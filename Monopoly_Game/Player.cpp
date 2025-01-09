#include "Player.h"

Player::Player() {
	this->name = "NULL";
	this->color = "NUll";
	this->position = nullptr;
}

Player::Player(std::string name, std::string color, Property* position) {
	this->name = name;
	this->color = color;
	this->position = position;
}

Player::~Player() {
	delete position;
}