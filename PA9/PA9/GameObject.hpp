
#pragma once
#include "ourLibrary.h"
#include "Map.hpp"

class GameObject {
public:
	virtual void update(float deltaTime, const Map& map) = 0;
	virtual void render(RenderWindow& window) = 0;
    virtual Vector2f getPosition() const = 0;
    virtual FloatRect getBounds() const = 0;
    virtual bool destroyed() const { return isDestroyed; }
    virtual void destroy() { isDestroyed = true; }
private:
    bool isDestroyed = false;
};