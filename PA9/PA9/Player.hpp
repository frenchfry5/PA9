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
    void update(float deltaTime, const Platform& pl, const vector<Bug>& bugs) {
        // up
        if (isKeyPressed(Key::W) && isGrounded) {
            // check if any collision above
            sf::FloatRect nextPos = shape.getGlobalBounds();
            nextPos.position.y -= jump * deltaTime;
            nextPos.position.y += .5;

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
        // apply friction
        horizVelocity *= friction;
        if (std::abs(horizVelocity) < 0.01f) horizVelocity = 0;

        // horizontal movement with collision
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
        else {
            vertVelocity = 1;
            isGrounded = true;
            for (const auto& bug : bugs) {
                if (this->getBounds().findIntersection(bug.getBounds())) {
                    isDead = true;
                    break;
                }
            }
        }
        int tileType = pl.getTileType(shape.getGlobalBounds());

        switch (tileType) {
        case 1: // normal solid block
            speed = 60;
            isGrounded = true;
            /*cout << "Normal block" << endl;*/
            break;
        case 2: // lava
            isDead = true;
            /*cout << "Lava block" << endl;*/
            break;
        case 3: // ice
            speed = 100;
            /*cout << "Ice block" << endl;*/
            break;
        case 4: // slime
            isGrounded = false;
            speed = 60;
            vertVelocity = -jump * 1.5f;
            shape.move({ 0, vertVelocity * deltaTime });
            break;
            /*cout << "Slime block" << endl;*/
        case 5: // victory
            Victory = true;
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
        Victory = false;
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
    void LoadFromImage(sf::Image& image) {
        //grid.clear();
        //grid = vector(image.getSize().x, vector(image.getSize().y, 0));

        //for (size_t x = 0; x < grid.size(); x++) {
        //    for (size_t y = 0; y < grid[x].size(); y++) {
        //        Color colorPixel = image.getPixel(sf::Vector2u(x, y));
        //        if (colorPixel == Color::Black) {
        //            grid[x][y] = 1; // 1 for block
        //        }
        //        if (colorPixel == Color::Red) {
        //            grid[x][y] = 2; // 2 for lava
        //        }
        //        if (colorPixel == Color::Blue) {
        //            grid[x][y] = 3; // for Ice
        //        }
        //        if (colorPixel == Color::Green) {
        //            grid[x][y] = 4; // for Slime or bouncy
        //        }
        //    }
        //}
    }
    bool checkVictory() {
        return Victory;
    }
private:
    sf::RectangleShape shape;
    bool isGrounded = false;
    bool isDead = false;
    bool Victory = false;
    float horizVelocity = 0;
    float friction = 0.8;
    float jump = 700;
    float speed = 60;
    float vertVelocity = 1;
    float gravity = 3;
};
