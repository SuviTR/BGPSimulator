#include <random>

class RandomGenerator {
  private:
    double random;
    
  public:
    RandomGenerator() {}
    
    /**
     * Get the random number
     * @param min the minimum number
     * @param max the maximum number
     * @return the random number between the min and max values
     */
    double getRandom(int min, int max) {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist(min, max);

        random = dist(rng);
        return random;
    }
    
};