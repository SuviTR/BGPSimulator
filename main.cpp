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
 * 6. Add neighbor connections
 */

int main() {
    
    /**
     * 1. Create Autonomous Systems
     */
    AS AS1 = AS("AS1");
    AS AS2 = AS("AS2");

    /**
     * - Number of routers in an AS
     * - Number of networks in total
     */
    int routersInAS1 = 6;
    int routersInAS2 = 4;
    int numberOfNetworks = 0;

    /**
     * 2. Create routers
     * 
     * 1.param: number of routers
     * 2.param: the starting number of the IP addresses in the AS
     * 3.param: edge router connecting two ASes
     * 
     * Add created routers to the router list
     */
    AS1.createRouters(6, 1, 6); //create routers
    std::vector<Device> routerListAS1 = AS1.getRouters();
    
    AS2.createRouters(4, 7, 1);
    std::vector<Device> routerListAS2 = AS2.getRouters();

    /**
     * 3. Create source host
     * 4. Create destination host
     * 
     * 1.param: id
     * 2.param: name
     */
    Device sourceHost = Device(1, "H1");
    Device destinationHost = Device(2, "H2");

    /**
     * Configure connections
     * Example AS1:
     * H1 -> R1 -> R2 -> R6e
     * H1 -> R3 -> R4 -> R5 -> R6e
     * 
     * TODO: routings the other way round
     * H1 <-> R1 <-> R2 <-> R6e
     * H1 <-> R3 <-> R4 <-> R5 <-> R6e
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

    std::string confAS1_names [7][2] = {
        {sourceHost.getName(),routerListAS1[0].getName()}, 
        {routerListAS1[0].getName(),routerListAS1[1].getName()}, 
        {routerListAS1[1].getName(),routerListAS1[5].getName()},

        {sourceHost.getName(),routerListAS1[2].getName()},
        {routerListAS1[2].getName(),routerListAS1[3].getName()},
        {routerListAS1[3].getName(),routerListAS1[4].getName()},
        {routerListAS1[4].getName(),routerListAS1[5].getName()}
        };

    /**
     * Add created connections to the connection list of AS1
     * 
     * connsAS1 = [
     * connAS1_H1_R1,
     * connAS1_R1_R2,
     * connAS1_R2_R6e,
     * connAS1_H1_R3,
     * connAS1_R3_R4,
     * connAS1_R4_R5,
     * connAS1_R5_R6e
     * ]
     */    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Connection conn = Connection(confAS1[i][j], confAS1[i][j+1], "connAS1", confAS1_names[i][j], confAS1_names[i][j+1], numberOfNetworks++);
            connsAS1.push_back(conn);

            /*
            //add neighbor connections
            for (int k = 0; k < routerListAS1.size(); k++) {
                std::cout << "KK " << k << std::endl;
                if (k != 0) { //EI TOIMI!!!
                    if (routerListAS1[k].getId() == confAS1[i][j]) {
                        std::vector<Connection> connections;
                        connections.push_back(conn);
                        routerListAS1[k].setConnections(connections);
                    } 
                } else {
                    
                    //std::vector<Connection> connections;
                    //connections.push_back(connsAS1[0]); 
                    //connections.push_back(connsAS1[3]); //connAS1_H1_R3
                    //sourceHost.setConnections(connections);
                }
            }*/

            break;
        }
    }
    /*
    std::cout << "AS1 0 " << connsAS1[0].getName() << std::endl;
    std::cout << "AS1 1 " << connsAS1[1].getName() << std::endl;
    std::cout << "AS1 2 " << connsAS1[2].getName() << std::endl;
    std::cout << "AS1 3 " << connsAS1[3].getName() << std::endl;
    std::cout << "AS1 4 " << connsAS1[4].getName() << std::endl;
    std::cout << "AS1 5 " << connsAS1[5].getName() << std::endl;
    std::cout << "AS1 6 " << connsAS1[6].getName() << std::endl;
    std::cout << " " << std::endl;
    */

    /**
     * Configure the connection between AS1 and AS2
     * Example AS1 -> AS2
     */
    Connection conn_AS1_AS2 = Connection(routerListAS1[5].getId(), routerListAS2[0].getId(), "connAS1_AS2", routerListAS1[5].getName(), routerListAS2[0].getName(), numberOfNetworks++);

    /**
     * Configure connections
     * Example AS2:
     * R7e -> R8 -> R9 -> H2
     * R7e -> R10 -> H2
     * 
     * TODO: routings the other way round
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

    std::string confAS2_names [5][2] = {
        {routerListAS2[0].getName(),routerListAS2[1].getName()}, 
        {routerListAS2[1].getName(),routerListAS2[2].getName()}, 
        {routerListAS2[2].getName(),destinationHost.getName()},

        {routerListAS2[0].getName(),routerListAS2[3].getName()},
        {routerListAS2[3].getName(),destinationHost.getName()},
        };

     /**
     * Add created connections to the connection list of AS2
     * 
     * connsAS2 = [
     * connAS2_R7e_R8,
     * connAS2_R8_R9,
     * connAS2_R9_H2,
     * connAS2_R7e_R10,
     * connAS2_R10_H2,
     * ]
     */  
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Connection conn = Connection(confAS2[i][j], confAS2[i][j+1], "connAS2", confAS2_names[i][j], confAS2_names[i][j+1], numberOfNetworks++);
            connsAS2.push_back(conn);
            break;
        }
    }
    /*
    std::cout << "AS2 0 " << connsAS2[0].getName() << std::endl;
    std::cout << "AS2 1 " << connsAS2[1].getName() << std::endl;
    std::cout << "AS2 2 " << connsAS2[2].getName() << std::endl;
    std::cout << "AS2 3 " << connsAS2[3].getName() << std::endl;
    std::cout << "AS2 4 " << connsAS2[4].getName() << std::endl;
    */

    /**
     * Set neighbour connections to each device
     * 
     * TODO: automate the connection creation process
     */
    std::vector<Connection> connections;

    //source host
    connections.push_back(connsAS1[0]); 
    connections.push_back(connsAS1[3]);
    sourceHost.setConnections(connections);
    connections.clear();

    //R1 -> R2
    connections.push_back(connsAS1[1]);
    routerListAS1[0].setConnections(connections);
    connections.clear();

    //R2 -> R6e
    connections.push_back(connsAS1[2]);
    routerListAS1[1].setConnections(connections);
    connections.clear();

    //R3 -> R4
    connections.push_back(connsAS1[4]);
    routerListAS1[2].setConnections(connections);
    connections.clear();

    //R4 -> R5
    connections.push_back(connsAS1[5]);
    routerListAS1[3].setConnections(connections);
    connections.clear();

    //R5 -> R6e
    connections.push_back(connsAS1[6]);
    routerListAS1[4].setConnections(connections);
    connections.clear();
    
    //R6e -> R7e
    connections.push_back(conn_AS1_AS2);
    routerListAS1[5].setConnections(connections);
    connections.clear();

    //R7 -> R8 / R10
    connections.push_back(connsAS2[1]);
    connections.push_back(connsAS2[3]);
    routerListAS2[0].setConnections(connections);
    connections.clear();

    //R8 -> R9
    connections.push_back(connsAS2[1]);
    routerListAS2[1].setConnections(connections);
    connections.clear();

    //R9 -> H2
    connections.push_back(connsAS2[2]);
    routerListAS2[2].setConnections(connections);
    connections.clear();

    //R10 -> H2
    connections.push_back(connsAS2[4]);
    routerListAS2[3].setConnections(connections);
    connections.clear();

    std::vector<Device> deviceList = routerListAS1;
    deviceList.insert(deviceList.end(), routerListAS2.begin(), routerListAS2.end());
    
    deviceList.insert(deviceList.begin(), sourceHost);
    deviceList.insert(deviceList.end(), destinationHost);

    /**
     * Establish a TCP connection
     */

    /**
     * Create a SYN packet
     */ 
    Packet synPacket = Packet();
    synPacket.createSYNPacket("SYN");

    /**
     * Send a packet from AS1 to AS2.
     * 
     * If the receiving entity/entities respond, the fastest response is chosen, 
     * and the packet is delivered successfully.
     * 
     * Otherwise, the connection is down and the transmission is terminated.
     */ 
    int i = 0;
    do {
        std::cout << "Current network " << deviceList[i].getName() << std::endl;
        deviceList[i].sendPacket(synPacket);

        if (deviceList[i].getSendSuccessful()) {

            //get the index of the next hop
            int index = deviceList[i].getNextHopIndex(deviceList, deviceList[i].getNextHop());
            if (index != -1) {
                i = index - 1;
            }
        }
        i++;
    } while (i < 12);

    if (deviceList[deviceList.size()-2].getSendSuccessful()) {
        std::string nextHop = deviceList[deviceList.size()-1].getNextHop();

        deviceList[deviceList.size()-1].sendPacket(synPacket);
    }

    /**
     * Create a data packet
     */ 
    Packet packet = Packet(2500, 80, "Hello World!");

}