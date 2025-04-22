#include "Platform.hpp"

Platform::Platform(const Vector2f& size, const Vector2f& position, bool movement)
{
	this->mCanMove = movement;
	this->mIsDangerous = false;
	this->mColor = Color::White;
	this->mShape.setSize(size);
	this->mShape.setPosition(position);
	this->mShape.setFillColor(mColor);
	
}

Platform::~Platform()
{
}

sf::FloatRect Platform::getBounds() const
{
	return this->mShape.getGlobalBounds();
}
