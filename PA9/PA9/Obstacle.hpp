#pragma once
#include "GameObject.hpp"

class Obstacle : public GameObject
{
public:
	Obstacle();
	~Obstacle();

protected:

	bool mIsDangerous;
	Color mColor;

};

