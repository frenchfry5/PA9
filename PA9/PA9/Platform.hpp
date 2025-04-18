#pragma once
#include "Obstacle.hpp"

class Platform : public Obstacle
{
public:
	Platform(bool movement = false);
	~Platform();


private:

	bool mCanMove;
	sf::RectangleShape shape;
	

};

