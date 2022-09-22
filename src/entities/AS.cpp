#include "Router.cpp"

#include <string>
#include <vector>

class AS {
  private:
    std::string name;
    int numberOfRouters;
    std::vector<Router> routerList;
    int numberOfNetworks;

  public:
    AS(std::string _name) { // Constructor with parameters
        name = _name;
        numberOfNetworks = 1;
    }

    void createRouters(int _numberOfRouters) {
        numberOfRouters = _numberOfRouters;
        
        for (int i = 1; i <= numberOfRouters; i++) {
            std::vector<std::string> ipAddresses = generateIPAddresses(i);

            std::string name = "R" + std::to_string(i);
            Router router = Router(name, ipAddresses);
            routerList.push_back(router);
        }
    }

    /**
     * 3 routers:
     * 11.22.0.1 R1 towards R2
     * 11.33.0.2 R1 towards R3
     */
    std::vector<std::string> generateIPAddresses(int i) {
        std::vector<std::string> ipAddresses;
        int init = i;
        std::string ipAddress = "";

        std::string initToString = std::to_string(init); //1

        std::string first = initToString + initToString; //11
        
        for (int i = 1; i <= numberOfRouters; i++) {
            if (i != init) {
                initToString = std::to_string(i); //2
                std::string second = initToString + initToString; //22
                std::string third = "0";
                std::string fourth = std::to_string(numberOfNetworks); //1
                
                ipAddress = first + "." + second + "." + third + "." + fourth; //11.22.0.1
                ipAddresses.push_back(ipAddress);

                numberOfNetworks++;
                ipAddress = "";
            }
        }
        return ipAddresses;
    }

    std::vector<Router> getRouters() {
        return routerList;
    }

};