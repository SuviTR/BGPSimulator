#include "src/entities/AS.cpp"
#include "src/entities/Host.cpp"
#include "src/Packet.cpp"
#include "src/Connection.cpp"

#include <iostream>
#include <vector>

/**
 * 1. Create Autonomous Systems
 * 2. Create routers
 * 3. Create source host
 * 4. Create destination host
 * 5. Create connections between entities
 * 
 */

int main() {
    
    AS AS1 = AS("AS1");
    AS AS2 = AS("AS2");

    int routersInAS1 = 6;
    int routersInAS2 = 4;
    int numberOfNetworks = 0;

    AS1.createRouters(6, 1, 6); //create routers
    std::vector<Router> routerListAS1 = AS1.getRouters();

    AS2.createRouters(4, 7, 4);
    std::vector<Router> routerListAS2 = AS2.getRouters();

    Host sourceHost = Host(1, "H1");
    Host destinationHost = Host(2, "H2");

    /**
     * Configure connections
     * Example AS1:
     * H1 <-> R1 <-> R2 <-> R6e
     * H1 <-> R3 <-> R4 <-> R5 <-> R6e
     * 
     * TODO [[H1_id, R1_id], ...] -> loop
     */
    
    Connection connAS1_H1_R1 = Connection(sourceHost.getId(), routerListAS1[0].getId(), numberOfNetworks++);
    Connection connAS1_R1_R2 = Connection(routerListAS1[0].getId(), routerListAS1[1].getId(), numberOfNetworks++);
    Connection connAS1_R2_R6e = Connection(routerListAS1[1].getId(), routerListAS1[5].getId(), numberOfNetworks++);

    Connection connAS1_H1_R3 = Connection(sourceHost.getId(), routerListAS1[2].getId(), numberOfNetworks++);
    Connection connAS1_R3_R4 = Connection(routerListAS1[2].getId(), routerListAS1[3].getId(), numberOfNetworks++);
    Connection connAS1_R4_R5 = Connection(routerListAS1[3].getId(), routerListAS1[4].getId(), numberOfNetworks++);
    Connection connAS1_R5_R6e = Connection(routerListAS1[4].getId(), routerListAS1[5].getId(), numberOfNetworks++);

    /**
     * Configure connections
     * Example AS1 -> AS2
     */
    Connection conn_AS1_AS2 = Connection(routerListAS1[5].getId(), routerListAS2[0].getId(), numberOfNetworks++);

    /**
     * Configure connections
     * Example AS2:
     * R7e <-> R8 <-> R9 <-> H2
     * R7e <-> R10 <-> H2
     */
    Connection connAS2_R7e_R8 = Connection(routerListAS2[0].getId(), routerListAS2[1].getId(), numberOfNetworks++);
    Connection connAS2_R8_R9 = Connection(routerListAS2[1].getId(), routerListAS2[2].getId(), numberOfNetworks++);
    Connection connAS2_R9_H2 = Connection(routerListAS1[2].getId(), destinationHost.getId(), numberOfNetworks++);

    Connection connAS2_R7e_R10 = Connection(routerListAS2[0].getId(), routerListAS2[3].getId(), numberOfNetworks++);
    Connection connAS2_R10_H2 = Connection(routerListAS1[3].getId(), destinationHost.getId(), numberOfNetworks++);


    /**
     * Establish a TCP connection
     */ 
    Packet synPacket = Packet();
    synPacket.setSYNFlags(0,0,0,0,0,0,1,0);

    sourceHost.sendPacket(synPacket);


    Packet packet = Packet(2500, 80, "Hello World!");

    //for testing
    std::cout << connAS1_H1_R1.getIPAddress() << std::endl; //get H1 -> R1
    std::cout << connAS1_R1_R2.getIPAddress() << std::endl; //get R1 -> R2
    std::cout << connAS1_H1_R1.getDistance() << std::endl; //get H1 -> R1 distance
    std::cout << connAS1_H1_R1.getHoldTime() << std::endl; //get H1 -> R1 hold time

}