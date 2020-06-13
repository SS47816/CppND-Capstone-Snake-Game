#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <random>
#include <vector>
#include "SDL.h"

class Obstacle {
  public:
    Obstacle();
    ~Obstacle();

    std::vector<SDL_Point> rocks;
    int r, g, b, a;

  private:
    std::random_device dev;
    std::mt19937 engine;
};

#endif // OBSTACLE_H