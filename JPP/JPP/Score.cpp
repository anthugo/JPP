#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    score = 0;
    setPlainText(QString("Score : ") + QString::number(score));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",20));
}

void Score::increase()
{
    score++;
}

int Score::getScore()
{
    return score;
}
