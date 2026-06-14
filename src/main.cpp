#include <SFML/Graphics.hpp>
#include <iostream>
#include "map.cpp"

using namespace sf;

int main() {
	RenderWindow window(VideoMode({800, 600}), "Ray casting");

	Map map;
	RectangleShape shape;
	shape.setFillColor(Color::Green);
	map.add_base_box(window.getSize().x, window.getSize().y, 100);

	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()) {
			if (event->is<Event::Closed>())
				window.close();
		}

		window.clear();

		for (int i = 0; i < map.size(); i++) {
			shape.setSize( Vector2f(map.get(i).getW(), map.get(i).getH()) );
			shape.setPosition({map.get(i).getX(), map.get(i).getY()});
			window.draw(shape);
		}

		window.display();
	}
}
