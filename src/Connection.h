#ifndef CONNECTION_H
#define CONNECTION_H

#include <random>

class Connection {
  private:

    int sourceEntityId;
    int destinationEntityId;
    int id;
    std::string ipAddress;
    int distance;
    //double holdTime;

    enum BGPMessage { OPEN, UPDATE, NOTIFICATION, KEEPALIVE };
    std::vector<std::string> neighbours;

  public:
    Connection();

    Connection(int _sourceEntityId, int _destinationEntityId, int _numberOfNetworks);

    int getSourceEntityId();
    int getDestinationEntityId();

    /**
     * ip addresses between two entities
     * distance between them
     */
    void configureEntityConnection(int _numberOfNetworks);

    void generateId();
    int getId();

     /**
     * 2 routers:
     * 11.22.0.1 R1 towards R2
     * 11.33.0.2 R2 towards R1
     */
    void generateIPAddress(int _numberOfNetworks);
    std::string getIPAddress();

    void generateDistance();
    int getDistance();

    double getHoldTime();

    /**
     * Establish a TCP connection
     */
    void establishConnection();


    /*
    std::string getBGPMessage() {
        bool hello = nextHop.getHello();
        BGPMessage message = OPEN;
        std::string msg = "";

        switch (message)
        {
        case OPEN:
            msg="OPEN";
            break;
        case UPDATE:
            msg="UPDATE";
            break;
        case NOTIFICATION:
            msg="NOTIFICATION";
            break;
        case KEEPALIVE:
            msg="KEEPALIVE";
            break;
        default:
            break;
        }
        return msg;
    }*/

    
    /*
    std::vector<std::string> getNeighbours() {
        return neighbours;
    }*/

};

#endif