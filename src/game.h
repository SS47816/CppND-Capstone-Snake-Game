#ifndef GAME_H
#define GAME_H

#include <random>
#include <memory>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "food.h"
#include "obstacle.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

 private:
  std::shared_ptr<Snake> snake;
  std::shared_ptr<Food> food;
  std::shared_ptr<Obstacle> obstacles;

  int grid_width;
  int grid_height;

  int score{0};

  void PlaceFood();
  void Update();
};

#endif