#pragma once

#include <iostream>
#include <Property.h>

class Player {
public:
	std::string name;
	std::string color;
	Property* position;

	Player();
	Player(std::string name, std::string color, Property* position);
	~Player();
};

