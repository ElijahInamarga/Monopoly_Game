#include "Player.h"

Player::Player() {
	this->name = "NULL";
	this->color = "NUll";
	this->position = nullptr;
	this->budget = 0;
}

Player::Player(std::string name, std::string color, Node<Property>* position) {
	this->name = name;
	this->color = color;
	this->position = position;
	this->budget = 1500;
}

Player::~Player() {
	delete position;
	int numOfProperties = playerProperties.size();
	for (int i = 0; i < numOfProperties; i++) {
		delete playerProperties[i];
	}
}