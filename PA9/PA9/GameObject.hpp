
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class GameObject {
public:
	virtual void update(float deltaTime) = 0;
	virtual void render(sf::RenderWindow& window) = 0;
    virtual sf::Vector2f getPosition() const = 0;
    virtual sf::FloatRect getBounds() const = 0;
    virtual bool destroyed() const { return isDestroyed; }
    virtual void destroy() { isDestroyed = true; }
private:
    bool isDestroyed = false;
};