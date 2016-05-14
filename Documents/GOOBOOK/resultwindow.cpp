#include "resultwindow.h"
#include "ui_resultwindow.h"
#include <QLabel>
#include "game.h"

extern Game * game;;

ResultWindow::ResultWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResultWindow)
{
    ui->setupUi(this);
    setWindowTitle("RESULT");
    setWindowIcon(QIcon(":/Thumbs-Up.png"));
    setFixedSize(400,300);

    //copy score
    ss.score = game->score->score;
    ui->lcdNumber->display(ss.score);


}

ResultWindow::~ResultWindow()
{
    delete ui;
}

void ResultWindow::on_close_clicked()
{
    this->close();
    game->close();
    //scene->bgChange("exit");
}

void ResultWindow::on_retry_clicked()
{
    game->restart();
    //scene->bgChange("start");
    this->close();
}
