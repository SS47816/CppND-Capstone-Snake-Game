#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <random>
#include <vector>
#include "SDL.h"

class Obstacle {
  public:
    Obstacle();
    Obstacle(std::size_t grid_width, std::size_t grid_height);

    std::vector<SDL_Point> rocks;
    // paint grey
    const int r = 0x7D;
    const int g = 0x7D;
    const int b = 0x7D;
    const int a = 0xFF;

  private:
    const int num_rocks = 10;
    std::random_device dev;
    std::mt19937 engine;
};

#endif // OBSTACLE_H