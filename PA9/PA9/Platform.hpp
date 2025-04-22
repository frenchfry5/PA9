#pragma once
#include "Obstacle.hpp"

class Platform : public Obstacle
{
public:
    Platform(const Vector2f& size, const Vector2f& position, bool movement = false);
	~Platform();


    void update(float deltaTime, const Map& map) override {
    }

    void render(sf::RenderWindow& window) override {
        sf::RectangleShape shape;
        shape.setSize(mShape.getSize());
        shape.setFillColor(mColor);
        shape.setPosition(mShape.getPosition());
        window.draw(shape);
    }

    Vector2f getPosition() const override {
        return mShape.getPosition();
    }

    FloatRect getBounds() const override;
private:
	bool mCanMove;
	sf::RectangleShape mShape;
	

};

