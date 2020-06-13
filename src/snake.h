#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <memory>
#include "SDL.h"
#include "obstacle.h"

class Snake {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Snake(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(grid_width / 2),
        head_y(grid_height / 2) {};

  void Update(std::shared_ptr<Obstacle> obs);

  void GrowBody();
  bool SnakeCell(int x, int y);
  void ChangeSpeedBy(const float percentage);

  Direction direction = Direction::kUp;

  float speed{0.1f};
  int size{1};
  bool alive{true};
  float head_x;
  float head_y;
  std::vector<SDL_Point> body;

 private:
  bool CheckIfAlive(SDL_Point &current_head_cell);
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);
  std::shared_ptr<Obstacle> obstacles;

  bool growing{false};
  int grid_width;
  int grid_height;
};

#endif