#pragma once
#include "ourLibrary.h"
#include "Enemy.hpp"

class Bug : public Enemy {
public:
	Bug(const Vector2f& pos) : Enemy(pos) {
		shape.setFillColor(Color::Magenta);
	}
	~Bug() {

	}
	void update(float deltaTime) override {}
	void update(float deltaTime, const Platform& pl) override {
		Enemy::update(deltaTime, pl);

		// if moving right keep moving right 
		// else flip direction
		if (movingR) {
			sf::FloatRect nextPos = shape.getGlobalBounds();
			nextPos.position.x += speed * deltaTime;
			nextPos.position.y -= 1;
			if (!pl.isColliding(nextPos)) {
				shape.move({ speed * deltaTime , 0 });
				
			}
			else {
				
				movingR = false;
			}
		}
		else if(movingR == false) {
			sf::FloatRect nextPos = shape.getGlobalBounds();
			nextPos.position.x -= speed * deltaTime;
			nextPos.position.y += 1;
			nextPos.position.y -= 2;
			if (!pl.isColliding(nextPos)) {
				shape.move({ -(speed * deltaTime) , 0 });
			}
			else {
				
				movingR = true;
			}
		}
	}


	void render(RenderWindow& window) override {
		window.draw(shape);
	}
	sf::Vector2f getPosition() const override {
		return shape.getPosition();
	}
	FloatRect getBounds() const override {
		return shape.getGlobalBounds();
	}
private:
	bool movingR = false;
};