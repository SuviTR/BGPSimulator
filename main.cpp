#include <vector>
#include "helpers/Log.cpp"
#include "src/entities/AS.cpp"
#include "src/entities/Host.cpp"
#include "src/Connection.cpp"

/**
 * 1. Create Anonymous System
 * 2. Create routers
 * 3. Create sourceHost
 * 4. Create destinationHost
 * 5. Create connection between the sourceHost and its homeRouter
 * 
 */

int main() {
    
    AS AS1 = AS("AS1"); //create AS

    AS1.createRouters(6); //create routers, TODO names, ip addresses
    std::vector<Router> routerList = AS1.getRouters();

    Host sourceHost = Host("H1","R1");
    Host destinationHost = Host("H2", "R10");

    Connection conn = Connection(sourceHost, routerList[1], destinationHost);
    std::cout << conn.getNextHop().getName() << std::endl;
    

    for (int i = 0; i < routerList.size(); i++) {
        std::cout << routerList[i].getName() << std::endl;

        std::vector<std::string> neighbours = routerList[i].getNeighbours();
        for (int j = 0; j < neighbours.size(); j++) {
            std::cout << neighbours[j] << std::endl;
        }
    }
}