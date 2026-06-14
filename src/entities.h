#pragma once
#include <SFML/Graphics.hpp>

class Player {
    public:
    float x, y, angle;
    Player(float x, float y, float angle = 0);
};
