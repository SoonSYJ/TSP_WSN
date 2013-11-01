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

#include "Server.h"

namespace witcommunication {

Define_Module(Server);

adress_type Server::getAdress()
{
    return adress;
}
void Server::sendMessageToAllChilds()
{
   int i;
   ImYourMaster *msg;
   for (i=0;i<child_count;i++)
   {
       msg = new ImYourMaster("ss",MASTER);
       msg -> setDestinationNodeID(i);
       send(msg,"toWirelessChannel");
   }
}
bool Server::bIsIntendedToThisNode(cMessage *msg)
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
           break;
       case SCHEDULE_SYNC:
           sendMessageToAllChilds();
       break;
       default:
       // just send back the message
       send(msg,"toWirelessChannel");
       break;
    }
    return false;
}

void Server::initialize()
{
    child_count=0;
   // scheduleAt(5000,new cMessage("ss",SCHEDULE));
    adress.adress= par("adress").longValue();
}

void Server::handleMessage(cMessage *msg)
{
    ImYourSlave *incoming;
    ImYourMaster *response;
    if (bIsIntendedToThisNode(msg))
    {
    int kind=msg->getKind();
    switch (kind){
            case SLAVE:
                incoming=check_and_cast <ImYourSlave*>(msg);
                int slaveID;
                slaveID=incoming->getSrcNodeID();
                client_adresses[child_count++].adress=slaveID;
                response= new ImYourMaster("master",MASTER);
                response->setDestinationNodeID(slaveID);
                send((cMessage*)response, "toWirelessChannel");
                break;
            case UNICAST:
                break;
            case BROADCAST:
                break;
            case MASTER:
                break;
            case SCHEDULE_SYNC:
                sendMessageToAllChilds();
                break;
            default:
                // just send back the message
                send(msg,"toWirelessChannel");
                break;
            }
    }
    else
    {
        //Ignore message. The destination of the message is another WIT
    }
}

}; // namespace
