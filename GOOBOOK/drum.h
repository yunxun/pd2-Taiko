#ifndef DRUM_H
#define DRUM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Drum: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Drum(QGraphicsItem * parent = 0);

public slots:
    void check();
};

#endif // DRUM_H
