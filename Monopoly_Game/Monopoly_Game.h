#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Monopoly_Game.h"
#include "CircularLinkedList.h"
#include "Property.h"
#include "Player.h"
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
    const int NUM_OF_PROPERTIES = 20; // Start counts as a property
    const int NUM_OF_SLOTS = 20;
    const int MAX_ROLL = 12;
    const int START_BONUS = 250;

    int numOfPropertiesLeft;
    int numOfPlayers;
    int currentPlayerIndex;
    Ui::Monopoly_GameClass* ui;
    CircularLinkedList<Property> board;
    vector<Property*> propertyList;
    vector<QTextBrowser*> slotsList;
    vector<Player*> playerList;
    vector<QTextBrowser*> playerTextboxList;
    vector<vector<QLabel*>> possiblePlayerLocationsList;
    Player* currentPlayer;

private slots:
    void on_inputGo_clicked();
    void on_rollButton_clicked();
    void on_pushYes_clicked();
    void on_pushNo_clicked();
    void on_noMoneyOkButton_clicked();
};