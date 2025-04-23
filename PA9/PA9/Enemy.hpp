#pragma once
#include "GameObject.hpp"
#include "Platform.hpp"

class Enemy : public GameObject {
public:
    Enemy(const Vector2f& position) {
        shape.setSize({ 50, 50 });
        shape.setFillColor(Color::Cyan);
        shape.setPosition(position);
    }
    ~Enemy() {}
    void update(float deltaTime) override {}
    virtual void update(float deltaTime, const Platform& pl) {
        // gravity common to most enimies
        vertVelocity += gravity;
        sf::FloatRect bounds = shape.getGlobalBounds();
        if (!pl.isColliding(bounds)) {
            shape.move({ 0, vertVelocity * deltaTime });
            isGrounded = false;
        }
        else {
            vertVelocity = 0;
            isGrounded = true;
        }
    }
    void render(RenderWindow& window) override {
        window.draw(shape);
    }
    sf::Vector2f getPosition() const override {
        return shape.getPosition();
    }
protected:
    sf::RectangleShape shape;
    bool isGrounded = false;
    float speed = 100;
    float vertVelocity = 1;
    float gravity = 3;
};