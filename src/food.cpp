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
    auto random_type = std::uniform_int_distribution<int>(0, 100);
    const auto result = random_type(engine);
    if (result <= k_worm_prob) {
        food_type = FoodType::worm;
        score_buff = k_worm_score;
        speed_buff = k_worm_speed;
    }
    else if (result <= k_worm_prob + k_poisoned_mushroom_prob) {
        food_type = FoodType::poisoned_mushroom;
        score_buff = k_poisoned_mushroom_score;
        speed_buff = k_poisoned_mushroom_speed;
    }
    else {
        food_type = FoodType::blue_berry;
        auto random_score = std::uniform_int_distribution<int>(1, k_blue_berry_max_score);
        score_buff = random_score(engine);
        auto random_speed = std::uniform_int_distribution<int>(-100, 100);
        speed_buff = random_speed(engine) * k_blue_berry_max_speed / 100.0f;
    }
}