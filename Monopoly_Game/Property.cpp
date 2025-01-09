#include "Property.h"

Property::Property() {
    this->propertyName = "NULL";
    this->value = NULL;
}

Property::Property(string propertyName, int value) {
    this->propertyName = propertyName;
    this->value = value;
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
    return bought;
}