#include "play.h"
#include <QGraphicsScene>
#include <QApplication>
#include <QKeyEvent>
#include <QTimer>
#include <Qtime>
#include "drum2.h"
#include "drum.h"
#include "taiko.h"
#include "time.h"
#include "taiko2.h"
#include "game.h"

#include <QDebug>
extern Game * game;

QTimer * timer;

Play::Play(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    // set the picture
    setPixmap(QPixmap(":/greenman.png"));
    setScale(1);
    setPos(60,700);





    // make/connect a timer to count down
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(timego()));

    // start the timer
    timer->start(1000);

}

void Play::timerstart()
{
    timer->start(1000);
}

void Play::spawn(){
    // create an taiko
    if(qrand()%2==0){
        Taiko * taiko = new Taiko();
        scene()->addItem(taiko);
    }
    else
    {
        Taiko2 * taiko2 = new Taiko2();
        scene()->addItem(taiko2);
    }
    /*
    else if(qrand()%4==2){
        Taiko3 * taiko3 = new Taiko3();
        scene()->addItem(taiko3);
    }
    else if(qrand()%4==3){
        Taiko4 * taiko4 = new Taiko4();
        scene()->addItem(taiko4);
    }*/
}


void Play::timego()
{
    game->mytime->countdown();

    if(game->mytime->ctn< 1) {
        timer->stop();
        game->gameOver();
    }
}

void Play::keyPressEvent(QKeyEvent *event){

    // drum taiko with F & G
    if (event->key() == Qt::Key_F)
    {
        Drum * drum = new Drum();
        drum->setPos(x(),y());
        scene()->addItem(drum);

        //play sound
       /* if(drumsound->state() == QMediaPlayer::PlayingState) {
            drumsound->setPosition(0);
        }
        else if (drumsound->state() == QMediaPlayer::StoppedState) {
            drumsound->play();
        }*/
    }
    else if (event->key() == Qt::Key_G)
    {
        Drum2 * drum2 = new Drum2();
        drum2->setPos(x(),y());
        scene()->addItem(drum2);

        //play sound
        /*if(drum2sound->state() == QMediaPlayer::PlayingState) {
            drum2sound->setPosition(0);
        }
        else if (drum2sound->state() == QMediaPlayer::StoppedState) {
            drum2sound->play();
        }*/
    }
    else if (event->key() == Qt::Key_Q)
    {
        qDebug()<<"you press Q! quit.";
        exit(0);
    }
}
