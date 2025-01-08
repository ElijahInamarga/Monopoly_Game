#pragma once

#include <iostream>
#include <string>

using namespace std;

class Property {
public:
    string propertyName;
    int value;

    Property();
    Property(string propertyName, int value);
    bool isEqual(Property other) const;
    void print() const;
};

