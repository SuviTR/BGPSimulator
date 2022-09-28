#include <random>

class Connection {
  private:

    int id;
    std::string ipAddress;
    int distance;
    //double holdTime;

    enum BGPMessage { OPEN, UPDATE, NOTIFICATION, KEEPALIVE };
    std::vector<std::string> neighbours;

  public:
    Connection() {}

    Connection(int _sourceEntityId, int _destinationEntityId, int _numberOfNetworks) {
        configureEntityConnection(_sourceEntityId,_destinationEntityId, _numberOfNetworks);
    }

    /**
     * ip addresses between two entities
     * distance between them
     */
    void configureEntityConnection(int _sourceEntityId, int _destinationEntityId, int _numberOfNetworks) {
        generateId(_sourceEntityId, _destinationEntityId);
        generateIPAddress(_sourceEntityId, _destinationEntityId, _numberOfNetworks);
        generateDistance();
    }

    void generateId(int _sourceEntityId, int _destinationEntityId) {
        std::string sourceEntityIdToString = std::to_string(_sourceEntityId);
        std::string destinationEntityIdToString = std::to_string(_destinationEntityId);

        std::string idString = sourceEntityIdToString + destinationEntityIdToString;
        id = stoi(idString);
    }
    int getId() {
        return id;
    }

     /**
     * 2 routers:
     * 11.22.0.1 R1 towards R2
     * 11.33.0.2 R2 towards R1
     */
    void generateIPAddress(int _sourceRouter, int _destinationRouter, int _numberOfNetworks) {

        std::string sourceRouterToString = std::to_string(_sourceRouter); //1
        std::string first = sourceRouterToString + sourceRouterToString; //11
        if (sourceRouterToString.length() > 1) {
            first = sourceRouterToString + "0";
        }

        std::string destinationRouterToString = std::to_string(_destinationRouter); //2
        std::string second = destinationRouterToString + destinationRouterToString; //11
        if (destinationRouterToString.length() > 1) {
            second = destinationRouterToString + "0";
        }

        std::string third = "0";
        std::string fourth = std::to_string(_numberOfNetworks); //1

        ipAddress = first + "." + second + "." + third + "." + fourth; //11.22.0.1
    }
    std::string getIPAddress() {
        return ipAddress;
    }

    void generateDistance() {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist10(1,10);

        distance = dist10(rng);
    }
    int getDistance() {
        return distance;
    }

    double getHoldTime() {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6);

        distance = dist6(rng);
        return distance;
    }


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