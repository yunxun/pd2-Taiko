#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    // initialize the score to 0
    score = 0;

    // draw the text
    setPlainText(QString("目前得分: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::black);
    setFont(QFont("bold",16));
}

void Score::increase()
{
    setPlainText(QString("目前得分: ") + QString::number(score)); // Score: 1
    score++;
    setPlainText(QString("目前得分: ") + QString::number(score)); // Score: 1
}

int Score::getScore()
{
    return score;
}

void Score::restart()
{
    score = 0;
    setPlainText(QString("目前得分: ") + QString::number(score)); // Score: 0
}
