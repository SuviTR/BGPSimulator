#include "Device.h"

#include "../RoutingTable.cpp"

#include <string>
#include <vector>
#include <iostream>

Device::Device(int _id, std::string _name) {
    id = _id;
    name = _name;
}
/*
void Device::setConnection(std::vector<Connection> _connections) {
    connections = _connections;
}*/

void Device::sendPacket(Packet _sentPacket) {
    sentPacket = _sentPacket;
    double prevTime = 10000;
    Connection fastestConn = Connection();
    bool connectionFound = false;
    setSendSuccessful(false);

    //neighbour connections
    if (connections.size() > 1) {
        for (int i = 0; i < connections.size(); i++) {
            double curTime = connections[i].getResponseTime();
            std::cout << "curTime " << curTime << "\n";
            if (curTime != 0) {
                if (curTime < prevTime) {
                    fastestConn = connections[i];
                    connectionFound = true;
                }
            }
            prevTime = curTime;
        }
    } else {
        double curTime = connections[0].getResponseTime();
        std::cout << "curTime else " << curTime << "\n";
        if (curTime != 0) {
            fastestConn = connections[0];
            connectionFound = true;
        }
    }

    if (connectionFound) {
        RoutingTable routingTable = RoutingTable();
        routingTable.addRoute(fastestConn);
        setSendSuccessful(true);
    } 
}

void Device::setSendSuccessful(bool _sendSuccessful) {
    sendSuccessful = _sendSuccessful;
}

bool Device::getSendSuccessful() {
    return sendSuccessful;
}

void Device::receivePacket(Packet _receivedPacket) {
    receivedPacket = _receivedPacket;
}

void Device::setNeighbours(std::vector<int> _neighbours) {
    neighbours = _neighbours;
}

std::vector<int> Device::getNeighbours() {
    return neighbours;
}

void Device::setConnections(std::vector<Connection> _connections) {
    connections = _connections;
}

std::vector<Connection> Device::getConnections(){
    return connections;
}

int Device::getId() {
    return id;
}

std::string Device::getName() {
    return name;
}