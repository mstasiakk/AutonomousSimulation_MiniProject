#pragma once
#include <SFML/Graphics.hpp>

class Vehicle {
private:
	float x, y;
	sf::RectangleShape shape;

public:

	// constructor with default values
	Vehicle(float winWidth, float winHeight, float veh_x = 20.f, float veh_y = 40.f);

	// methods
	void Steering(); // steering by keyboard
	void draw(sf::RenderWindow& window);
};