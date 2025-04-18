#include "Platform.hpp"

Platform::Platform(bool movement)
{
	this->mCanMove = movement;
	this->mIsDangerous = false;

}

Platform::~Platform()
{
}
