#include "src/entities/AS.cpp"
#include "src/entities/Host.cpp"
#include "src/Connection.cpp"

#include <iostream>
#include <vector>

/**
 * 1. Create Autonomous Systems
 * 2. Create routers
 * 3. Create source host
 * 4. Create destination host
 * 5. Create connection between the source host and its home router
 * 
 */

int main() {
    
    AS AS1 = AS("AS1");
    AS AS2 = AS("AS2");

    AS1.createRouters(6, 1); //create routers
    std::vector<Router> routerListAS1 = AS1.getRouters();

    AS2.createRouters(4, 7);
    std::vector<Router> routerListAS2 = AS2.getRouters();

    Host sourceHost = Host("H1","R1");
    Host destinationHost = Host("H2", "R10");

    Connection conn = Connection(sourceHost, routerListAS1[1], destinationHost);
    std::cout << conn.getNextHop().getName() << std::endl;
    

    //for testing
    for (int i = 0; i < routerListAS1.size(); i++) {
        std::cout << routerListAS1[i].getName() << std::endl;

        std::vector<std::string> neighbours = routerListAS1[i].getNeighbours();
        for (int j = 0; j < neighbours.size(); j++) {
            std::cout << neighbours[j] << std::endl;
        }
    }

    for (int i = 0; i < routerListAS2.size(); i++) {
        std::cout << routerListAS2[i].getName() << std::endl;

        std::vector<std::string> neighbours = routerListAS2[i].getNeighbours();
        for (int j = 0; j < neighbours.size(); j++) {
            std::cout << neighbours[j] << std::endl;
        }
    }
}