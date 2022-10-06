#include "src/entities/AS.cpp"
#include "src/entities/Device.cpp"
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
    std::vector<Device> routerListAS1 = AS1.getRouters();

    /*
    for (int i = 0; i < routerListAS1.size(); i++) { 
        std::cout << routerListAS1[i].getName() << "\n";
    }*/
    
    AS2.createRouters(4, 7, 1);
    std::vector<Device> routerListAS2 = AS2.getRouters();

    /*
    for (int i = 0; i < routerListAS2.size(); i++) { 
        std::cout << routerListAS2[i].getName() << "\n";
    }*/

    Device sourceHost = Device(1, "H1");
    Device destinationHost = Device(2, "H2");

    /**
     * Configure connections
     * Example AS1:
     * H1 <-> R1 <-> R2 <-> R6e
     * H1 <-> R3 <-> R4 <-> R5 <-> R6e
     * 
     * TODO: [[H1_id, R1_id], ...] -> loop
     * TODO: routings vice versa
     */

    std::vector<Connection> connsAS1;
    int rows = 7;
    int cols = 2;

    int confAS1 [7][2] = {
        {sourceHost.getId(),routerListAS1[0].getId()}, 
        {routerListAS1[0].getId(),routerListAS1[1].getId()}, 
        {routerListAS1[1].getId(),routerListAS1[5].getId()},

        {sourceHost.getId(),routerListAS1[2].getId()},
        {routerListAS1[2].getId(),routerListAS1[3].getId()},
        {routerListAS1[3].getId(),routerListAS1[4].getId()},
        {routerListAS1[4].getId(),routerListAS1[5].getId()}
        };

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Connection conn = Connection(confAS1[i][j], confAS1[i][j+1], numberOfNetworks++);
            connsAS1.push_back(conn);
            //std::cout << j << "\n";
            break;
        }
        //std::cout << i << "\n";
    }

    /*
    Connection connAS1_H1_R1 = Connection(sourceHost.getId(), routerListAS1[0].getId(), numberOfNetworks++);
    Connection connAS1_R1_R2 = Connection(routerListAS1[0].getId(), routerListAS1[1].getId(), numberOfNetworks++);
    Connection connAS1_R2_R6e = Connection(routerListAS1[1].getId(), routerListAS1[5].getId(), numberOfNetworks++);

    Connection connAS1_H1_R3 = Connection(sourceHost.getId(), routerListAS1[2].getId(), numberOfNetworks++);
    Connection connAS1_R3_R4 = Connection(routerListAS1[2].getId(), routerListAS1[3].getId(), numberOfNetworks++);
    Connection connAS1_R4_R5 = Connection(routerListAS1[3].getId(), routerListAS1[4].getId(), numberOfNetworks++);
    Connection connAS1_R5_R6e = Connection(routerListAS1[4].getId(), routerListAS1[5].getId(), numberOfNetworks++);
    */

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
    std::vector<Connection> connsAS2;
    rows = 5;
    cols = 2;

    int confAS2 [5][2] = {
        {routerListAS2[0].getId(),routerListAS2[1].getId()}, 
        {routerListAS2[1].getId(),routerListAS2[2].getId()}, 
        {routerListAS2[2].getId(),destinationHost.getId()},

        {routerListAS2[0].getId(),routerListAS2[3].getId()},
        {routerListAS2[3].getId(),destinationHost.getId()},
        };

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Connection conn = Connection(confAS2[i][j], confAS2[i][j+1], numberOfNetworks++);
            connsAS2.push_back(conn);
            //std::cout << j << "\n";
            break;
        }
        //std::cout << i << "\n";
    }
    /*
    Connection connAS2_R7e_R8 = Connection(routerListAS2[0].getId(), routerListAS2[1].getId(), numberOfNetworks++);
    Connection connAS2_R8_R9 = Connection(routerListAS2[1].getId(), routerListAS2[2].getId(), numberOfNetworks++);
    Connection connAS2_R9_H2 = Connection(routerListAS2[2].getId(), destinationHost.getId(), numberOfNetworks++);

    Connection connAS2_R7e_R10 = Connection(routerListAS2[0].getId(), routerListAS2[3].getId(), numberOfNetworks++);
    Connection connAS2_R10_H2 = Connection(routerListAS2[3].getId(), destinationHost.getId(), numberOfNetworks++);
    */

    /**
     * Set connections to each device
     * 
     * TODO: automate the connection creation process
     */

    //source host
    std::vector<Connection> connections;
    //Connection connections [2] = {connsAS1[0], connsAS1[3]} //connAS1_H1_R1, connAS1_H1_R3
    connections.push_back(connsAS1[0]); 
    connections.push_back(connsAS1[3]); //connAS1_H1_R3
    sourceHost.setConnections(connections);
    connections.clear();

    //R1
    connections.push_back(connsAS1[1]);
    routerListAS1[0].setConnections(connections);
    connections.clear();

    //R2
    connections.push_back(connsAS1[2]);
    routerListAS1[1].setConnections(connections);
    connections.clear();

    //R3
    connections.push_back(connsAS1[3]);
    routerListAS1[2].setConnections(connections);
    connections.clear();

    //R4
    connections.push_back(connsAS1[4]);
    routerListAS1[3].setConnections(connections);
    connections.clear();

    //R5
    connections.push_back(connsAS1[5]);
    routerListAS1[4].setConnections(connections);
    connections.clear();
    
    //R6
    connections.push_back(conn_AS1_AS2);
    routerListAS1[5].setConnections(connections);
    connections.clear();

    //R7
    connections.push_back(connsAS2[0]);
    connections.push_back(connsAS2[3]);
    routerListAS2[0].setConnections(connections);
    connections.clear();

    //R8
    connections.push_back(connsAS2[1]);
    routerListAS2[1].setConnections(connections);
    connections.clear();

    //R9
    connections.push_back(connsAS2[2]);
    routerListAS2[2].setConnections(connections);
    connections.clear();

    //R10
    connections.push_back(connsAS2[4]);
    routerListAS2[3].setConnections(connections);
    connections.clear();
    

    /*Not yet implemented
    //destination host
    connections.push_back(connsAS2[2]); //connAS2_R9_H2
    connections.push_back(connsAS2[4]); //connAS2_R10_H2
    destinationHost.setConnections(connections);
    connections.clear();
    */


    /*
    int neighbour1 = connAS1_H1_R1.getDestinationEntityId();
    int neighbour2 = connAS1_H1_R3.getDestinationEntityId();
    std::vector<int> neighbours;
    neighbours.push_back(neighbour1);
    neighbours.push_back(neighbour2);

    sourceHost.setNeighbours(neighbours); //set neighbour connections?
    */

    /**
     * Establish a TCP connection
     */ 
    Packet synPacket = Packet();
    synPacket.createSYNPacket("SYN");

    sourceHost.sendPacket(synPacket); //everybody has to know its neighbours, connection get response
    std::cout << "Send successful? source " << sourceHost.getName() << " " << sourceHost.getSendSuccessful() << std::endl;
    if (sourceHost.getSendSuccessful()) {
        std::cout << "Send successful before? " << routerListAS1[0].getName() << " " << sourceHost.getSendSuccessful() << std::endl;
        routerListAS1[0].sendPacket(synPacket);
        for (int i = 1; i < routerListAS1.size(); i++) {
            if (routerListAS1[i-1].getSendSuccessful()) {
                std::cout << "Send successful? " << routerListAS1[i-1].getName() << " " << routerListAS1[i-1].getSendSuccessful() << std::endl;
                routerListAS1[i].sendPacket(synPacket);
            }
        }
        std::cout << "Send successful? " << routerListAS1[routerListAS1.size()-1].getName() << " " << routerListAS1[routerListAS1.size()-1].getSendSuccessful() << std::endl; 
    }

    if (routerListAS1[routerListAS1.size()-1].getSendSuccessful()) {
        std::cout << "Send successful before? " << routerListAS2[0].getName() << " " << routerListAS1[routerListAS1.size()-1].getSendSuccessful() << std::endl;
        routerListAS2[0].sendPacket(synPacket);
        for (int i = 1; i < routerListAS2.size(); i++) {
            if (routerListAS2[i-1].getSendSuccessful()) {
                std::cout << "Send successful? " << routerListAS2[i-1].getName() << " " << routerListAS2[i-1].getSendSuccessful() << std::endl;
                routerListAS2[i].sendPacket(synPacket);
            }
        }
        std::cout << "Send successful? " << routerListAS2[routerListAS2.size()-1].getName() << " " << routerListAS2[routerListAS2.size()-1].getSendSuccessful() << std::endl;
    }

    Packet packet = Packet(2500, 80, "Hello World!");

    //for testing
    std::cout << connsAS1[2].getIPAddress() << std::endl; //get H1 -> R1
    std::cout << connsAS2[2].getIPAddress() << std::endl; //get R1 -> R2
    std::cout << connsAS2[3].getDistance() << std::endl; //get H1 -> R1 distance
    std::cout << connsAS2[3].getHoldTime() << std::endl; //get H1 -> R1 hold time

}