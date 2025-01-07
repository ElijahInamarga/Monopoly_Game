#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Monopoly_Game.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Monopoly_GameClass; };
QT_END_NAMESPACE

class Monopoly_Game : public QMainWindow {
    Q_OBJECT

public:
    Monopoly_Game(QWidget *parent = nullptr);
    ~Monopoly_Game();
private:
    Ui::Monopoly_GameClass *ui;

private slots:

};
