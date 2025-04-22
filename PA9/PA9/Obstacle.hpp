#pragma once
#include "GameObject.hpp"

class Obstacle : public GameObject
{
public:
	Obstacle();
	~Obstacle();

	void update(float deltaTime) override {

	}
	void render(RenderWindow& window) override {

	}
protected:

	bool mIsDangerous;
	Color mColor;

};

