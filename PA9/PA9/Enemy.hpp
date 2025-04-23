#pragma once
#include "GameObject.hpp"
#include "Player.hpp"

class Enemy : public GameObject
{
public:
	Enemy(const Vector2f& position);
	~Enemy();

    void render(RenderWindow& window) override;
    
    void update(float deltaTime, const Map& map) override;

    Vector2f getPosition() const override;

    FloatRect getBounds() const override;


private:
    CircleShape mShape;
    bool mIsGrounded = false;
    float mSpeed = 200;
    float mVertVelocity = 1;
    float mGravity = 3;
};

