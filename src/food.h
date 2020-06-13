#ifndef FOOD_H
#define FOOD_H

#include <random>
#include "SDL.h"

enum FoodType {poisoned_mushroom = 0, worm = 1, blue_berry = 5};

class Food {
  public:
    Food(int grid_width, int grid_height);
    ~Food();
    
    int food_type;
    SDL_Point point;

  private:
    void setProbability();

    std::random_device dev;
    std::mt19937 engine;
    std::uniform_int_distribution<int> random_w;
    std::uniform_int_distribution<int> random_h;
    std::uniform_int_distribution<int> random_type;
};

#endif // FOOD_H