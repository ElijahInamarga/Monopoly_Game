#pragma once

#include <iostream>

using namespace std;

class Property {
private:
    string propertyName;
    int value;
    int penalty;
    bool bought;
public:
    Property();
    Property(string propertyName, int value, int penalty);
    Property(string propertyName, bool cantBuy);
    bool isEqual(Property other) const;
    void print() const;
    string getName();
    int getValue();
    bool isBought();
    void setBought();
};

