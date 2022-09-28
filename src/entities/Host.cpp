#include <string>
#include <vector>

class Host {
  private:
    int id;
    std::string name;
    std::string homeRouter;

  public:
    Host(int _id, std::string _name, std::string _homeRouter) {
        id = _id;
        name = _name;
        homeRouter = _homeRouter;
    }

    int getId() {
        return id;
    }

    std::string getName() {
        return name;
    }

    std::string getHomeRouter() {
        return homeRouter;
    }

};