#ifndef ENTITY_DEVICE_H
#define ENTITY_DEVICE_H

#include "../Packet.h"

#include <string>
#include <vector>

class Device {
  private:
    int id;
    std::string name;
    Packet sentPacket;
    Packet receivedPacket;
    std::vector<int> neighbourIds;
    std::vector<std::string> neighbours;

  public:

    Device(int _id, std::string _name);

    void setConnection();

    void sendPacket(Packet _sentPacket);

    void receivePacket(Packet _receivedPacket);

    /**
     * Set neighbour entity ids
     */
    void setNeighbours(std::vector<int> _neighbourIds);

    /**
     * Get neighbour entity ids
     */
    std::vector<int> getNeighbours();
    
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