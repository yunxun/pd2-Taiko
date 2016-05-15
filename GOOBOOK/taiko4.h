#ifndef TAIKO4_H
#define TAIKO4_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Taiko4:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Taiko4(QGraphicsItem * parent=0);
    double x_speed;

public slots:
    void move();
};
#endif // TAIKO4_H
