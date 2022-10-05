#include <random>

class RandomGenerator {
  private:
    double random;
    
  public:
    RandomGenerator() {}
    
    double getRandom(int min, int max) {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist(min, max);

        random = dist(rng);
        return random;
    }
    
};