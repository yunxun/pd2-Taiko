#ifndef PLAY_H
#define PLAY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Play:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Play(QGraphicsItem * parent=0);
    void timerstart();

public slots:
    void spawn();
    void timego();
    void keyPressEvent(QKeyEvent *event);
};

#endif // PLAY_H
