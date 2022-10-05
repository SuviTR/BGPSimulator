#ifndef ENTITY_DEVICE_H
#define ENTITY_DEVICE_H

#include "../Connection.h"
#include "../Packet.h"
#include "../RoutingTable.h"

#include <string>
#include <vector>

class Device {
  private:
    int id;
    std::string name;
    Packet sentPacket;
    Packet receivedPacket;
    std::vector<Connection> connections;
    std::vector<int> neighbours;
    bool sendSucceeded;

  public:

    Device(int _id, std::string _name);

    //void setConnection(std::vector<Connection> _connections);

    /**
     * Set neighbour entity ids
     */
    void setNeighbours(std::vector<int> _neighbours);

    /**
     * Get neighbour entity ids
     */
    std::vector<int> getNeighbours();

    void setConnections(std::vector<Connection> _connections);

    std::vector<Connection> getConnections();

    void sendPacket(Packet _sentPacket);

    void receivePacket(Packet _receivedPacket);

    void setSendSucceeded(bool _sendSucceeded);
    
    bool getSendSucceeded();

    //RoutingTable getRoutingTable();
    
    /**
     * Get the id of the router
     */
    int getId();

    /**
     * Get the name of the router
     */
    std::string getName();

};

#endif