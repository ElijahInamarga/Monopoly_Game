#include "Monopoly_Game.h"

Monopoly_Game::Monopoly_Game(QWidget* parent) : QMainWindow(parent), ui(new Ui::Monopoly_GameClass()) {
    ui->setupUi(this);

    Property* prop1 = new Property("Hotel", 10000);
    Property* prop2 = new Property("Villa", 7000);
    Property* prop3 = new Property("Grocery Store", 5000);
    Property* prop4 = new Property("Park", 6000);
    Property* prop5 = new Property("House", 3000);
    Property* prop6 = new Property("School", 15000);
    Property* prop7 = new Property("Apartment", 4000);
    Property* prop8 = new Property("Mansion", 10000);
    Property* prop9 = new Property("University", 20000);
    Property* prop10 = new Property("Bank", 8000);
    Property* prop11 = new Property("Airport", 18000);
    Property* prop12 = new Property("Convenience Store", 4500);
    Property* prop13 = new Property("Dealership", 12500);
    Property* prop14 = new Property("Mega Mall", 21500);
    Property* prop15 = new Property("Spa", 5500);
    Property* prop16 = new Property("Computer Store", 4500);
    Property* prop17 = new Property("Taco Shop", 3400);
    Property* prop18 = new Property("Itallian Restaurant", 3250);
    Property* prop19 = new Property("99cent Store", 1500);
    Property* prop20 = new Property("Mall", 15500);

    board.insertAtTail(*prop1);
    board.insertAtTail(*prop2);
    board.insertAtTail(*prop3);
    board.insertAtTail(*prop4);
    board.insertAtTail(*prop5);
    board.insertAtTail(*prop6);
    board.insertAtTail(*prop7);
    board.insertAtTail(*prop8);
    board.insertAtTail(*prop9);
    board.insertAtTail(*prop10);
    board.insertAtTail(*prop11);
    board.insertAtTail(*prop12);
    board.insertAtTail(*prop13);
    board.insertAtTail(*prop14);
    board.insertAtTail(*prop15);
    board.insertAtTail(*prop16);
    board.insertAtTail(*prop17);
    board.insertAtTail(*prop18);
    board.insertAtTail(*prop19);
    board.insertAtTail(*prop20);
       
    ui->textStart->setText(QString::fromStdString(prop1->getName()));

    delete prop1;
    delete prop2;
    delete prop3;
    delete prop4;
    delete prop5;
    delete prop6;
    delete prop7;
    delete prop8;
    delete prop9;
    delete prop10;
    delete prop11;
    delete prop12;
    delete prop13;
    delete prop14;
    delete prop15;
    delete prop16;
    delete prop17;
    delete prop18;
    delete prop19;
    delete prop20;
}

Monopoly_Game::~Monopoly_Game() {
    delete ui;
}
