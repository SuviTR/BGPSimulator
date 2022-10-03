#include "Router.h"

#include <string>
#include <vector>
#include <random>

Router::Router(int _id, std::string _name) {
    id = _id;
    name = _name;
}
/*
Router::Router(int _id, std::string _name, std::vector<std::string> _neighbours) {
    id = _id;
    name = _name;
    neighbours = _neighbours;
}*/

void Router::setConnection() {

}

bool Router::getHello() {
    bool hello = false;
    int min = 0;
    int max = 10;
    int result = (double)rand() / max;

    if (result > 2) {
        hello = true;
    }
    return hello;
}

int Router::getId() {
    return id;
}

std::string Router::getName() {
    return name;
}

void Router::setNeighbours(std::vector<int> _neighbourIds) {
    neighbourIds = _neighbourIds;
}

std::vector<int> Router::getNeighbours() {
    return neighbourIds;
}

