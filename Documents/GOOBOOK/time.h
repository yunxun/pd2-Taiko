#ifndef TIME_H
#define TIME_H

#include <QGraphicsTextItem>

class Time: public QGraphicsTextItem
{
public:
    Time(QGraphicsItem * parent=0);
    int getTime();
    void countdown();
    void pause();
    int ctn;
    void restart();
};

#endif // TIME_H
