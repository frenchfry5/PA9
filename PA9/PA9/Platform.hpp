#pragma once
#include "Obstacle.hpp"

class Platform : public Obstacle
{
public:
	Platform(const Vector2f& size, const Vector2f& position, vector<Platform>& platformVector, bool movement = false);
	~Platform();


	sf::FloatRect getBounds() const;

private:

	bool mCanMove;
	sf::RectangleShape mShape;
	

};

