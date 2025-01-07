#include "Monopoly_Game.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Monopoly_Game w;
    w.show();
    return a.exec();
}
