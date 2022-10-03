#ifndef ENTITY_AS_H
#define ENTITY_AS_H

#include "Router.h"

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
    AS(std::string _name);

    void createRouters(int _numberOfRouters, int _ipPrefix, int _eBGP);

    std::vector<Router> getRouters();

};

#endif