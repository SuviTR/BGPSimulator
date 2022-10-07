#include "RoutingTable.h"

#include <iostream>

RoutingTable::RoutingTable() {}


void RoutingTable::addRoute(Connection _connection) {
    std::cout << "Connection " << _connection.getName() << " was added to the routing table." << std::endl;;
    routingTable.push_back(_connection);
}
/*
Connection RoutingTable::getNextHop(){

}*/

std::vector<Connection> RoutingTable::getRoutingTable() {
    return routingTable;
}
