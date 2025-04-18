#pragma once
#include "GameObject.hpp"

class Player : public GameObject {
public:
    Player(const sf::Vector2f& position) {
        shape.setSize({ 50.f, 50.f });
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(position);
    }

    void update(float deltaTime) override {
        // up
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            shape.move({ 0, (vertVelocity * deltaTime) });
        }
        // left
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            shape.move({ -(speed * deltaTime) , 0 });
        }
        // right
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            shape.move({ speed * deltaTime , 0 });
        }
        
        // gravity as in falling
        vertVelocity += gravity;
        shape.move({ 0, vertVelocity * deltaTime });
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
    float vertVelocity = 0;
    float gravity = 3;

};
