#include "Connection.h"
#include "helpers/RandomGenerator.cpp"

#include <random>

Connection::Connection() {}
/*
Connection::Connection(Device _sourceEntity, Device _destinationEntity, int _numberOfNetworks) : sourceEntity(_sourceEntity), destinationEntity(_destinationEntity) {
    configureEntityConnection(_numberOfNetworks);
}*/

Connection::Connection(int _sourceEntityId, int _destinationEntityId, int _numberOfNetworks) {
    sourceEntityId = _sourceEntityId;
    destinationEntityId = _destinationEntityId;
    configureEntityConnection(_numberOfNetworks);
}

int Connection::getSourceEntityId() {
    return sourceEntityId;
}
int Connection::getDestinationEntityId() {
    return destinationEntityId;
}

/*
Device Connection::getSourceEntity() {
    return sourceEntity;
}
Device Connection::getDestinationEntity() {
    return destinationEntity;
}*/

/**
 * ip addresses between two entities
 * distance between them
 */
void Connection::configureEntityConnection(int _numberOfNetworks) {
    generateId();
    generateIPAddress(_numberOfNetworks);
    generateDistance();
}

void Connection::generateId() {
    std::string sourceEntityIdToString = std::to_string(sourceEntityId);
    std::string destinationEntityIdToString = std::to_string(destinationEntityId);

    std::string idString = sourceEntityIdToString + destinationEntityIdToString;
    id = stoi(idString);
}
int Connection::getId() {
    return id;
}

/*
void generateName() {}
int getName() {}
*/

    /**
 * 2 routers:
 * 11.22.0.1 R1 towards R2
 * 11.33.0.2 R2 towards R1
 */
void Connection::generateIPAddress(int _numberOfNetworks) {

    std::string sourceEntityToString = std::to_string(sourceEntityId); //1
    std::string first = sourceEntityToString + sourceEntityToString; //11
    if (sourceEntityToString.length() > 1) {
        first = sourceEntityToString + "0";
    }

    std::string destinationEntityToString = std::to_string(destinationEntityId); //2
    std::string second = destinationEntityToString + destinationEntityToString; //11
    if (destinationEntityToString.length() > 1) {
        second = destinationEntityToString + "0";
    }

    std::string third = "0";
    std::string fourth = std::to_string(_numberOfNetworks); //1

    ipAddress = first + "." + second + "." + third + "." + fourth; //11.22.0.1
}
std::string Connection::getIPAddress() {
    return ipAddress;
}

void Connection::generateDistance() {
    distance = RandomGenerator().getRandom(1,10);
}
int Connection::getDistance() {
    return distance;
}

double Connection::getResponseTime() {
    double responseTime = RandomGenerator().getRandom(1,10);
    return responseTime;
}

double Connection::getHoldTime() {
    double holdTime = RandomGenerator().getRandom(1,6);
    return holdTime;
}


/*
std::string Connection::getBGPMessage() {
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

