#include "map.h"

Wall::Wall(int x, int y, int w, int h): x(x), y(y), w(w), h(h) {}
float Wall::getX() { return x; }
float Wall::getY() { return y; }
int Wall::getW() { return w; }
int Wall::getH() { return h; }


Wall Map::getLast() { return data[data.size()-1]; }
Wall Map::get(int index) { return data[index]; }
int Map::size() { return data.size(); }
void Map::push_wall(Wall wall) { data.push_back(wall); }

void Map::add_base_box(int width, int height, int thickness) {
    this->push_wall( Wall(20, 20, width-40, thickness) );
    this->push_wall( Wall(20, 20, thickness, height-40) );
    this->push_wall( Wall(width-20-thickness, 20, thickness, height-40) );
    this->push_wall( Wall(20, height-20-thickness, width-40, thickness) );
}
