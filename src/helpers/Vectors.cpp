#include "Vectors.h"

#include <vector>
#include <iostream>

Vectors::Vectors() {
}

int Vectors::getIndex(std::vector<Device> _v, std::string _K) {
    int i = 0;
    
    do {
        if (_v[i].getName().compare(_K) == 0) {
            //std::cout << "Index: " << i << std::endl;
            return i;
        }
        i++;
    } while (i < _v.size());

    return -1;
}
