#pragma once
#include "GameObject.hpp"

class Enemy : public GameObject
{
public:
	Enemy();
	~Enemy();

private:
    sf::RectangleShape shape;
    float speed = 200;
};

