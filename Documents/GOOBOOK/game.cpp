#include "game.h"
#include <QTimer>
#include "taiko.h"
#include <QGraphicsTextItem>
#include <QFont>
#include "resultwindow.h"
#include <QBrush>
#include <QImage>
#include <QLabel>
#include <QSound>
#include <QMediaPlayer>

QTimer * tt;
QMediaPlayer * music;

Game::Game(QWidget * parent)
{
    //creat a scene
    QImage bg;
    bg.load(":/bg3.jpg");
    bg = bg.scaled(1280,840);
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1280,840); // make the scene
    scene->setBackgroundBrush (bg);

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1280,840);


    // create the player
    play = new Play();
    // make the player focusable and set it to be the current focus
    play->setFlag(QGraphicsItem::ItemIsFocusable);
    play->setFocus();
    // add the player to the scene
    scene->addItem(play);

    //creat the score
    score = new Score();
    score->setPos(score->x()+150,score->y()+50);
    scene->addItem(score);

    //creat the time
    mytime = new Time();
    mytime->setPos(mytime->x()+150,mytime->y()+130);
    scene->addItem(mytime);

    // spawn taiko
    tt = new QTimer();
    QObject::connect(tt,SIGNAL(timeout()),play,SLOT(spawn()));
    tt->start(800);

    //bgm
    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/Holy Knight..mp3"));
    music->play();

}

void Game::gameOver()
{
    //stop timer and music
    tt->stop();
    music->stop();

    //creat a result window
    ResultWindow * rr = new ResultWindow();
    rr->show();
}

void Game::restart()
{
    //restart timer and music
    tt->start(1000);
    music->play();
    play->timerstart();

    //reset score and time
    score->restart();
    mytime->restart();

}
