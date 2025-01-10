#include "Property.h"

Property::Property() {
    this->propertyName = "NULL";
    this->value = NULL;
}

Property::Property(string propertyName, int value) {
    this->propertyName = propertyName;
    this->value = value;
    this->bought = false;
}

Property::Property(string propertyName, bool cantBuy) {
    this->propertyName = propertyName;
    this->bought = true;
    this->value = 0;
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