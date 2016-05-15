#ifndef DRUM2_H
#define DRUM2_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Drum2: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Drum2(QGraphicsItem * parent = 0);

public slots:
    void check();
};

#endif // DRUM2_H
