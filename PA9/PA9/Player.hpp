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
        if (isKeyPressed(Key::W) && isGrounded) {
            sf::FloatRect nextPos = shape.getGlobalBounds();
            nextPos.position.y -= jump * deltaTime;
            if (!map.isColliding(nextPos)) {
                shape.move({ 0, -(jump * deltaTime) });

            }
        }
        // left
        if (isKeyPressed(Key::A)) {
            sf::FloatRect nextPos = shape.getGlobalBounds();
            nextPos.position.x -= speed * deltaTime;
            if (!map.isColliding(nextPos)) {
                shape.move({ -(speed * deltaTime) , 0 });
            }

        }
        // right
        if (isKeyPressed(Key::D)) {
            sf::FloatRect nextPos = shape.getGlobalBounds();
            nextPos.position.x += speed * deltaTime;
            if (!map.isColliding(nextPos)) {
                shape.move({ speed * deltaTime , 0 });
            }
        }
        vertVelocity += gravity;
       
        if (!map.isColliding(shape.getGlobalBounds())) {
            // gravity as in falling
            shape.move({ 0, vertVelocity * deltaTime });
        }
        else {
            vertVelocity = 0;
            isGrounded = true;
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
    bool isGrounded = false;
    float jump = 600;
    float speed = 200;
    float vertVelocity = 1;
    float gravity = 3;
};
