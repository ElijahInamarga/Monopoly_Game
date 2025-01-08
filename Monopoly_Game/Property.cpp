#include "Property.h"

Property::Property() {}

Property::Property(string propertyName, string propertyColor, int value, int rent) {
    this->propertyName = propertyName;
    this->propertyColor = propertyColor;
    this->value = value;
    this->rent = rent;
}

bool Property::isEqual(Property other) const {
    if (other.propertyName == this->propertyName
        && other.propertyColor == this->propertyColor
        && other.value == this->value
        && other.rent == this->rent) {
        return true;
    }
    return false;
}

void Property::print() const {
    cout << "[Name: " + propertyName << ", Color: " + propertyColor << ", Value: " << value << ", Rent: " << rent << "]";
}