#pragma once
#include "GameObject.hpp"
#include "Platform.hpp"

class Enemy : public GameObject {
public:
    Enemy() {

    }
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
        bounds.position.y += 1;
        if (!pl.isColliding(bounds)) {
            shape.move({ 0, vertVelocity * deltaTime });
            isGrounded = false;
        }
        else {
            vertVelocity = 0;
            isGrounded = true;
        }
    }
    virtual void render(RenderWindow& window) override {
        window.draw(shape);
    }
    sf::Vector2f getPosition() const override {
        return shape.getPosition();
    }
    FloatRect getBounds() const override {
        return shape.getGlobalBounds();
    }
    //void LoadFromImage(sf::Image& image) {
    //    const float tileSize = 55;
    //    grid.clear();
    //    grid = vector(image.getSize().x, vector(image.getSize().y, 0));

    //    for (size_t x = 0; x < grid.size(); x++) {
    //        for (size_t y = 0; y < grid[x].size(); y++) {
    //            Color colorPixel = image.getPixel(sf::Vector2u(x, y));
    //            if (colorPixel == Color::Magenta) {
    //                cout << "Bug" << endl;
    //                grid[x][y] = 5; // 1 for Bug
    //                /*inline constexpr Color Color::Magenta(255, 0, 255);*/
    //            }
    //        }
    //    }
    //}
protected:
    vector <vector<int>> grid;
    sf::RectangleShape shape;
    bool isGrounded = false;
    float speed = 100;
    float vertVelocity = 1;
    float gravity = 3;
};