#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    score = 0;
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",20));
    refresh();
}

void Score::increase()
{
    score++;
    refresh();
}

int Score::getScore()
{
    return score;
}

void Score::refresh()
{
    setPlainText(QString("Score : ") + QString::number(score));
}
