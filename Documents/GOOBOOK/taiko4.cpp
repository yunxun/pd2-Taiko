#include "taiko4.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QKeyEvent>

Taiko4::Taiko4(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    x_speed =0.08;
    //set random x position (like random time spawn)
    setPos(1280+qrand()%800,750);

    // set the picture
    setPixmap(QPixmap(":/chrome.png"));

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer

    timer->start(25);
}

void Taiko4::move()
{

    if(x() > 300) {
        setPos(x() - x_speed , y());
    }
    else {
        //emit noteDestroyed();
        scene()->removeItem(this);
        delete this;
    }

}
