#ifndef TAIKO_H
#define TAIKO_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Taiko :public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Taiko(QGraphicsItem * parent=0);
    double x_speed;

public slots:
    void move();
};

#endif // TAIKO_H
