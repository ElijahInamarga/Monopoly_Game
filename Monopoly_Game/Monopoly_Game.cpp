#include "Monopoly_Game.h"

Monopoly_Game::Monopoly_Game(QWidget* parent) : QMainWindow(parent), ui(new Ui::Monopoly_GameClass()) {
    ui->setupUi(this);
    currentPlayerIndex = 0;

    // Initialize list of properties
    propertyList.push_back(new Property("Start"));
    propertyList.push_back(new Property("Hotel", 1000, 100));
    propertyList.push_back(new Property("Villa", 700, 70));
    propertyList.push_back(new Property("Park", 600, 60));
    propertyList.push_back(new Property("House", 300, 30));
    propertyList.push_back(new Property("School", 1500, 150));
    propertyList.push_back(new Property("Mansion", 1000, 100));
    propertyList.push_back(new Property("Apartment", 400, 40));
    propertyList.push_back(new Property("University", 2000, 200));
    propertyList.push_back(new Property("Bank", 800, 80));
    propertyList.push_back(new Property("Airport", 1800, 180));
    propertyList.push_back(new Property("Book Store", 450, 45));
    propertyList.push_back(new Property("Dealership", 1250, 125));
    propertyList.push_back(new Property("Mega Mall", 2150, 215));
    propertyList.push_back(new Property("Spa", 550, 55));
    propertyList.push_back(new Property("Computer Store", 450, 45));
    propertyList.push_back(new Property("Taco Shop", 340, 35));
    propertyList.push_back(new Property("Sushi Restaurant", 325, 30));
    propertyList.push_back(new Property("Mall", 1550, 155));
    propertyList.push_back(new Property("Grocery Store", 500, 50));

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

    // Initialize vector of possible player locations
    possiblePlayerLocationsList.push_back({ ui->label_3, ui->label, ui->label_2 });
    possiblePlayerLocationsList.push_back({ ui->label_6, ui->label_5, ui->label_4 });
    possiblePlayerLocationsList.push_back({ ui->label_7, ui->label_8, ui->label_9 });
    possiblePlayerLocationsList.push_back({ ui->label_10, ui->label_11, ui->label_12 });
    possiblePlayerLocationsList.push_back({ ui->label_13, ui->label_14, ui->label_15 });
    possiblePlayerLocationsList.push_back({ ui->label_16, ui->label_17, ui->label_18 });
    possiblePlayerLocationsList.push_back({ ui->label_19, ui->label_20, ui->label_21 });
    possiblePlayerLocationsList.push_back({ ui->label_22, ui->label_23, ui->label_24 });
    possiblePlayerLocationsList.push_back({ ui->label_25, ui->label_26, ui->label_27 });
    possiblePlayerLocationsList.push_back({ ui->label_28, ui->label_29, ui->label_30 });
    possiblePlayerLocationsList.push_back({ ui->label_31, ui->label_32, ui->label_33 });
    possiblePlayerLocationsList.push_back({ ui->label_34, ui->label_35, ui->label_36 });
    possiblePlayerLocationsList.push_back({ ui->label_37, ui->label_38, ui->label_39 });
    possiblePlayerLocationsList.push_back({ ui->label_40, ui->label_41, ui->label_42 });
    possiblePlayerLocationsList.push_back({ ui->label_43, ui->label_44, ui->label_45 });
    possiblePlayerLocationsList.push_back({ ui->label_46, ui->label_47, ui->label_48 });
    possiblePlayerLocationsList.push_back({ ui->label_49, ui->label_50, ui->label_51 });
    possiblePlayerLocationsList.push_back({ ui->label_52, ui->label_53, ui->label_54 });
    possiblePlayerLocationsList.push_back({ ui->label_55, ui->label_56, ui->label_57 });
    possiblePlayerLocationsList.push_back({ ui->label_58, ui->label_59, ui->label_60 });

    // Set up initial UI
    for (int i = 0; i < NUM_OF_SLOTS; i++) {
        for (int j = 0; j < 3; j++) {
            possiblePlayerLocationsList[i][j]->hide();
        }
    }
    ui->noMoneyOkButton->hide();
    ui->textBuyQuestion->hide();
    ui->pushYes->hide();
    ui->pushNo->hide();
    ui->playerRollText->hide();
    ui->rollButton->hide(); 
    ui->player1Text->hide();
    ui->player2Text->hide();
    ui->player3Text->hide();
    ui->rollResult->hide();
    slotsList[0]->setText("Start");

    for(int i = 1; i < NUM_OF_PROPERTIES; i++) {
        QString propertyName = QString::fromStdString(propertyList[i]->getName());
        QString propertyValue = QString::number(propertyList[i]->getValue());
        QString str = propertyName + "\n\nPrice: $" + propertyValue;
        slotsList[i]->setText(str);
    }

    for (int i = 0; i < NUM_OF_PROPERTIES; i++) {
        board.insertAtTail(*propertyList[i]);
    }

    // Delete properties 
    for (int i = 0; i < NUM_OF_PROPERTIES; i++) {
        delete propertyList[i];
    }

    currentPlayer = nullptr;
}

