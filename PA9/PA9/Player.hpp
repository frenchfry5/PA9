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
            // check if any collision above
            sf::FloatRect nextPos = shape.getGlobalBounds();
            nextPos.position.y -= jump * deltaTime;
            // if there is no collision, then move player
            if (!map.isColliding(nextPos)) {
                shape.move({ 0, -(jump * deltaTime) });
            }
        }
        // left
        if (isKeyPressed(Key::A)) {
            // check if any collision to the left
            sf::FloatRect nextPos = shape.getGlobalBounds();
            nextPos.position.x -= speed * deltaTime;

            //shrink it a little so it cant detect the ground
            nextPos.position.y += 1;
            nextPos.position.y -= 2;

            // if there is no collision, then move player
            if (!map.isColliding(nextPos)) {
                shape.move({ -(speed * deltaTime) , 0 });
            }

        }
        // right
        if (isKeyPressed(Key::D)) {
            // check if any collision to the right
            sf::FloatRect nextPos = shape.getGlobalBounds();
            nextPos.position.x += speed * deltaTime;

            //shrink it a little so it cant detect the ground
            nextPos.position.y += 1;
            nextPos.position.y -= 2;
            // if there is no collision, then move player
            if (!map.isColliding(nextPos)) {
                shape.move({ speed * deltaTime , 0 });
            }
        }
        
       
        // if anything on the map is not colliding with the player, then the player must be in the air, so falling
        // else the player must be on the ground and not falling
        if (!map.isColliding(shape.getGlobalBounds())) {
            // gravity as in falling
            vertVelocity += gravity;
            shape.move({ 0, vertVelocity * deltaTime });
        }
        else {
            vertVelocity = 0;

            sf::FloatRect groundCheck = shape.getGlobalBounds();
            groundCheck.position.y += 1.0;
            isGrounded = map.isColliding(groundCheck);
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
