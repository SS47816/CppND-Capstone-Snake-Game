#include "snake.h"
#include <cmath>
#include <iostream>

void Snake::Update(std::shared_ptr<Obstacle> obs) {
  obstacles = obs;
  SDL_Point prev_cell{ static_cast<int>(head_x), static_cast<int>(head_y) };  // We first capture the head's cell before updating.
  UpdateHead();
  SDL_Point current_cell{ static_cast<int>(head_x), static_cast<int>(head_y) };  // Capture the head's cell after updating.

  // Update all of the body vector items if the snake head has moved to a new cell.
  if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y) {
    // std::cout << "x: " << current_cell.x << " y: " << current_cell.y << std::endl;
    UpdateBody(current_cell, prev_cell);
    CheckIfAlive(current_cell);
  }
}

// Check if the snake has died.
bool Snake::CheckIfAlive(SDL_Point &current_head_cell) {
  for (auto const &item : body) {
    if (current_head_cell.x == item.x && current_head_cell.y == item.y) {
      alive = false;
      break;
    }
    // check if hit the walls
    else if (current_head_cell.x < 0 || current_head_cell.x >= grid_width ||
             current_head_cell.y < 0 || current_head_cell.y >= grid_height) {
      alive = false;
      break;
    }
    // check if hit the rocks
    else if (obstacles->RockCell(current_head_cell.x, current_head_cell.y)) {
      alive = false;
      break;
    }
  }

  return alive;
}

void Snake::UpdateHead() {
  switch (direction) {
    case Direction::kUp:
      head_y -= speed;
      break;

    case Direction::kDown:
      head_y += speed;
      break;

    case Direction::kLeft:
      head_x -= speed;
      break;

    case Direction::kRight:
      head_x += speed;
      break;
  }

  // Wrap the Snake around to the beginning if going off of the screen.
  // head_x = fmod(head_x + grid_width, grid_width);
  // head_y = fmod(head_y + grid_height, grid_height);
}

void Snake::UpdateBody(SDL_Point &current_head_cell, SDL_Point &prev_head_cell) {
  // Add previous head location to vector
  body.push_back(prev_head_cell);

  if (!growing) {
    // Remove the tail from the vector.
    body.erase(body.begin());
  } else {
    growing = false;
    size++;
  }
}

void Snake::GrowBody() { growing = true; }

// Inefficient method to check if cell is occupied by snake.
bool Snake::SnakeCell(int x, int y) {
  if (x == static_cast<int>(head_x) && y == static_cast<int>(head_y)) {
    return true;
  }
  for (auto const &item : body) {
    if (x == item.x && y == item.y) {
      return true;
    }
  }
  return false;
}

void Snake::ChangeSpeedBy(const float percentage) {
  speed *= (1.0f + percentage/100.0f);
  if (speed < init_speed) { speed = 0.1f; };
}