#include "AS.h"

#include "Router.cpp"

#include <iostream>
#include <string>
#include <vector>
#include <random>

AS::AS(std::string _name) { // Constructor with parameters
    name = _name;
    numberOfNetworks = 1;
}

void AS::createRouters(int _numberOfRouters, int _ipPrefix, int _eBGP) { //6, 1, 6
    numberOfRouters = _numberOfRouters;
    ipPrefix = _ipPrefix;
    eBGP = _eBGP;
    routerList.clear();
    
    for (int i = 1; i <= numberOfRouters; i++) {

        std::string name = "R" + std::to_string(ipPrefix);
        if (i == eBGP) {
            name = name + "e";
        }
        
        Device router = Device(ipPrefix, name);
        routerList.push_back(router);
        ipPrefix++;
    }
}

std::vector<Device> AS::getRouters() {
    return routerList;
}

std::string AS::getName() {
    return name;
}
