#include "Host.h"

#include <string>
//#include "../Packet.h"

#include <vector>

Host::Host(int _id, std::string _name) /*: sentPacket(sentPacket), receivedPacket(receivedPacket)*/ {
    id = _id;
    name = _name;
}

void Host::setConnection() {
    
}

int Host::getId() {
    return id;
}

std::string Host::getName() {
    return name;
}


void Host::sendPacket(Packet _sentPacket) {
    sentPacket = _sentPacket;

    //get neighbours -> routers
    //every entity has a connection
    //get those connections
    //connection -> get response time -> the one that responses faster -> create routing table
}

void Host::receivePacket(Packet _receivedPacket) {
    receivedPacket = _receivedPacket;
}

void Host::setNeighbours(std::vector<int> _neighbourIds) {
    neighbourIds = _neighbourIds;
}

std::vector<int> Host::getNeighbours() {
    return neighbourIds;
}