Monopoly_Game::~Monopoly_Game() {
    delete ui;
    delete currentPlayer;

    // Delete ui elements
    for(int i = 0; i < NUM_OF_SLOTS; i++) {
        delete slotsList[i];
    }

    // Delete player text boxes
    for (int i = 0; i < 3; i++) {
        delete playerTextboxList[i];
    }

    // Delete player labels
    for (int i = 0; i < NUM_OF_SLOTS; i++) {
        for (int j = 0; j < 3; j++) {
            delete possiblePlayerLocationsList[i][j];
        }
    }
}

// Before game begins
void Monopoly_Game::on_inputGo_clicked() {
    std::string listOfColors[] = { "blue", "orange", "green" };

    ui->inputGo->hide();
    ui->inputSelection->hide();
    ui->inputQuestion->hide();

    // Initialize list of players and reveal appropriate player text boxes
    numOfPlayers = (ui->inputSelection->currentIndex()) + 1;

    // Reveal appropriate players on the start property
    switch (numOfPlayers) {
    case 3:
        possiblePlayerLocationsList[0][2]->show();
    case 2:
        possiblePlayerLocationsList[0][1]->show();
    case 1:
        possiblePlayerLocationsList[0][0]->show();
        break;
    }

    for (int i = 0; i < numOfPlayers; i++) {
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
    QString str = QString::fromStdString(currentPlayer->name + "'s turn to roll");
    ui->playerRollText->setText(str);
    ui->playerRollText->show();
    ui->rollButton->show();
}

void Monopoly_Game::on_rollButton_clicked() {
    // After roll
    std::srand(std::time(nullptr));
    int randomValue = std::rand() % MAX_ROLL + 1;
    ui->rollButton->hide();
    ui->playerRollText->hide();
    if(randomValue == 8 || randomValue == 11)
        ui->rollResult->setText("You rolled an " + QString::number(randomValue) + "!");
    else
        ui->rollResult->setText("You rolled a " + QString::number(randomValue) + "!");
    ui->rollResult->show();

    // Move player
    for (int i = 0; i < randomValue; i++) {
        currentPlayer->position = currentPlayer->position->nextNode;
        if (currentPlayer->position->data.isEqual(Property("Start"))) {
            currentPlayer->budget += 200;

            // Update player text box
            QString playerName = QString::fromStdString(currentPlayer->name);
            QString playerBudget = QString::number(currentPlayer->budget);
            QString currentPlayerProperties = "";
            for (int i = 0; i < currentPlayer->playerProperties.size(); i++) {
                currentPlayerProperties += " " + QString::fromStdString(currentPlayer->playerProperties[i]->getName()) + "\n";
            }
            playerTextboxList[currentPlayerIndex]->setText(playerName + "\n\n$" + playerBudget + "\n\nProperties: \n" + currentPlayerProperties);
        }
    }

    int index = board.search(currentPlayer->position->data);
    for (int i = 0; i < NUM_OF_SLOTS; i++) {
        possiblePlayerLocationsList[i][currentPlayerIndex]->hide();
    }
    possiblePlayerLocationsList[index][currentPlayerIndex]->show();

    // Determine if property can be bought
    if (currentPlayer->position->data.isEqual(Property("Start"))) {
        currentPlayerIndex = (currentPlayerIndex + 1) % numOfPlayers;
        currentPlayer = playerList[currentPlayerIndex];

        ui->textBuyQuestion->hide();
        ui->pushYes->hide();
        ui->pushNo->hide();
        ui->rollResult->hide();

        QString str = QString::fromStdString(currentPlayer->name + "'s turn to roll");
        ui->textBuyQuestion->hide();
        ui->rollResult->hide();
        ui->playerRollText->setText(str);
        ui->playerRollText->show();
        ui->rollButton->show();
    } else if (currentPlayer->position->data.isBought()) {
        // Penalize currentPlayer and update currentPlayer's player text box
        currentPlayer->budget -= currentPlayer->position->data.getPenalty();
        QString playerName = QString::fromStdString(currentPlayer->name);
        QString playerBudget = QString::number(currentPlayer->budget);
        QString currentPlayerProperties = "";
        for (int i = 0; i < currentPlayer->playerProperties.size(); i++) {
            currentPlayerProperties += " " + QString::fromStdString(currentPlayer->playerProperties[i]->getName()) + "\n";
        }
        playerTextboxList[currentPlayerIndex]->setText(playerName + "\n\n$" + playerBudget + "\n\nProperties: \n" + currentPlayerProperties);

        // Award property owner and update owner's player text box
        playerList[currentPlayer->position->data.getOwnerIndex()]->budget += currentPlayer->position->data.getPenalty();
        playerName = QString::fromStdString(playerList[currentPlayer->position->data.getOwnerIndex()]->name);
        playerBudget = QString::number(playerList[currentPlayer->position->data.getOwnerIndex()]->budget);
        currentPlayerProperties = "";
        for (int i = 0; i < playerList[currentPlayer->position->data.getOwnerIndex()]->playerProperties.size(); i++) {
            currentPlayerProperties += " " + QString::fromStdString(playerList[currentPlayer->position->data.getOwnerIndex()]->playerProperties[i]->getName()) + "\n";
        }
        playerTextboxList[currentPlayer->position->data.getOwnerIndex()]->setText(playerName + "\n\n$" + playerBudget + "\n\nProperties: \n" + currentPlayerProperties);

        // Move to next player
        currentPlayerIndex = (currentPlayerIndex + 1) % numOfPlayers;
        currentPlayer = playerList[currentPlayerIndex];

        ui->textBuyQuestion->hide();
        ui->pushYes->hide();
        ui->pushNo->hide();
        ui->rollResult->hide();

        QString str = QString::fromStdString(currentPlayer->name + "'s turn to roll");
        ui->textBuyQuestion->hide();
        ui->rollResult->hide();
        ui->playerRollText->setText(str);
        ui->playerRollText->show();
        ui->rollButton->show();
    } else {
        QString buyQuestion = QString::fromStdString(currentPlayer->name) + ", would you like to buy: \n" +
                              QString::fromStdString(currentPlayer->position->data.getName()) + " for $" +
                              QString::number(currentPlayer->position->data.getValue());
        ui->textBuyQuestion->setText(buyQuestion + "?");
        ui->textBuyQuestion->show();
        ui->pushYes->show();
        ui->pushNo->show();
    }
}

void Monopoly_Game::on_pushYes_clicked() {
    ui->pushYes->hide();
    ui->pushNo->hide();

    if (currentPlayer->budget < currentPlayer->position->data.getValue()) {
        ui->textBuyQuestion->setText("You don't have enough money");
        ui->noMoneyOkButton->show();
    } else {
        // Update player information
        currentPlayer->playerProperties.push_back(&currentPlayer->position->data);
        currentPlayer->budget -= currentPlayer->position->data.getValue();
        currentPlayer->position->data.setBought();
        currentPlayer->position->data.setOwnerIndex(currentPlayerIndex);

        // Recolor slot on board 
        int index = board.search(currentPlayer->position->data);
        slotsList[index]->setStyleSheet("background-color: " + QString::fromStdString(currentPlayer->color) + ";");
        
        // Update player text boxes
        QString playerName = QString::fromStdString(currentPlayer->name);
        QString playerBudget = QString::number(currentPlayer->budget);
        QString currentPlayerProperties = "";
        for(int i = 0; i < currentPlayer->playerProperties.size(); i++) {
            currentPlayerProperties += " " + QString::fromStdString(currentPlayer->playerProperties[i]->getName()) + "\n";
        }
        playerTextboxList[currentPlayerIndex]->setText(playerName + "\n\n$" + playerBudget + "\n\nProperties: \n" + currentPlayerProperties);

        // Move to next player
        currentPlayerIndex = (currentPlayerIndex + 1) % numOfPlayers;
        currentPlayer = playerList[currentPlayerIndex];   

        QString str = QString::fromStdString(currentPlayer->name + "'s turn to roll");
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

    QString str = QString::fromStdString(currentPlayer->name + "'s turn to roll");
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

    QString str = QString::fromStdString(currentPlayer->name + "'s turn to roll");
    ui->playerRollText->setText(str);
    ui->playerRollText->show();
    ui->rollButton->show();
}
