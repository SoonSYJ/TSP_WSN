#ifndef __WITCOMMUNICATION_WIRELESSCHANNEL_H
#define __WITCOMMUNICATION_WIRELESSCHANNEL_H

#include <omnetpp.h>
#include "messageTypes.h"
#include "messages_m.h"
#include "common.h"

namespace witcommunication {

/**
 * Implements the WIT simple module. See the NED file for more information.
 */
class WirelessChannel : public cSimpleModule
{
  private:
    cOutVector simDelay;
    int xCoordinates[MAXNBCHILDS];
    int yCoordinates[MAXNBCHILDS];
    int delay;
    int numNodes;

    int positions[MAXNBNODES][NBDIRECTIONS];
    cMessage *event;
    cMessage *witMsg;
  protected:
    virtual void initialize();
    void updatePosition(int nodeIndex);
    int calculateDelay(int x, int y);
    virtual void handleMessage(cMessage *msg);
};

}; // namespace

#endif
