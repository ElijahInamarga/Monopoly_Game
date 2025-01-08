#pragma once

#include <iostream>
#include <string>

using namespace std;

class Property {
public:
    string propertyName;
    string propertyColor;
    int value;
    int rent;

    Property();
    Property(string propertyName, string propertyColor, int value, int rent);
    bool isEqual(Property other) const;
    void print() const;
};

