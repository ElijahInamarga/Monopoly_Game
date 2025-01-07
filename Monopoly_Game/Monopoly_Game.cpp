#include "Monopoly_Game.h"

Monopoly_Game::Monopoly_Game(QWidget *parent) : QMainWindow(parent), ui(new Ui::Monopoly_GameClass()) {
    ui->setupUi(this);
    ui->textStart->setText("Start");
}

Monopoly_Game::~Monopoly_Game() {
    delete ui;
}
