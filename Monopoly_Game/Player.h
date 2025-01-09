#pragma once

#include <iostream>
#include "Property.h"
#include "Node.h"
#include <vector>

class Player {

public:
	std::string name;
	std::string color;
	Node<Property>* position;
	int budget;
	vector<Property*> playerProperties;

	Player();
	Player(std::string name, std::string color, Node<Property>* position);
	~Player();
};

