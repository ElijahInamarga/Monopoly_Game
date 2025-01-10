#include "Property.h"

Property::Property() {
    this->propertyName = "NULL";
    this->value = NULL;
    this->bought = false;
    this->penalty = NULL;
}

Property::Property(std::string propertyName) {
    this->propertyName = propertyName;
    this->value = 0;
    this->bought = false;
    this->penalty = 0;
}

Property::Property(string propertyName, int value, int penalty) {
    this->propertyName = propertyName;
    this->value = value;
    this->bought = false;
    this->penalty = penalty;
}

bool Property::isEqual(Property other) const {
    if (other.propertyName == this->propertyName
        && other.value == this->value) {
        return true;
    }
    return false;
}

void Property::print() const {
    cout << "[Name: " + propertyName << ", Value: " << value << "]";
}

string Property::getName() {
    return this->propertyName;
}

int Property::getValue() {
    return this->value;
}

bool Property::isBought() {
    return this->bought;
}

void Property::setBought() {
    this->bought = true;
}

int Property::getPenalty() {
    return this->penalty;
}