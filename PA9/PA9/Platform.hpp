#pragma once
#include "Obstacle.hpp"

class Platform
{
public:
	Platform(bool movement = false);
	~Platform();


private:

	bool mCanMove;
	sf::RectangleShape shape;
	sf::Vector2f velocity;

};

