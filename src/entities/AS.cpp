#include "Router.cpp"

#include <iostream>
#include <string>
#include <vector>
#include <random>

class AS {
  private:
    std::string name;
    int numberOfRouters;
    std::vector<Router> routerList;
    int numberOfNetworks;
    int ipPrefix;
    int eBGP;

  public:
    AS(std::string _name) { // Constructor with parameters
        name = _name;
        numberOfNetworks = 1;
    }

    void createRouters(int _numberOfRouters, int _ipPrefix, int _eBGP) { //6, 1
        numberOfRouters = _numberOfRouters;
        ipPrefix = _ipPrefix;
        eBGP = _eBGP;
        
        for (int i = 1; i <= numberOfRouters; i++) {

            std::string name = "R" + std::to_string(_ipPrefix);
            if (i == eBGP) {
                name = name + "e";
            }
            
            Router router = Router(_ipPrefix, name);
            routerList.push_back(router);
            _ipPrefix++;
        }
    }

    std::vector<Router> getRouters() {
        return routerList;
    }

};