#ifndef PAUSE_H
#define PAUSE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Pause: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Pause(QGraphicsItem * parent = 0);

public slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // PAUSE_H
