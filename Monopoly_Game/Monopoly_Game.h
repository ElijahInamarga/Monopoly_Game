#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Monopoly_Game.h"
#include "CircularLinkedList.h"
#include "Property.h"
#include <iostream>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { 
    class Monopoly_GameClass; 
};
QT_END_NAMESPACE

class Monopoly_Game : public QMainWindow {
    Q_OBJECT

public:
    Monopoly_Game(QWidget* parent = nullptr);
    ~Monopoly_Game();

private:
    const int numOfProperties = 19;
    const int numOfSlots = 20;
    Ui::Monopoly_GameClass* ui;
    CircularLinkedList<Property> board;
    vector<Property*> propertyList;
    vector<QTextBrowser*> slotsList;
};
