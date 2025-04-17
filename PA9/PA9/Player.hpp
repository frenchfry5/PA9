#pragma once
#include "GameObject.hpp"

class Player : public GameObject {
private: 
    sf::RectangleShape shape;
    sf::Vector2f velocity;

    const float moveSpeed = 200.0f; 
    const float gravity = 800.0f;

public:

};