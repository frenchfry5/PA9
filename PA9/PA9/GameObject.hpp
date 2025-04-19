
#pragma once
#include <SFML/Graphics.hpp>
#include "ourLibrary.h"

class GameObject {
public:
	virtual void update(float deltaTime) = 0;
	virtual void render(RenderWindow& window) = 0;
    virtual Vector2f getPosition() const = 0;
    virtual FloatRect getBounds() const = 0;
    virtual bool destroyed() const { return isDestroyed; }
    virtual void destroy() { isDestroyed = true; }
private:
    bool isDestroyed = false;
};