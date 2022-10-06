#ifndef ROUTINGTABLE_H
#define ROUTINGTABLE_H

#include "Connection.h"

#include "vector"

class RoutingTable {
  private:
    std::vector<Connection> routingTable;

  public:
    RoutingTable();

    void addRoute(Connection _connection);

    //Connection getNextHop();

    std::vector<Connection> getRoutingTable();
   
};

#endif