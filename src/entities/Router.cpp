#include <string>
#include <vector>
#include <random>

class Router {
  private:
    int id;
    std::string name;
    std::vector<std::string> neighbours;

  public:
    Router(int _id, std::string _name) {
        id = _id;
        name = _name;
    }
    /*
    Router(int _id, std::string _name, std::vector<std::string> _neighbours) {
        id = _id;
        name = _name;
        neighbours = _neighbours;
    }*/

    bool getHello() {
        bool hello = false;
        int min = 0;
        int max = 10;
        int result = (double)rand() / max;

        if (result > 2) {
            hello = true;
        }
        return hello;
    }

    int getId() {
        return id;
    }

    std::string getName() {
        return name;
    }

    std::vector<std::string> getNeighbours() {
        return neighbours;
    }

};