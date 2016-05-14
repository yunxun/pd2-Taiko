#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "score.h"
#include "taiko.h"
#include "play.h"
#include "time.h"
#include "pause.h"


class Game: public QGraphicsView
{
public:
    Game(QWidget * parent=0);
    // objects
    QGraphicsScene * scene;
    Play * play;
    Score * score;
    Time * mytime;
    Pause * pause;
    //member function
    void gameOver();
    void restart();

};

#endif // GAME_H
