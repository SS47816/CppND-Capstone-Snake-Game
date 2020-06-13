#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(std::make_shared<Snake>(grid_width, grid_height)),
      obstacles(std::make_shared<Obstacle>(grid_width, grid_height)),
      food(std::make_shared<Food>()),
      grid_width(grid_width),
      grid_height(grid_height) {
  PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, food, obstacles);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count, snake->speed/snake->init_speed);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood() {
  while (true) {
    food->setPosition(grid_width, grid_height);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake->SnakeCell(food->position.x, food->position.y)) {
      if (!obstacles->RockCell(food->position.x, food->position.y)) {
        food->specialEffects();
        return;
      }
    }
  }
}

void Game::Update() {
  if (!snake->alive) return;

  snake->Update(obstacles);

  int new_x = static_cast<int>(snake->head_x);
  int new_y = static_cast<int>(snake->head_y);

  // Check if there's food over here
  if (food->position.x == new_x && food->position.y == new_y) {
    score += food->score_buff;
    // Grow snake and increase speed.
    snake->GrowBody();
    snake->ChangeSpeedBy(food->speed_buff);
    // place next food
    PlaceFood();
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake->size; }