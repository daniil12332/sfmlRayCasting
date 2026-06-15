#include "entities.h"
#include <cmath>

Player::Player(float x, float y, float angle): x(x), y(y), angle(angle) {
    step = 50;
    angle_step = 50.0f*M_PI/180;
}

void Player::move_forward(float delta_time) {
    x += cos(angle)*step*delta_time;
    y += sin(angle)*step*delta_time;
}
void Player::look_left(float delta_time) { angle -= angle_step*delta_time; }
void Player::look_right(float delta_time) { angle += angle_step*delta_time; }
