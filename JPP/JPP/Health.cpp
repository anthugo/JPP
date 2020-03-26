#include "Health.h"
#include <QFont>
#include <Game.h>
#include <QtCore>

extern Game *game;

Health::Health(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    health = 10;
    setPos(x()+660,0);
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",20));
    refresh();
}

void Health::decrease()
{
    health--;
    refresh();
}

int Health::getHealth()
{
    return health;
}

void Health::refresh()
{
    setPlainText(QString("Health : ") + QString::number(health));
}
