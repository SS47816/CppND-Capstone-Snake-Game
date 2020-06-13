# include "obstacle.h"

#include <algorithm>

Obstacle::Obstacle() : engine(dev()) {}

Obstacle::Obstacle(std::size_t grid_width, std::size_t grid_height) : engine(dev()) {
    rocks.clear();
    for (int i = 0; i < num_rocks; ++i) {
        auto random_w = std::uniform_int_distribution<int>(0, static_cast<int>(grid_width - 1));
        auto random_h = std::uniform_int_distribution<int>(0, static_cast<int>(grid_height - 1));
        SDL_Point rock{ random_w(engine), random_h(engine) };
        rocks.emplace_back(std::move(rock));
    }
}

bool Obstacle::RockCell(int x, int y) {
  for (auto const &rock : rocks) {
    if (x == rock.x && y == rock.y) {
      return true;
    }
  }
  return false;
}