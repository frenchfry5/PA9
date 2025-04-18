#include "Platform.hpp"

Platform::Platform(bool movement)
{
	this->mCanMove = movement;
	this->mIsDangerous = false;
	this->color = Color::White;
}

Platform::~Platform()
{
}
