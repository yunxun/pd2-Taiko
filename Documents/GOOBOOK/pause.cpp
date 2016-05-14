#include "pause.h"
#include "game.h"
#include <QGraphicsScene>

extern Game *game;

Pause::Pause(QGraphicsItem *parent)
{
    // set the picture
    setPixmap(QPixmap(":/pause1.png"));
    setScale(1);
    setPos(50,50);
}

void Pause::mousePressEvent(QGraphicsSceneMouseEvent *event)
{/*
    if((event->scenePos().x() >= pause ->pos().x() && event->scenePos().x() <= pause ->pos().x()+btn_w) && (event->scenePos().y() >= btn_start->pos().y() && event->scenePos().y() <= btn_start->pos().y()+btn_h))
    {



    }

*/
}
