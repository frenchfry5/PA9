#include "Player.hpp"

#include "Player.hpp"

Player::Player(const sf::Vector2f& startPos) {
    shape.setSize({ 40.f, 60.f });
    shape.setFillColor(sf::Color::Cyan);
    shape.setPosition(startPos);
}

void Player::update() {
    handleInput();

    // Apply gravity
    velocity.y += gravity * 1.f / 60.f;

    // Move
    shape.move(velocity * (1.f / 60.f)); // assuming 60 FPS, use deltaTime in real projects
}

void Player::render(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::Vector2f Player::getPosition() const {
    return shape.getPosition();
}

sf::FloatRect Player::getBounds() const {
    return shape.getGlobalBounds();
}

void Player::handleInput() {
    velocity.x = 0.f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        velocity.x -= moveSpeed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        velocity.x += moveSpeed;
    }

    // Jump (very basic)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        velocity.y = -350.f;
    }
}
