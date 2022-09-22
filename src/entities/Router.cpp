#include <string>
#include <vector>

class Router {
  private:
    std::string name;
    std::vector<std::string> neighbours;

  public:
    Router(std::string _name, std::vector<std::string> _neighbours) {
        name = _name;
        neighbours = _neighbours;
    }

    std::string getName() {
        return name;
    }

    std::vector<std::string> getNeighbours() {
        return neighbours;
    }

};