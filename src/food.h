#ifndef FOOD_H
#define FOOD_H

#include <random>
#include "SDL.h"

enum FoodType {worm = 0, poisoned_mushroom, berry};

class Food {
  public:
    Food();
    ~Food();

    void setPosition(int grid_width, int grid_height);
    void specialEffects();
    
    int food_type;
    int score_buff;
    float speed_buff;
    SDL_Point position;
    int r, g, b, a;

  private:
    std::random_device dev;
    std::mt19937 engine;

    const int k_worm_prob = 80;                        // percentage
    const int k_poisoned_mushroom_prob = 10;           // percentage
    const int k_berry_prob = 10;                       // percentage
    const int k_worm_score = 1;
    const int k_poisoned_mushroom_score = 0;
    const int k_berry_max_score = 10;
    const float k_worm_speed = 10.0f;                  // percentage
    const float k_poisoned_mushroom_speed = -50.0f;    // percentage
    const float k_berry_max_speed = 50.0f;             // percentage
};

#endif // FOOD_H