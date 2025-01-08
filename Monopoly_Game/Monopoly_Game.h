#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Monopoly_Game.h"
#include "CircularLinkedList.h"
#include "Property.h"

QT_BEGIN_NAMESPACE
namespace Ui { 
    class Monopoly_GameClass; 
};
QT_END_NAMESPACE

class Monopoly_Game : public QMainWindow {
    Q_OBJECT

public:
    Monopoly_Game(QWidget *parent = nullptr);
    ~Monopoly_Game();

private:
    Ui::Monopoly_GameClass *ui;
    CircularLinkedList<Property> board;
    Property* prop1;
    Property* prop2;
    Property* prop3;
    Property* prop4;
    Property* prop5;
    Property* prop6;
    Property* prop7;
    Property* prop8;
    Property* prop9;
    Property* prop10;
    Property* prop11;
    Property* prop12;
    Property* prop13;
    Property* prop14;
    Property* prop15;
    Property* prop16;
    Property* prop17;
    Property* prop18;
    Property* prop19;
    Property* prop20;
};
