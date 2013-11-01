//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "WIT.h"

namespace witcommunication {

Define_Module(WIT);
void WIT::manageDelayAndOffset()
{
    simtime_t A;
    simtime_t B;
    A = last_t1_rx - last_t0_rx;
    B = last_t3_rx - last_t2_rx;
    simtime_t delay;
    simtime_t offset;
    delay = (A+B)/2;
    offset = (A-B)/2;
    // char* buf;
    // buf =(char*) malloc(100*sizeof(char));
    //fprintf(output,"simulation time: %s, current time: %s, delay %s, offset %s\n", simTime().str(buf),currentTime.str(buf),delay.str(buf),offset.str(buf));
    EV <<"current time:"<< currentTime<<"delay:"<< delay <<"offset:"<< offset<<"\n";
    currentTime-=offset;
    EV<<"new time: "<<currentTime;
    simTimeVector.record(currentTime);
    witTimeVector.record(simTime());
    recordScalar("value",simTime(),"double");
    differenceTimeVector.record(currentTime-simTime()>=0?currentTime-simTime():simTime()-currentTime);
}
adress_type WIT::getAdress()
{
    return adress;
}
void WIT::saveCurrentTime(simtime_t *x)
{
    (*x)= currentTime;
}
void WIT::sendSyncToAllChilds()
{
    int index;
    for(index = 0;index<child_count;index++)
    {
        SyncMsg *syncMsg;
        syncMsg = new SyncMsg("messageToChild", SYNC);
        syncMsg->setSrcNodeID(adress.adress);
        syncMsg->setDestinationNodeID(client_adresses[index].adress);
        send((cMessage*)syncMsg, "toWirelessChannel");
        //EV<<"Sent sync from"<<adress.adress<<"to"<<client_adresses[index].adress;
    }
}
void WIT::sendFollowUpToAllChilds()
{
    int index;
    for(index = 0;index<child_count;index++)
    {
        FollowUp *syncMsg;
        syncMsg = new FollowUp("messageToChild", FOLLOW_UP);
        syncMsg->setSrcNodeID(adress.adress);
        syncMsg->setDestinationNodeID(client_adresses[index].adress);
        syncMsg->setTimeMoment(last_t0_tx);
        send((cMessage*)syncMsg, "toWirelessChannel");
        //EV<<"Sent sync from"<<adress.adress<<"to"<<client_adresses[index].adress;
    }
}
void WIT::initialize()
{
    /*if (par("sendInitialMessage").boolValue())
    {
        cMessage *msg = new cMessage("tictocMsg",BROADCAST);
        send(msg, "toWirelessChannel");
    }*/
    simTimeVector.setName("simTime");
    witTimeVector.setName("witTime");
    differenceTimeVector.setName("difference");
    child_count=0;
    masterAdress.adress = 0;
    adress.adress= par("adress").longValue();
    time_multiplier = par("time_multiplier").doubleValue();
    currentTime = 0;
    currentTimeStamp = simTime();
    ImYourSlave *msg = new ImYourSlave("slave", SLAVE);
    msg->setSrcNodeID(adress.adress);
    if (adress.adress<4)
    msg->setDestinationNodeID(1);
    else
        if (adress.adress<7)
        msg->setDestinationNodeID(3);
        else
            msg->setDestinationNodeID(6);
    send(msg, "toWirelessChannel");
    cMessage *selfMsg = new cMessage("schedule",SCHEDULE_SYNC);
    scheduleAt(5000,selfMsg);
    output = fopen("out.txt","w");
    if (output == NULL)
    {
        EV<<"Error creating output";
        exit(1);
    }

}
bool WIT::bIsIntendedToThisNode(cMessage *msg)
{
    int kind=msg->getKind();
    switch (kind){
    case SLAVE:
        ImYourSlave *incoming;
        incoming = check_and_cast <ImYourSlave*>(msg);
        int ID;
        ID=incoming->getDestinationNodeID();
        if (ID == getAdress().adress)
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    case UNICAST:
        break;
    case BROADCAST:
        return true;
        break;
    case MASTER:
        ImYourMaster *incomingMaster;
        incomingMaster = check_and_cast <ImYourMaster*>(msg);
        int destID;
        destID=incomingMaster->getDestinationNodeID();
        if (destID == getAdress().adress)
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    case SYNC:
        SyncMsg *incomingSync;
        incomingSync = check_and_cast <SyncMsg*>(msg);
        int destIDSync;
        destIDSync=incomingSync->getDestinationNodeID();
        if (destIDSync == getAdress().adress)
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    case FOLLOW_UP:
        FollowUp *incomingFollow;
        incomingFollow = check_and_cast <FollowUp*>(msg);
        int destIDFollow;
        destIDFollow=incomingFollow->getDestinationNodeID();
        if (destIDFollow == getAdress().adress)
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    case DELAY_REQ:
        DelayReq *incomingDelay;
        incomingDelay = check_and_cast <DelayReq*>(msg);
        int destIDDelay;
        destIDDelay=incomingDelay->getDestinationNodeID();
        if (destIDDelay == getAdress().adress)
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    case DELAY_RESP:
        DelayResp *incomingDelayResp;
        incomingDelayResp = check_and_cast <DelayResp*>(msg);
        int destIDDelayResp;
        destIDDelayResp=incomingDelayResp->getDestinationNodeID();
        if (destIDDelayResp == getAdress().adress)
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    case SCHEDULE_SYNC:
        return true;
        break;
    case SCHEDULE_FOLLOW_UP:
        return true;
        break;
    case SCHEDULE_DELAY_REQ:
        return true;
        break;
    default:
        // just send back the message
        break;
    }
    return false;
}
void WIT::handleMessage(cMessage *msg)
{

    currentTime += (simTime()-currentTimeStamp )*time_multiplier;

    currentTimeStamp = simTime();
    if (bIsIntendedToThisNode(msg))
    {
        int kind=msg->getKind();
        switch (kind){
        case SLAVE:
            ImYourSlave *slaveIncoming;
            ImYourMaster *slaveResponse;
            slaveIncoming=check_and_cast <ImYourSlave*>(msg);
            int slaveID;
            slaveID=slaveIncoming->getSrcNodeID();
            client_adresses[child_count++].adress=slaveID;
            slaveResponse= new ImYourMaster("master",MASTER);
            slaveResponse->setSrcNodeID(adress.adress);
            slaveResponse->setDestinationNodeID(slaveID);
            send((cMessage*)slaveResponse, "toWirelessChannel");
            break;
        case UNICAST:
            break;
        case BROADCAST:
            break;
        case MASTER:
            ImYourMaster *masterIn;
            masterIn=check_and_cast <ImYourMaster*>(msg);
            int masterID;
            masterID = masterIn->getSrcNodeID();
            masterAdress.adress=masterID;
            char* buf;
            buf =(char*) malloc(100*sizeof(char));
            fprintf(output,"Node: %d - My master is %d - at MY time: %s\n",adress.adress,masterAdress.adress, currentTime.str(buf));
            EV << "Node:" << adress.adress << " - My master is "<<masterAdress.adress <<" - at MY time: "<<currentTime;
            // simsignal_t mstSig;
            //mstSig = registerSignal("masterID");
            // cIListener *listener = new cIListener();
            //  subscribe("masterID", listener);

            //  emit(mstSig,masterAdress.adress);
            break;
        case SYNC:
            saveCurrentTime(&last_t1_rx);
            ///    EV<<"t1 received by "<<adress.adress<<" is "<<last_t1_rx;
            //    EV<<"got it";
            break;
        case FOLLOW_UP:
            FollowUp *followIncoming;
            followIncoming=check_and_cast <FollowUp*>(msg);
            last_t0_rx = followIncoming->getTimeMoment();
            //  EV<<"to received by "<<adress.adress<<" is "<<last_t0_rx;
            cMessage *selfM;
            selfM = new cMessage("schedule delay request",SCHEDULE_DELAY_REQ);
            scheduleAt(simTime()+FOLLOW_UP_DELAY_REQ_DIFF,selfM);
            //    EV<<"got it AGAIN";
            break;
        case DELAY_REQ:
            saveCurrentTime(&last_t3_tx);
            // EV<<"t3 sent by "<<adress.adress<<" is "<<last_t3_tx;
            DelayResp *delayResponse;
            DelayReq *incomingDelay;
            incomingDelay = check_and_cast <DelayReq*>(msg);
            int sourceIDDelay;
            sourceIDDelay=incomingDelay->getSrcNodeID();
            delayResponse= new DelayResp("delay response",DELAY_RESP);
            delayResponse->setSrcNodeID(adress.adress);
            delayResponse->setDestinationNodeID(sourceIDDelay);
            delayResponse->setTimeMoment(last_t3_tx);
            send((cMessage*)delayResponse, "toWirelessChannel");
            break;
        case DELAY_RESP:
            DelayResp *delayResponseIn;
            delayResponseIn = check_and_cast <DelayResp*>(msg);
            last_t3_rx = delayResponseIn->getTimeMoment();
            // EV<<"t3 received by "<<adress.adress<<" is "<<last_t3_rx;
            manageDelayAndOffset();
            break;
        case SCHEDULE_SYNC:
            saveCurrentTime(&last_t0_tx);
            //   EV<<"to sent  from "<<adress.adress<<" is "<<last_t0_tx;
            sendSyncToAllChilds();
            cMessage *selfMesg;
            selfMesg = new cMessage("schedule follow up",SCHEDULE_FOLLOW_UP);
            scheduleAt(simTime()+SYNC_FOLLOW_UP_DIFF,selfMesg);
            cMessage *selfMsg2;
            selfMsg2 = new cMessage("schedule sync",SCHEDULE_SYNC);
            scheduleAt(simTime()+SYNC_PERIOD,selfMsg2);
            break;
        case SCHEDULE_FOLLOW_UP:
            sendFollowUpToAllChilds();

            break;
        case SCHEDULE_DELAY_REQ:
            DelayReq *delayReq;
            saveCurrentTime(&last_t2_rx);
            //   EV<<"t2 received by "<<adress.adress<<" is "<<last_t2_rx;
            delayReq= new DelayReq("delay request",DELAY_REQ);
            delayReq->setSrcNodeID(adress.adress);
            delayReq->setDestinationNodeID(masterAdress.adress);
            send((cMessage*)delayReq, "toWirelessChannel");

            break;
        default:
            // just send back the message
            //send(msg,"toWirelessChannel");
            EV<< "Invalid message";
            break;
        }
    }
    else
    {
        //Ignore message. The destination of the message is another WIT
    }
    // just send back the message
    // send(msg, "toWirelessChannel");
}

}; // namespace
