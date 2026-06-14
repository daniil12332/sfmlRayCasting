#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "map.cpp"
#include "entities.cpp"

using namespace sf;

int main() {
	RenderWindow window(VideoMode({800, 600}), "Ray casting", Style::Default, State::Fullscreen);
	bool mapMode = true;

	Map map;
	RectangleShape shape;
	shape.setFillColor(Color::Green);
	map.add_base_box(window.getSize().x, window.getSize().y, 100);

	Player player(200, 200, 30.f*M_PI/180);
	CircleShape playerShape(10.0f);

	std::array viewLines = {
		Vertex{Vector2f(player.x, player.y)},
		Vertex{Vector2f(player.x, player.y)},
	};

	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()) {
			if (event->is<Event::Closed>())
				window.close();
			if (event->is<Event::KeyPressed>())
				window.close();
		}

		window.clear();

		if (mapMode) {
			for (int i = 0; i < map.size(); i++) {
				shape.setSize( Vector2f(map.get(i).getW(), map.get(i).getH()) );
				shape.setPosition({map.get(i).getX(), map.get(i).getY()});
				window.draw(shape);
			}

			playerShape.setPosition({player.x-playerShape.getRadius(), player.y-playerShape.getRadius()});
			window.draw(playerShape);
		}

		/*for (int rangeToWall = 0; rangeToWall < 10000; rangeToWall++) {
			for (int wallIndex = 0; wallIndex < map.size(); wallIndex++) {

			}
		}*/
		int rangeToWall = 200;
		float lineX = player.x + cos(player.angle-FOV/2)*rangeToWall;
		float lineY = player.y + sin(player.angle-FOV/2)*rangeToWall;
		viewLines[1] = Vertex{Vector2f(lineX, lineY)};
		window.draw(viewLines.data(), viewLines.size(), PrimitiveType::Lines);

		lineX = player.x + cos(player.angle+FOV/2)*rangeToWall;
		lineY = player.y + sin(player.angle+FOV/2)*rangeToWall;
		viewLines[1] = Vertex{Vector2f(lineX, lineY)};
		window.draw(viewLines.data(), viewLines.size(), PrimitiveType::Lines);

		window.display();
	}
}
