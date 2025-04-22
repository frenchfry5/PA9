#include "Enemy.hpp"

Enemy::Enemy(const Vector2f& position)
{
    this->mShape.setSize({ 50.f, 50.f });
    mShape.setFillColor(Color::Red);
    mShape.setPosition(position);
}

Enemy::~Enemy()
{
}
