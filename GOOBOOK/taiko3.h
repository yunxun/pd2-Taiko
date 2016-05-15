#ifndef TAIKO3_H
#define TAIKO3_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Taiko3:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Taiko3(QGraphicsItem * parent=0);
    double x_speed;

public slots:
    void move();
};

#endif // TAIKO3_H
