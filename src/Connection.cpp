#include <random>

class Connection {
  private:
    enum BGPMessage { OPEN, UPDATE, NOTIFICATION, KEEPALIVE };
    std::vector<std::string> neighbours;

  public:
    Host sourceHost;
    Host destinationHost;
    Router nextHop;
    double holdTime;

    Connection(Host _sourceHost, Router _nextHop, Host _destinationHost) : sourceHost(_sourceHost), nextHop(_nextHop), destinationHost(_destinationHost) {
        neighbours = nextHop.getNeighbours();
    }

    double getHoldTime() {
        double min = 0.0;
        double max = 3.0;

        //int randNum = rand()%(max-min + 1) + min;

        double f = (double)rand() / max;
        return min + f * (max - min);

    }

    std::string getBGPMessage() {
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
    }

    
    Router getNextHop() {
        return nextHop;
    }
    /*
    std::vector<std::string> getNeighbours() {
        return neighbours;
    }*/

};