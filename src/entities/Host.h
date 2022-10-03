#ifndef ENTITY_HOST_H
#define ENTITY_HOST_H

#include "../Packet.h"

#include <string>
#include <vector>

class Host {
  private:
    int id;
    std::string name;
    Packet sentPacket;
    Packet receivedPacket;
    std::vector<int> neighbourIds;

  public:

    Host(int _id, std::string _name); /*: sentPacket(sentPacket), receivedPacket(receivedPacket)*/

    void setConnection();

    int getId();

    std::string getName();

    void sendPacket(Packet _sentPacket);

    void receivePacket(Packet _receivedPacket);

    void setNeighbours(std::vector<int> _neighbourIds);

    std::vector<int> getNeighbours();

};

#endif