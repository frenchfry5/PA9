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

bool Enemy::isColliding(const FloatRect& bounds) const
{
    for (size_t x = 0; x < grid.size(); x++) {
        for (size_t y = 0; y < grid[x].size(); y++) {
            if (grid[x][y] == 1) {
                sf::FloatRect tileRect(sf::Vector2f(x * tileSize, y * tileSize), sf::Vector2f(tileSize, tileSize));
                if (bounds.findIntersection(tileRect)) {
                    return true;
                }
            }
        }
    }
    return false;
}

void Enemy::update(float deltaTime, const Map& map, Player& player)
{
    //move left
    FloatRect nextPos = mShape.getGlobalBounds();
    nextPos.position.x -= mSpeed * deltaTime;
    if (!map.isColliding(nextPos)) {
        mShape.move({ -(mSpeed * deltaTime) , 0 });
    }

    //stand still for a moment
    Sleep(2500);

    //move right
    FloatRect nextPos = mShape.getGlobalBounds();
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
