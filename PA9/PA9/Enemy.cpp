#include "Enemy.hpp"

Enemy::Enemy(const Vector2f& position)
{
    this->mShape.setScale({50.f, 50.f});
    mShape.setFillColor(Color::Red);
    mShape.setPosition(position);

}

Enemy::~Enemy()
{
}

void Enemy::render(RenderWindow& window)
{
    window.draw(this->mShape);
}


void Enemy::update(float deltaTime, const Map& map)
{
    FloatRect nextPos;

    //move left
    nextPos = mShape.getGlobalBounds();
    nextPos.position.x -= mSpeed * deltaTime;
    if (!map.isColliding(nextPos)) {
        mShape.move({ -(mSpeed * deltaTime) , 0 });
    }

    //stand still for a moment
    Sleep(2500);

    //move right
    nextPos = mShape.getGlobalBounds();
    nextPos.position.x += mSpeed * deltaTime;
    if (!map.isColliding(nextPos)) {
        mShape.move({ mSpeed * deltaTime , 0 });
    }


    //gravity
    if (!map.isColliding(this->mShape.getGlobalBounds())) {
        // gravity as in falling
        this->mShape.move({ 0, this->mVertVelocity * deltaTime });
    }
    else {
        this->mVertVelocity = 0;
         this->mIsGrounded = true;
    }

}

Vector2f Enemy::getPosition() const
{
    return this->mShape.getPosition();
}

FloatRect Enemy::getBounds() const
{
    return this->mShape.getGlobalBounds();
}
