#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include "game.h"

extern Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QDesktopWidget wid;
    int screenW = 1280;
    int screenH = 840;
    w.setGeometry(wid.screen()->width()/2 - (screenW/2) , wid.screen()->height()/2 - (screenH/2) , screenW , screenH);

    w.setWindowTitle("GOOBOOK");
    w.setWindowIcon(QIcon(":/Thumbs-Up.png"));
    w.setFixedSize(screenW , screenH);

    return a.exec();
}

