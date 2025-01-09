#include "Monopoly_Game.h"

Monopoly_Game::Monopoly_Game(QWidget* parent) : QMainWindow(parent), ui(new Ui::Monopoly_GameClass()) {
    ui->setupUi(this);
    currentPlayerIndex = 0;

    // Initialize list of properties
    propertyList.push_back(new Property("Start", 0));
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

    // Initialize list of UI elements
    slotsList.push_back(ui->text1);
    slotsList.push_back(ui->text2);
    slotsList.push_back(ui->text3);
    slotsList.push_back(ui->text4);
    slotsList.push_back(ui->text5);
    slotsList.push_back(ui->text6);
    slotsList.push_back(ui->text7);
    slotsList.push_back(ui->text8);
    slotsList.push_back(ui->text9);
    slotsList.push_back(ui->text10);
    slotsList.push_back(ui->text11);
    slotsList.push_back(ui->text12);
    slotsList.push_back(ui->text13);
    slotsList.push_back(ui->text14);
    slotsList.push_back(ui->text15);
    slotsList.push_back(ui->text16);
    slotsList.push_back(ui->text17);
    slotsList.push_back(ui->text18);
    slotsList.push_back(ui->text19);
    slotsList.push_back(ui->text20);

    // Initialize list of right-side UI elements
    playerTextboxList.push_back(ui->player1Text);
    playerTextboxList.push_back(ui->player2Text);
    playerTextboxList.push_back(ui->player3Text);
    playerTextboxList.push_back(ui->player4Text);

    // Display properties onto UI
    ui->noMoneyOkButton->hide();
    ui->textBuyQuestion->hide();
    ui->pushYes->hide();
    ui->pushNo->hide();
    ui->playerRollText->hide();
    ui->rollButton->hide(); 
    ui->player1Text->hide();
    ui->player2Text->hide();
    ui->player3Text->hide();
    ui->player4Text->hide();
    ui->rollResult->setStyleSheet("background-color: white;");
    ui->rollResult->hide();
    slotsList[0]->setText("Start");

    for(int i = 1; i < numOfProperties; i++) {
        QString propertyName = QString::fromStdString(propertyList[i]->getName());
        QString propertyValue = QString::number(propertyList[i]->getValue());
        QString str = propertyName + "\n\nPrice: $" + propertyValue;
        slotsList[i]->setText(str);
    }

    for (int i = 0; i < numOfProperties; i++) {
        board.insertAtTail(*propertyList[i]);
    }

    // Delete properties 
    for (int i = 0; i < numOfProperties; i++) {
        delete propertyList[i];
    }

    currentPlayer = nullptr;
}

Monopoly_Game::~Monopoly_Game() {
    delete ui;
     
    // Delete ui elements
    for(int i = 0; i < numOfSlots; i++) {
        delete slotsList[i];
    }

    // Delete player text boxes
    for (int i = 0; i < 4; i++) {
        delete playerTextboxList[i];
    }
}

// Before game begins
void Monopoly_Game::on_inputGo_clicked() {
    std::string listOfColors[] = {"blue", "red", "green", "orange"};

    ui->inputGo->hide();
    ui->inputSelection->hide();
    ui->inputQuestion->hide();

    // Initialize list of players and reveal appropriate player text boxes
    numOfPlayers = (ui->inputSelection->currentIndex()) + 1;
    for(int i = 0; i < numOfPlayers; i++) {
        std::string str = "Player " + std::to_string(i + 1);
        playerList.push_back(new Player(str, listOfColors[i], board.getHeadNode()));

        // Intialize player text boxes
        QString playerName = QString::fromStdString(playerList[i]->name);
        QString playerBudget = QString::number(playerList[i]->budget);
        playerTextboxList[i]->setText(playerName + "\n\n$" + playerBudget + "\n\nProperties: \n");
        
        QString playerTextBoxColor = QString::fromStdString(playerList[i]->color);
        playerTextboxList[i]->setStyleSheet("background-color: " + playerTextBoxColor + ";");
        playerTextboxList[i]->show();
    }

    currentPlayer = playerList[0];
    QString str = QString::fromStdString(currentPlayer->name + " rolls!");
    ui->playerRollText->setText(str);
    ui->playerRollText->show();
    ui->rollButton->show();
}

