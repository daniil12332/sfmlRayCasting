#pragma once
#include <cmath>

float FOV = 60.f*M_PI/180;

class Player {
    public:
    float x, y, angle;
    float step, angle_step;

    Player(float x, float y, float angle = 0);

    void move_forward();
    void move_back();
    void move_right();
    void move_left();
    
    void look_right();
    void look_left();
};
