#include "entities.h"
#include <cmath>

Player::Player(float x, float y, float angle): x(x), y(y), angle(angle) {
    step = 2;
    angle_step = 2.0f*M_PI/180;
}

void Player::move_forward() {
    x += cos(angle)*step;
    y += sin(angle)*step;
}
void Player::look_left() { angle -= angle_step; }
void Player::look_right() { angle += angle_step; }
