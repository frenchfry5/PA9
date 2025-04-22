
#pragma once
#include "ourLibrary.h"


class GameObject {
public:
	virtual void update(float deltaTime) = 0;
	virtual void render(RenderWindow& window) = 0;
    virtual bool destroyed() const { return isDestroyed; }
    virtual void destroy() { isDestroyed = true; }
private:
    bool isDestroyed = false;
};