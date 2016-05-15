#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QMediaPlayer>

 QMediaPlayer *bgm;
 Game * game;
 QTimer * timerm;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1280,840);

    // make/connect a timer to count down
    timerm = new QTimer();
    connect(timerm,SIGNAL(timeout()),this,SLOT(replay()));

    // start the timer
    timerm->start(96500);

    //set bgm
    bgm = new QMediaPlayer();
    bgm->setMedia(QUrl("qrc:/sound/Facebook.wav"));
    bgm->play();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_start_clicked()
{
    this->hide();
    bgm->stop();
    game = new Game();
    game->show();

}

void MainWindow::on_exit_clicked()
{
    this->close();
}
void MainWindow::replay()
{
   bgm->play();
}
