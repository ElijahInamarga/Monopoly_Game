#pragma once

#include <iostream>

using namespace std;

class Property {
private:
    string propertyName;
    int value;
    int penalty;
    bool bought;
    int ownerIndex;

public:
    Property();
    Property(std::string propertyName);
    Property(string propertyName, int value, int penalty);
    bool isEqual(Property other) const;
    void print() const;
    string getName();
    int getValue();
    bool isBought();
    void setBought();
    int getPenalty();
    void setOwnerIndex(int ownerIndex);
    int getOwnerIndex();
};

