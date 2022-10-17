#ifndef ROUTINGTABLE_H
#define ROUTINGTABLE_H

#include "Connection.h"

#include "vector"

class RoutingTable {
  private:
    std::vector<Connection> routingTable;

  public:
    RoutingTable();

     /**
     * Add new connection to the routing table
     * @param _connection available connection
     */
    void addRoute(Connection _connection);

    //Connection getNextHop();

     /**
     * Get the routing table
     * @return routing table of the entity
     */
    std::vector<Connection> getRoutingTable();
   
};

#endif