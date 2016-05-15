#include "time.h"
#include <QTimer>
#include <QFont>
#include "game.h"

#include <QDebug>

extern Game *game ;

Time::Time(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    // initialize the time to 30sec
    ctn = 30;


    // draw the text
    setPlainText(" 剩下時間 : "+QString::number(ctn)+" 秒");
    setDefaultTextColor(Qt::black);
    setFont(QFont("Noto Sans T Chinese bold",20));

}

void Time::countdown()
{
    ctn--;
    setPlainText(" 剩下時間 : "+QString::number(ctn)+" 秒"); // Time: 29
    if(ctn < 1) {
        return;
    }
}

void Time::restart()
{
    ctn = 30;
    setPlainText(" 剩下時間 : "+QString::number(ctn)+" 秒"); // Time: 30
}

int Time::getTime()
{
    return ctn;
}

void Time::pause()
{

}
