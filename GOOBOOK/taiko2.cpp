#include "taiko2.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QKeyEvent>

Taiko2::Taiko2(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    x_speed = 10;
    //set random x position (like random time spawn)
    setPos(1280+qrand()%800,700);

    // set the picture
    setPixmap(QPixmap(":/google.png"));

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer

    timer->start(25);
}

void Taiko2::move()
{

    if(x() > 5 ) {
        setPos(x() - x_speed , y());
    }
    else {
        //emit noteDestroyed();
        scene()->removeItem(this);
        delete this;
    }

}
