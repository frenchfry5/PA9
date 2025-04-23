#pragma once
#include "GameObject.hpp"
#include "Platform.hpp"
#include "Bug.hpp"

class Player : public GameObject {
public:


    Player(const Vector2f& position) {
        shape.setSize({ 50, 50 });
        shape.setFillColor(Color::Green);
        shape.setPosition(position);
    }

    void update(float deltaTime) override {

    }
    void update(float deltaTime, const Platform& pl, const Bug& bugs) {
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
        if (isKeyPressed(Key::A)) {
            horizVelocity -= speed * deltaTime;
        }
        if (isKeyPressed(Key::D)) {
            horizVelocity += speed * deltaTime;
        }
        // Apply friction
        horizVelocity *= friction;
        if (std::abs(horizVelocity) < 0.01f) horizVelocity = 0;

        // Horizontal movement with collision
        sf::FloatRect nextPos = shape.getGlobalBounds();
        nextPos.position.x += horizVelocity;
        nextPos.position.y -= 1;
        if (!pl.isColliding(nextPos)) {
            shape.move({ horizVelocity, 0 });
        }
        else {
            horizVelocity = 0;
        }

 
        // if anything on the map is not colliding with the player, then the player must be in the air, so falling
        // else the player must be on the ground and not falling
        if (!pl.isColliding(shape.getGlobalBounds())) {
            // gravity as in falling
            vertVelocity += gravity;
            shape.move({ 0, vertVelocity * deltaTime });
        }
        else if (this->isColliding(bugs)) {
            isDead = true;
        }
        else {
            vertVelocity = 1;
            isGrounded = true;
        }
        int tileType = pl.getTileType(shape.getGlobalBounds());

        switch (tileType) {
        case 1: // Normal solid block
            speed = 60;
            /*cout << "Normal block" << endl;*/
            break;
        case 2: // Lava
            speed = 60;
            /*cout << "Lava block" << endl;*/
            break;
        case 3: // Ice
            speed = 100;
            /*cout << "Ice block" << endl;*/
            break;
        case 4: // Slime
            isGrounded = false;
            vertVelocity = -jump * 1.5f;
            shape.move({ 0, vertVelocity * deltaTime });
            /*cout << "Slime block" << endl;*/
            break;
        }
    }
    void render(RenderWindow& window) override {
        window.draw(shape);
    }
    sf::Vector2f getPosition() const override {
        return shape.getPosition();
    }
    void resetState(Vector2f spawnPosition) {
        isDead = false;
        isGrounded = false;
        speed = 60;
        vertVelocity = 1;
        gravity = 3;
        shape.setPosition(spawnPosition);
    }

    bool isColliding(const Bug& bugs) const {
        if (shape.getGlobalBounds().findIntersection(bugs.getBounds())) {
            return true;
        }
        else return false;
    }
    FloatRect getBounds() const override {
        return shape.getGlobalBounds();
    }
    bool checkDead() const {
        return isDead;
    }

private:
    sf::RectangleShape shape;
    bool isGrounded = false;
    bool isDead = false;
    float horizVelocity = 0;
    float friction = 0.9;
    float jump = 700;
    float speed = 60;
    float vertVelocity = 1;
    float gravity = 3;
};
