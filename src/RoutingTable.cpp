#include "RoutingTable.h"

#include <iostream>

RoutingTable::RoutingTable() {}


void RoutingTable::addRoute(Connection _connection) {
    std::cout << "Connection to the routing table " << _connection.getId() << "\n";
    routingTable.push_back(_connection);
}
/*
Connection RoutingTable::getNextHop(){

}*/

std::vector<Connection> RoutingTable::getRoutingTable() {
    return routingTable;
}
