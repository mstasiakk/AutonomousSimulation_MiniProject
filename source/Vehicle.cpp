#include "Vehicle.hpp"


	// constructor with default values
	Vehicle::Vehicle(float winWidth, float winHeight, float veh_x, float veh_y)
		: x{ veh_x }, y{ veh_y } {
		shape.setSize({ x,y });
		shape.setFillColor(sf::Color::Magenta);
		shape.setOrigin({ x / 2, y / 2 });
		shape.setPosition({ winWidth / 2, winHeight / 2 });
	}

	// methods
	void Vehicle::Steering() {
		// steering by keyboard
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
			shape.move({ -1.f, 0.f });
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
			shape.move({ 1.f, 0.f });
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
			shape.move({ 0.f, 1.f });
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
			shape.move({ 0.f, -1.f });
	} 

	void Vehicle::draw(sf::RenderWindow& window)
	{
		window.draw(shape);
	}