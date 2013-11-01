#include "WirelessChannel.h"
#include <string.h>
namespace witcommunication {

Define_Module(WirelessChannel);
int WirelessChannel::calculateDelay(int x, int y)
{
    double retVal;
    retVal = (xCoordinates[x] - xCoordinates[y])* (xCoordinates[x] - xCoordinates[y]);
    retVal+= (yCoordinates[x] - yCoordinates[y])* (yCoordinates[x] - yCoordinates[y]);
    retVal = (sqrt(retVal*1.0)+1) * delay;
    if((x==3 )||( y ==3))

    //EV<<retVal<<" asd\n";
    return (int)retVal;
}
void WirelessChannel::updatePosition(int nodeIndex)
{
    int directionX[4] = {-1,1,0,0};
    int directionY[4] = {0,0,-1,1};
    int x =random()%4;
    xCoordinates[nodeIndex] += directionX[x];
    yCoordinates[nodeIndex] += directionY[x];
    //EV<<x<<" before, node "<<nodeIndex<<" new position: X: "<<xCoordinates[nodeIndex]<<"Y: "<<yCoordinates[nodeIndex]<<"\n";

    if (xCoordinates[nodeIndex]>MAP_X_SIZE)
        xCoordinates[nodeIndex] = MAP_X_SIZE;

    if (yCoordinates[nodeIndex]>MAP_Y_SIZE)
        yCoordinates[nodeIndex] = MAP_Y_SIZE;

    if (xCoordinates[nodeIndex]<0)
        xCoordinates[nodeIndex] = 0;
    if (yCoordinates[nodeIndex]<0)
        yCoordinates[nodeIndex] = 0;
    //EV<<x<<"node "<<nodeIndex<<" new position: X: "<<xCoordinates[nodeIndex]<<"Y: "<<yCoordinates[nodeIndex]<<"\n";
}
void WirelessChannel::initialize()
{

    int i;
    simDelay.setName("delay");
    numNodes=par("numNodes").longValue();
    for (i=0;i< numNodes; i++)
    {
        xCoordinates[i] = 0;
        yCoordinates[i] = 0;
    }

    scheduleAt(simTime()+LOCATION_CHANGE_PERIOD,new cMessage("update position",POSITION_UPDATE));
    delay=par("delay").longValue();
    event = new cMessage("event",SCHEDULE_SYNC);


}

void WirelessChannel::handleMessage(cMessage *msg)
{
    int kind=msg->getKind();
    int i;
    cMessage *copy;
    switch (kind){
    case SCHEDULE_DELAY:

        break;
    case POSITION_UPDATE:
        for(i=0;i<numNodes;i++)
        {
            updatePosition(i);
        }
        scheduleAt(simTime()+LOCATION_CHANGE_PERIOD,new cMessage("update position",POSITION_UPDATE));
        break;
    default:

        int j = 0;
        while(msg->arrivedOn("fromNode",j) == 0) j++;
        int delayCalc;
        for(i=0; i<numNodes;i++)
        {
            copy=msg->dup();
            delay=par("delay").longValue();
            simDelay.record(delay);
            delayCalc = calculateDelay(j,i);

           // EV<<delayCalc<<"\n";
           // EV<<"node "<<i<<" new position: X: "<<xCoordinates[i]<<"Y: "<<yCoordinates[i]<<"\n";
            sendDelayed(copy, delayCalc,"toNode",i);
        }


      //  scheduleAt(simTime()+delay,new cMessage(,SCHEDULE_DELAY));
        break;


    }

}

}; // namespace
