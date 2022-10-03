#include "Device.h"

#include <string>
#include <vector>

Device::Device(int _id, std::string _name) {
    id = _id;
    name = _name;
}

void Device::setConnection() {
    
}

void Device::sendPacket(Packet _sentPacket) {
    sentPacket = _sentPacket;



    //get neighbours -> routers
    //every entity has a connection
    //get those connections
    //connection -> get response time -> the one that responses faster -> create routing table
}

void Device::receivePacket(Packet _receivedPacket) {
    receivedPacket = _receivedPacket;
}

void Device::setNeighbours(std::vector<int> _neighbourIds) {
    neighbourIds = _neighbourIds;
}

std::vector<int> Device::getNeighbours() {
    return neighbourIds;
}

int Device::getId() {
    return id;
}

std::string Device::getName() {
    return name;
}