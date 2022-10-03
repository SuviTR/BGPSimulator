#ifndef ENTITY_ROUTER_H
#define ENTITY_ROUTER_H

#include <string>
#include <vector>
#include <random>

class Router {
  private:
    int id;
    std::string name;
    std::vector<int> neighbourIds;
    std::vector<std::string> neighbours;

  public:
    Router(int _id, std::string _name);

    //Router(int _id, std::string _name, std::vector<std::string> _neighbours);

    void setConnection();
    bool getHello();

    /**
     * Get the id of the router
     */
    int getId();

    /**
     * Get the name of the router
     */
    std::string getName();

    /**
     * Set neighbour entity ids
     */
    void setNeighbours(std::vector<int> _neighbourIds);

    /**
     * Get neighbour entity ids
     */
    std::vector<int> getNeighbours();
};

#endif