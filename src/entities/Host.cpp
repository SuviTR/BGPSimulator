#include <string>
#include <vector>

class Host {
  private:
    int id;
    std::string name;
    Packet sentPacket;
    Packet receivedPacket;

  public:

    Host(int _id, std::string _name) : sentPacket(sentPacket), receivedPacket(receivedPacket) {
        id = _id;
        name = _name;
    }

    int getId() {
        return id;
    }

    std::string getName() {
        return name;
    }

    void sendPacket(Packet _sentPacket) {
        sentPacket = _sentPacket;
    }

    void receivePacket(Packet _receivedPacket) {
        receivedPacket = _receivedPacket;
    }

};