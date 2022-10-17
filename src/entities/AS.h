#ifndef ENTITY_AS_H
#define ENTITY_AS_H

#include "Device.h"

#include <iostream>
#include <string>
#include <vector>
#include <random>

class AS {
  private:
    std::string name;
    int numberOfRouters;
    std::vector<Device> routerList;
    int numberOfNetworks;
    int ipPrefix;
    int eBGP;

  public:
    AS(std::string _name);

    /**
     * Create routers
     * 
     * @param _numberOfRouters the number of routers in the AS
     * @param _ipPrefix the starting number of the IP addresses in the AS
     * @param _eBGP the edge router connecting two ASes
     */
    void createRouters(int _numberOfRouters, int _ipPrefix, int _eBGP);

    /**
     * Get router list
     * @return the router list of the AS
     */
    std::vector<Device> getRouters();

    /**
     * Get the name
     * @return the name of the AS
     */
    std::string getName();

};

#endif