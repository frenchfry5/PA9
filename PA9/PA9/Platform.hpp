#pragma once
#include "Obstacle.hpp"

class Platform : public Obstacle
{
public:
	Platform(const Vector2f& size, const Vector2f& position, vector<Platform>& platformVector, bool movement = false);
	~Platform();


    void update(float deltaTime) override {
    }

    void render(sf::RenderWindow& window) override {
        window.draw(mShape);
    }

    Vector2f getPosition() const override {
        return mShape.getPosition();
    }

    FloatRect getBounds() const override;



private:

	bool mCanMove;
	sf::RectangleShape mShape;
	

};

