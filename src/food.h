#ifndef FOOD_H
#define FOOD_H

#include <random>
#include "SDL.h"

enum FoodType {poisoned_mushroom = 0, worm, blue_berry};

class Food {
  public:
    Food();
    ~Food();

    void setPosition(int grid_width, int grid_height);
    void specialEffects();
    
    int food_type;
    SDL_Point position;

  private:
    std::random_device dev;
    std::mt19937 engine;

    const int k_worm_prob = 100;
    const int k_poisoned_mushroom_prob = 0;
    const int k_berry_prob = 0;
};

#endif // FOOD_H