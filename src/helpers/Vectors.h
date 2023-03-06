#ifndef ENTITY_VECTORS_H
#define ENTITY_VECTORS_H

#include "../entities/Device.h"

#include <vector>
#include <iostream>


class Vectors {
  private:
    //int index;
    
  public:
    Vectors();
    
    int getIndex(std::vector<Device> _v, std::string _K);
};

#endif