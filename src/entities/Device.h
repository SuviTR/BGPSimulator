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
    bool sendSuccessful;
    RoutingTable routingTable;

  public:

    Device(int _id, std::string _name);

    //void setConnection(std::vector<Connection> _connections);

    /**
     * Set neighbour entity ids
     */
    //void setNeighbours(std::vector<int> _neighbours);

    /**
     * Get neighbour entity ids
     * @return the neighbour entity id list of the device
     */
    //std::vector<int> getNeighbours();

    /**
     * Set neighbour connections of the device
     * @param _connections neighbour connections
     */
    void setConnections(std::vector<Connection> _connections);

    /**
     * Get neighbour connections
     * @return the neighbour connection list of the device
     */
    std::vector<Connection> getConnections();

    /**
     * Send a packet
     * @param _sentPacket a packet to be sent by the device
     */
    void sendPacket(Packet _sentPacket);

    /**
     * Receive a packet
     * @param _receivedPacket a packet to be received
     */
    //void receivePacket(Packet _receivedPacket);

    /**
     * Set the outcome of whether the connection was on and whether the packet was sent successfully
     * @param _sendSuccessful was the transfer of the packet successful
     */
    void setSendSuccessful(bool _sendSuccessful);
    
    /**
     * Get the outcome of whether the connection was on and whether the packet was sent successfully
     * @return if the packet was successfully sent
     */
    bool getSendSuccessful();

    /**
     * Set the routing table
     * @param _routingTable the routing table of the device
     */
    //void setRoutingTable(RoutingTable _routingTable);

    /** 
     * Get the routing table
     * @return the routing table of the device
     */
    RoutingTable getRoutingTable();

    /**
     * The device informs the status of the packet transfer
     * @param _message status
     * @param _responseTime neighbour connection's response time
     */
    void message(std::string _message, double _responseTime);
    
    /**
     * Get the id
     * @return the id of the device
     */
    int getId();

    /**
     * Get the name
     * @return the name of the device
     */
    std::string getName();

};

#endif