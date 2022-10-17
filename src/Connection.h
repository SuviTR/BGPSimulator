#ifndef CONNECTION_H
#define CONNECTION_H

#include "entities/Device.h"

#include <random>

class Connection {
  private:
    //Device sourceEntity;
    //Device destinationEntity;
    int sourceEntityId;
    int destinationEntityId;
    std::string name;
    int id;
    std::string ipAddress;
    int distance;
    //double holdTime;
    //std::string name;

    enum BGPMessage { OPEN, UPDATE, NOTIFICATION, KEEPALIVE };
    std::vector<std::string> neighbours;

  public:
    Connection();

    //Connection(Device _sourceEntity, Device _destinationEntity, int _numberOfNetworks);

    Connection(int _sourceEntityId, int _destinationEntityId, std::string _ASName, std::string _sourceEntityName, std::string _destinationEntityName, int _numberOfNetworks);

    //Device getSourceEntity();
    //Device getDestinationEntity();

    /**
     * Get the id
     * @return the id of the source entity
     */
    int getSourceEntityId();

    /**
     * Get the id
     * @return the id of the destination entity
     */
    int getDestinationEntityId();

    /**
     * Generate the name of the connection
     * @param _ASName name of the AS to which the connection belongs to
     * @param _sourceEntityName name of the source entity
     * @param _destinationEntityName name of the destination entity
     */
    void generateName(std::string _ASName, std::string _sourceEntityName, std::string _destinationEntityName);
    void setName(std::string _name);
    std::string getName();

    /**
     * Configure the connection between two entities
     * @param _numberOfNetworks current total number of networks
     */
    void configureEntityConnection(int _numberOfNetworks);

    /**
     * Generate the connection id
     */
    void generateId();

    /**
     * Get the id
     * @return the id of the connection
     */
    int getId();

    //void generateName();
    //int getName();

    /**
     * Configure IP addresses between two entities
     * 
     * 2 routers:
     * 11.22.0.1 R1 towards R2
     * 11.33.0.2 R2 towards R1
     * 
     * @param _numberOfNetworks current total number of networks
     */
    void generateIPAddress(int _numberOfNetworks);
    std::string getIPAddress();

    /**
     * Generate the distance between two entities
     */
    void generateDistance();

    /**
     * Get distance
     * @return distance between two entities
     */
    int getDistance();

    /**
     * Generate and get the response time
     * @return the response time of the connection
     */
    double getResponseTime();

    double getHoldTime();

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