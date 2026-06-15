#pragma once
#include <cmath>

float FOV = 60.f*M_PI/180;

class Player {
    public:
    float x, y, angle;
    float step, angle_step;

    Player(float x, float y, float angle = 0);

    void move_forward(float delta_time);
    void move_back(float delta_time);
    void move_right(float delta_time);
    void move_left(float delta_time);
    
    void look_right(float delta_time);
    void look_left(float delta_time);
};
