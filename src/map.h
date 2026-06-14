#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class Wall {
    int x;
    int y;
    int w;
    int h;
    public:
    Wall(int x, int y, int w, int h);
    float getX();
    float getY();
    int getW();
    int getH();
};

class Map {
    std::vector <Wall> data;
    public:
    Wall getLast();
    Wall get(int index);
    int size();
    void push_wall(Wall wall);
    void add_base_box(int width, int height, int thickness);
};
