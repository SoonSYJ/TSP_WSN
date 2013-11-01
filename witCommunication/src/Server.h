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
#include "messages_m.h"
#include "messageTypes.h"
#include "common.h"

namespace witcommunication {

/**
 * Implements the Server simple module. See the NED file for more information.
 */
class Server : public cSimpleModule
{
  public:
    adress_type getAdress();
  protected:
    adress_type adress;
    adress_type client_adresses[MAXNBCHILDS];
    int child_count;
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
  private:
    void sendMessageToAllChilds();
    bool bIsIntendedToThisNode(cMessage *msg);
};

}; // namespace

#endif
