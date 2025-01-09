#pragma once

#include <iostream>
#include "Property.h"
#include "Node.h"

class Player {

public:
	std::string name;
	std::string color;
	Node<Property>* position;

	Player();
	Player(std::string name, std::string color, Node<Property>* position);
	~Player();
};

