#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>
#include <Game.h>

extern Game *game;

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
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for (int i = 0,n = colliding_items.size();i < n;i++) {
        if(typeid(*(colliding_items[i])) == typeid(Player)) {
            game->health->decrease();
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    setPos(x(),y()+5);
    if (pos().y() > scene()->height()) {
        game->health->decrease();
        scene()->removeItem(this);
        this->deleteLater();
    }
}