void Monopoly_Game::on_rollButton_clicked() {
    // First roll click
    std::srand(std::time(nullptr));
    int randomValue = std::rand() % 12 + 1;
    ui->rollButton->hide();
    ui->playerRollText->hide();
    ui->rollResult->display(QString::number(randomValue));
    ui->rollResult->show();

    // Move player
    for(int i = 0; i < randomValue; i++) {
        currentPlayer->position = currentPlayer->position->nextNode;
    }

    // Reveal player on board
    int index = board.search(currentPlayer->position->data);
    QString str = slotsList[index]->toPlainText() + "\n " + QString::fromStdString(currentPlayer->name);
    slotsList[index]->setText(str);
    ui->textBuyQuestion->setText(QString::fromStdString(currentPlayer->name) + ", would you like to buy: \n" + 
                                 QString::fromStdString(currentPlayer->position->data.getName()) + " for $" + 
                                 QString::number(currentPlayer->position->data.getValue()));
    ui->textBuyQuestion->show();
    ui->pushYes->show();
    ui->pushNo->show();
}

void Monopoly_Game::on_pushYes_clicked() {
    ui->pushYes->hide();
    ui->pushNo->hide();

    if(currentPlayer->budget < currentPlayer->position->data.getValue()) {
        ui->textBuyQuestion->setText("You don't have enough money");
        ui->noMoneyOkButton->show();
    } else {
        // Update player information
        currentPlayer->playerProperties.push_back(&currentPlayer->position->data);
        currentPlayer->budget -= currentPlayer->position->data.getValue();

        // Recolor slot on board 
        int index = board.search(currentPlayer->position->data);
        slotsList[index]->setStyleSheet("background-color: " + QString::fromStdString(currentPlayer->color) + ";");
        QString playerName = QString::fromStdString(currentPlayer->name);
        QString playerBudget = QString::number(currentPlayer->budget);
        
        // Update player text boxes
        QString currentPlayerProperties = " ";
        for(int i = 0; i < currentPlayer->playerProperties.size(); i++) {
            currentPlayerProperties += QString::fromStdString(currentPlayer->playerProperties[i]->getName()) + " \n";
        }

        playerTextboxList[currentPlayerIndex]->setText(playerName + "\n\n$" + playerBudget + "\n\nProperties: \n" + currentPlayerProperties);
        currentPlayerIndex = (currentPlayerIndex + 1) % numOfPlayers;
        currentPlayer->position->data.
        currentPlayer = playerList[currentPlayerIndex];   

        QString str = QString::fromStdString(currentPlayer->name + " rolls!");
        ui->textBuyQuestion->hide();
        ui->rollResult->hide();
        ui->playerRollText->setText(str);
        ui->playerRollText->show();
        ui->rollButton->show();
    }
}

void Monopoly_Game::on_pushNo_clicked() {
    currentPlayerIndex = (currentPlayerIndex + 1) % numOfPlayers;
    currentPlayer = playerList[currentPlayerIndex];

    ui->textBuyQuestion->hide();
    ui->pushYes->hide();
    ui->pushNo->hide();
    ui->rollResult->hide();

    QString str = QString::fromStdString(currentPlayer->name + " rolls!");
    ui->textBuyQuestion->hide();
    ui->rollResult->hide();
    ui->playerRollText->setText(str);
    ui->playerRollText->show();
    ui->rollButton->show();
}

void Monopoly_Game::on_noMoneyOkButton_clicked() {
    ui->noMoneyOkButton->hide();
    ui->textBuyQuestion->hide();
    ui->rollResult->hide();

    currentPlayerIndex = (currentPlayerIndex + 1) % numOfPlayers;
    currentPlayer = playerList[currentPlayerIndex];

    QString str = QString::fromStdString(currentPlayer->name + " rolls!");
    ui->playerRollText->setText(str);
    ui->playerRollText->show();
    ui->rollButton->show();
}
