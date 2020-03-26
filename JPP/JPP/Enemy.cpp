#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>

Enemy::Enemy()
{
    setRect(0,0,100,100);
    int random_number = rand() % 700;
    setPos(random_number,0);

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move()
{
    setPos(x(),y()+5);
    if (pos().y()+rect().height() > scene()->height()) {
        scene()->removeItem(this);
        this->deleteLater();
    }
}
