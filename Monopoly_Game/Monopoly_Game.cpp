#include "Monopoly_Game.h"

Monopoly_Game::Monopoly_Game(QWidget* parent) : QMainWindow(parent), ui(new Ui::Monopoly_GameClass()) {
    ui->setupUi(this);

    // Initialize list of properties
    propertyList.push_back(new Property("Hotel", 1000));
    propertyList.push_back(new Property("Villa", 700));
    propertyList.push_back(new Property("Park", 600));
    propertyList.push_back(new Property("House", 300));
    propertyList.push_back(new Property("School", 1500));
    propertyList.push_back(new Property("Mansion", 1000));
    propertyList.push_back(new Property("Apartment", 400));
    propertyList.push_back(new Property("University", 2000));
    propertyList.push_back(new Property("Bank", 800));
    propertyList.push_back(new Property("Airport", 1800));
    propertyList.push_back(new Property("Convenience Store", 450));
    propertyList.push_back(new Property("Dealership", 1250));
    propertyList.push_back(new Property("Mega Mall", 2150));
    propertyList.push_back(new Property("Spa", 550));
    propertyList.push_back(new Property("Computer Store", 450));
    propertyList.push_back(new Property("Taco Shop", 340));
    propertyList.push_back(new Property("Itallian Restaurant", 325));
    propertyList.push_back(new Property("Mall", 1550));
    propertyList.push_back(new Property("Grocery Store", 500));

    // Initialize list of board slots
    slotsList.push_back(ui->textStart);
    slotsList.push_back(ui->textBrowser_top_2);
    slotsList.push_back(ui->textBrowser_top_3);
    slotsList.push_back(ui->textBrowser_top_4);
    slotsList.push_back(ui->textBrowser_top_5);
    slotsList.push_back(ui->textBrowser_top_6);
    slotsList.push_back(ui->textBrowser_bot_1);
    slotsList.push_back(ui->textBrowser_bot_2);
    slotsList.push_back(ui->textBrowser_bot_3);
    slotsList.push_back(ui->textBrowser_bot_4);
    slotsList.push_back(ui->textBrowser_bot_5);
    slotsList.push_back(ui->textBrowser_bot_6);
    slotsList.push_back(ui->textBrowser_left_1);
    slotsList.push_back(ui->textBrowser_left_2);
    slotsList.push_back(ui->textBrowser_left_3);
    slotsList.push_back(ui->textBrowser_left_4);
    slotsList.push_back(ui->textBrowser_right_1);
    slotsList.push_back(ui->textBrowser_right_2);
    slotsList.push_back(ui->textBrowser_right_3);
    slotsList.push_back(ui->textBrowser_right_4);

    // Display properties onto UI
    slotsList[0]->setText("Start");
    for (int i = 0; i < numOfProperties; i++) {
        QString propertyName = QString::fromStdString(propertyList[i]->getName());
        QString propertyValue = QString::number(propertyList[i]->getValue());
        QString str = propertyName + "\n\nPrice: $" + propertyValue;
        slotsList[i + 1]->setText(str);
    }
}

Monopoly_Game::~Monopoly_Game() {
    delete ui;

    // Delete properties 
    for (int i = 0; i < numOfProperties; i++) {
        delete propertyList[i];
    }

    // Delete slots
    for (int i = 0; i < numOfSlots; i++) {
        delete slotsList[i];
    }
}
