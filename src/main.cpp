#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "map.cpp"
#include "entities.cpp"

using namespace sf;

int main() {
	RenderWindow window(VideoMode({800, 600}), "Ray casting", Style::Default, State::Windowed);
	bool mapMode = true;

	Map map;
	RectangleShape shape;
	shape.setFillColor(Color::Green);
	map.add_base_box(window.getSize().x, window.getSize().y, 100);

	Player player(200, 200, 75.f*M_PI/180);
	CircleShape playerShape(10.0f);

	float lineX = player.x;
	float lineY = player.y;
	std::array viewLines = {
		Vertex{Vector2f(player.x, player.y)},
		Vertex{Vector2f(lineX, lineY)}
	};

	double lineFOVstep = FOV/window.getSize().x;
	double lineAngle = player.angle-FOV/2;
	float lineLength = 0;

	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()) {
			if (event->is<Event::Closed>())
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Key::W))
			player.move_forward();
		if (Keyboard::isKeyPressed(Keyboard::Key::A))
			player.look_left();
		if (Keyboard::isKeyPressed(Keyboard::Key::D))
			player.look_right();

		if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
			window.close();

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

		lineAngle = player.angle - FOV/2;
		for (int ray = 1; ray <= window.getSize().x; ray++) {
			for (int rangeToWall = 0; rangeToWall < 10000; rangeToWall++) {
				lineX = player.x + cos(lineAngle)*rangeToWall;
				lineY = player.y + sin(lineAngle)*rangeToWall;

				for (int wallIndex = 0; wallIndex < map.size(); wallIndex++) {
					if (map.get(wallIndex).isCollision(lineX, lineY)) {
						if (mapMode) {
							viewLines[0].position = Vector2f(player.x, player.y);
							viewLines[1].position = Vector2f(lineX, lineY);
							window.draw(viewLines.data(), viewLines.size(), PrimitiveType::Lines);
						} else {
							lineLength = window.getSize().y/rangeToWall;
							viewLines[0].position = Vector2f(ray, window.getSize().y/2 - lineLength/2);
							viewLines[1].position = Vector2f(ray, window.getSize().y/2 + lineLength/2);
							window.draw(viewLines.data(), viewLines.size(), PrimitiveType::Lines);
						}
						rangeToWall = 10001;
						break;
					}
				}

			}
			lineAngle += lineFOVstep;
		}

		window.display();
	}
}
