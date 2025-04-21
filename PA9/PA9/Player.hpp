#pragma once
#include "GameObject.hpp"
#include "global.hpp"

class Player : public GameObject {
public:
    Player(const Vector2f& position) {
        shape.setSize({ 50.f, 50.f });
        shape.setFillColor(Color::Green);
        shape.setPosition(position);
    }

    void update(float deltaTime, const Map& map) override {
        // up
        if (isKeyPressed(Key::W)) {
            shape.move({ 0, -(speed * deltaTime) });
        }
        // left
        if (isKeyPressed(Key::A)) {
            shape.move({ -(speed * deltaTime) , 0 });
        }
        // right
        if (isKeyPressed(Key::D)) {
            shape.move({ speed * deltaTime , 0 });
        }

        // gravity as in falling
        

        if (!map.isColliding(shape.getGlobalBounds())) {
            vertVelocity += gravity;
            shape.move({ 0, vertVelocity * deltaTime });
        }
        else {
            vertVelocity = 0;
        }
    }
    void render(sf::RenderWindow& window) override {
        window.draw(shape);
    }
    sf::Vector2f getPosition() const override {
        return shape.getPosition();
    }

    sf::FloatRect getBounds() const override {
        return shape.getGlobalBounds();
    }

private:
    sf::RectangleShape shape;
    float speed = 200;
    float vertVelocity = 1;
    float gravity = 3;
};
