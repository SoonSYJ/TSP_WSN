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

#ifndef __WITCOMMUNICATION_WIT_H
#define __WITCOMMUNICATION_WIT_H

#include <omnetpp.h>
#include <stdio.h>
#include <stdlib.h>
#include "messageTypes.h"
#include "messages_m.h"
#include "common.h"
namespace witcommunication {

/**
 * Implements the WIT simple module. See the NED file for more information.
 */
class WIT : public cSimpleModule
{
  public:
    adress_type getAdress();
    bool bIsIntendedToThisNode(cMessage *msg);
  protected:
    cOutVector simTimeVector;
    cOutVector witTimeVector;
    cOutVector differenceTimeVector;
    simtime_t currentTime;
    simtime_t last_t0_rx;
    simtime_t last_t0_tx;
    simtime_t last_t1_rx;
    simtime_t last_t1_tx;
    simtime_t last_t2_rx;
    simtime_t last_t2_tx;
    simtime_t last_t3_rx;
    simtime_t last_t3_tx;
    simtime_t currentTimeStamp;
    adress_type adress;
    adress_type client_adresses[MAXNBCHILDS];
    adress_type masterAdress;
    int child_count;
    double time_multiplier;
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    void sendSyncToAllChilds();
    void saveCurrentTime(simtime_t *x);
    void sendFollowUpToAllChilds();
    void manageDelayAndOffset();
    FILE *output;
};

}; // namespace

#endif
