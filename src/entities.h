#pragma once
#include <SFML/Graphics.hpp>

float FOV = 60.f*M_PI/180;

class Player {
    public:
    float x, y, angle;
    Player(float x, float y, float angle = 0);
};
