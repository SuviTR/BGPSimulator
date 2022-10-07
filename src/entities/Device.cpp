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
    double curTime;
    double prevTime = 10000;
    Connection fastestConn = Connection();
    bool connectionFound = false;
    setSendSuccessful(false);

    //neighbour connections
    if (connections.size() > 1) {
        for (int i = 0; i < connections.size(); i++) {
            curTime = connections[i].getResponseTime();
            std::cout << "curTime " << curTime << "\n";
            if (curTime > 1) {
                if (curTime < prevTime) {
                    fastestConn = connections[i];
                    connectionFound = true;
                }
                prevTime = curTime;
            }
        }
    } else {
        curTime = connections[0].getResponseTime();
        if (curTime > 1) {
            fastestConn = connections[0];
            connectionFound = true;
        }
    }

    if (connectionFound) {
        std::cout << "Connection " << fastestConn.getName() << " was established." << std::endl;

        RoutingTable routingTable = RoutingTable();
        routingTable.addRoute(fastestConn);
        
        
        std::vector<Connection> routing = routingTable.getRoutingTable();
        std::cout << getName() << "'s routing table: " << std::endl;
        for (int i = 0; i < routing.size(); i++) {
            std::cout << routing[i].getName() << " " << routing[i].getIPAddress() << std::endl;
        }

        setSendSuccessful(true);
        if (curTime == 1 || prevTime < curTime) {
            message("Packet was successufully transmitted. Response time:", prevTime);
        } else {
            message("Packet was successufully transmitted. Response time:", curTime);
        }
    } else {
        message("Packet could not be transmitted because the connection is not responding. Response time:", curTime);
    }
}

void Device::setSendSuccessful(bool _sendSuccessful) {
    sendSuccessful = _sendSuccessful;
}

bool Device::getSendSuccessful() {
    return sendSuccessful;
}

void Device::setRoutingTable(RoutingTable _routingTable) {
    routingTable = _routingTable;
}

RoutingTable Device::getRoutingTable() {
    return routingTable;
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

void Device::message(std::string _message, double _responseTime) {
    std::cout << "Message from " << getName() << ": " << _message << " " << _responseTime << "\n" << std::endl;
}

int Device::getId() {
    return id;
}

std::string Device::getName() {
    return name;
}