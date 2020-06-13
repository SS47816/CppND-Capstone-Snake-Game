#include "food.h"

Food::Food() : engine(dev()) {}

Food::~Food() {};

void Food::setPosition(int grid_width, int grid_height) {
    auto random_w = std::uniform_int_distribution<int>(0, static_cast<int>(grid_width));
    auto random_h = std::uniform_int_distribution<int>(0, static_cast<int>(grid_height));
    position.x = random_w(engine);
    position.y = random_h(engine);
}

void Food::specialEffects() {
    // generate the food type
    // auto random_type = std::uniform_int_distribution<int>(0, 100);
    food_type = worm;
}