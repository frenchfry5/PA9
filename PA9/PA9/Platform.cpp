#include "Platform.hpp"

Platform::Platform(const Vector2f& size, const Vector2f& position, vector<Platform>& platformVector, bool movement)
{
	this->mCanMove = movement;
	this->mIsDangerous = false;
	this->mColor = Color::White;
	this->mShape.setSize(size);
	this->mShape.setPosition(position);
	this->mShape.setFillColor(mColor);
	
	platformVector.push_back(*this);
}

Platform::~Platform()
{
}

sf::FloatRect Platform::getBounds() const
{
	return this->mShape.getGlobalBounds();
}
