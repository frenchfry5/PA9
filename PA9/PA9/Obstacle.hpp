#pragma once
#include "GameObject.hpp"

class Obstacle : public GameObject
{
public:
	Obstacle();
	~Obstacle();

private:

	bool isDangerous;

};

