#include "Router.cpp"

#include <iostream>
#include <string>
#include <vector>

class AS {
  private:
    std::string name;
    int numberOfRouters;
    std::vector<Router> routerList;
    int numberOfNetworks;
    int ipPrefix;
    int maxIPAddress;

  public:
    AS(std::string _name) { // Constructor with parameters
        name = _name;
        numberOfNetworks = 1;
    }

    void createRouters(int _numberOfRouters, int _ipPrefix) { //6, 1
        numberOfRouters = _numberOfRouters;
        ipPrefix = _ipPrefix;
        maxIPAddress = numberOfRouters+ipPrefix;
        
        for (int i = 1; i <= numberOfRouters; i++) {
            std::vector<std::string> ipAddresses = generateIPAddresses(_ipPrefix);

            std::string name = "R" + std::to_string(_ipPrefix);
            Router router = Router(name, ipAddresses);
            routerList.push_back(router);
            _ipPrefix++;
        }
    }

    /**
     * 3 routers:
     * 11.22.0.1 R1 towards R2
     * 11.33.0.2 R1 towards R3
     */
    std::vector<std::string> generateIPAddresses(int _ipPrefix) {
        std::vector<std::string> ipAddresses;
        int init = _ipPrefix;
        std::string ipAddress = "";

        std::string initToString = std::to_string(init); //1
        std::string first = initToString + initToString; //11
        if (initToString.length() > 1) {
            first = initToString + "0";
        }

        for (int i = ipPrefix; i < maxIPAddress; i++) {
            if (i != init) {
                initToString = std::to_string(i); //2
                std::string second = initToString + initToString; //22

                std::string third = "0";
                std::string fourth = std::to_string(numberOfNetworks); //1
                
                if (initToString.length() > 1) {
                    second = initToString + "0";
                }

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