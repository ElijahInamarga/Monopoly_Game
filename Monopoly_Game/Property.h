#pragma once

#include <iostream>

using namespace std;

class Property {
private:
    string propertyName;
    int value;

public:
    Property();
    Property(string propertyName, int value);
    bool isEqual(Property other) const;
    void print() const;
    string getName();
    int getValue();
};

