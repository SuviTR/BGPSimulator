#include <string>
#include <vector>

class Host {
  private:
    std::string name;
    std::string homeRouter;

  public:
    Host(std::string _name, std::string _homeRouter) {
        name = _name;
        homeRouter = _homeRouter;
    }

    std::string getName() {
        return name;
    }

    std::string getHomeRouter() {
        return homeRouter;
    }

};