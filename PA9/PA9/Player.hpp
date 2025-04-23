#pragma once
#include "GameObject.hpp"
#include "Platform.hpp"

class Player : public GameObject {
public:


    Player(const Vector2f& position) {
        shape.setSize({ 50, 50 });
        shape.setFillColor(Color::Green);
        shape.setPosition(position);
    }

    void update(float deltaTime) override {

    }
    void update(float deltaTime, const Platform& pl) {
        // up
        if (isKeyPressed(Key::W) && isGrounded) {
            // check if any collision above
            sf::FloatRect nextPos = shape.getGlobalBounds();
            nextPos.position.y -= jump * deltaTime;

            // if there is no collision, then move player
            if (!pl.isColliding(nextPos)) {
                shape.move({ 0, -(jump * deltaTime) });
            }
        }
        // left
        if (isKeyPressed(Key::A)) {
            // check if any collision to the left
            sf::FloatRect nextPos = shape.getGlobalBounds();
            nextPos.position.x -= speed * deltaTime;
            nextPos.position.y += 1;
            nextPos.position.y -= 2;
            if (!pl.isColliding(nextPos)) {
                shape.move({ -(speed * deltaTime) , 0 });
            }

        }
        // right
        if (isKeyPressed(Key::D)) {
            // check if any collision to the right
            sf::FloatRect nextPos = shape.getGlobalBounds();
            nextPos.position.x += speed * deltaTime;
            nextPos.position.y += 1;
            nextPos.position.y -= 2;
            if (!pl.isColliding(nextPos)) {
                shape.move({ speed * deltaTime , 0 });
            }
        }

        vertVelocity += gravity;
        // if anything on the map is not colliding with the player, then the player must be in the air, so falling
        // else the player must be on the ground and not falling
        if (!pl.isColliding(shape.getGlobalBounds())) {
            // gravity as in falling
            shape.move({ 0, vertVelocity * deltaTime });
        }
        else {
            vertVelocity = 0;
            isGrounded = true;
        }
        int tileType = pl.getTileType(shape.getGlobalBounds());

        switch (tileType) {
        case 1: // Normal solid block
            cout << "Normal block" << endl;
            break;
        case 2: // Lava
            cout << "Lava block" << endl;
            break;
        case 3: // Ice
            speed = 600;
            cout << "Ice block" << endl;
            break;

        case 4: // Slime
            isGrounded = false;
            vertVelocity = -jump * 1.5f; 
            shape.move({ 0, vertVelocity * deltaTime });
            cout << "Slime block" << endl;
            break;
        default:
            speed = 200;
            break;
        }
        
    }
    void render(RenderWindow& window) override {
        window.draw(shape);
    }
    sf::Vector2f getPosition() const override {
        return shape.getPosition();
    }

private:
    sf::RectangleShape shape;
    bool isGrounded = false;
    float jump = 750;
    float speed = 200;
    float vertVelocity = 1;
    float gravity = 3;
};
