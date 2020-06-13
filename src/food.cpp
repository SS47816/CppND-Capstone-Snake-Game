#include "food.h"

Food::Food(int grid_width, int grid_height)
    :   engine(dev()),
        random_w(0, static_cast<int>(grid_width)),
        random_h(0, static_cast<int>(grid_height)),
        random_type(0, 100) {
    setProbability();
}

Food::~Food() {};

void Food::setProbability() {
    
}