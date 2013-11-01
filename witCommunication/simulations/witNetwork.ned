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

package witcommunication.simulations;

import witcommunication.WIT;
import witcommunication.Server;
import witcommunication.WirelessChannel;
//
// Two instances (tic and toc) of Txc connected.
//
network witNetwork
{
    parameters:
        int numberOfNodes = default(10);
        @display("bgb=673,410;bgl=2");
    submodules:
        wit[5]: WIT {
            @display("p=1000,152,m,10,10,10");
        }
        wit2: WIT {
            @display("p=230,143");
        }
        wit1: WIT {
            @display("p=128,143");
        }
        wit3: WIT {
            @display("p=350,136");
        }
        wit4: WIT {
            @display("p=41,249");
        }
        wit5: WIT {
            @display("p=100,249");
        }
        wit6: WIT {
            @display("p=152,249");
        }
        wit7: WIT {
            @display("p=218,249");
        }
        wit8: WIT {
            @display("p=269,249");
        }
        wit9: WIT {
            @display("p=350,249");
        }
        wit10: WIT {
            @display("p=409,249");
        }
        wit11: WIT {
            @display("p=350,359");
        }
        wit12: WIT {

            @display("p=409,359");
        }
        server: Server {
            @display("p=207,23");
        }
        wirelessChannel: WirelessChannel {
            @display("p=1000,1000");
            gates:
                toNode[numberOfNodes+1];
                fromNode[numberOfNodes+1];
        }
    connections:
        server.toWirelessChannel --> { @display("ls=red,0"); } --> wirelessChannel.fromNode[numberOfNodes];
        server.fromWirelessChannel <-- { @display("ls=red,0"); } <-- wirelessChannel.toNode[numberOfNodes];
        //   for i=0..numberOfNodes -1 {
        //      wit[i].toWirelessChannel --> { @display("ls=red,0"); } --> wirelessChannel.fromNode[i];
        //     wit[i].fromWirelessChannel <-- { @display("ls=red,0"); } <-- wirelessChannel.toNode[i];
        //}
        wit2.master++ --> server.slave++;
        wit4.master++ --> wit1.slave++;
        wit5.master++ --> wit1.slave++;
        wit6.master++ --> wit1.slave++;
        wit7.master++ --> wit2.slave++;
        wit8.master++ --> wit2.slave++;
        wit9.master++ --> wit3.slave++;
        wit10.master++ --> wit3.slave++;
        wit11.master++ --> wit9.slave++;
        wit12.master++ --> wit9.slave++;
        wit3.master++ --> server.slave++;
        wit1.master++ --> server.slave++;
}
