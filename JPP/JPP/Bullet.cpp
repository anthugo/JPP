#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"

extern Game *game;

Bullet::Bullet(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/Resources/assassin.jpg").scaled(60,50));
    setTransformOriginPoint(30,25);

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for (int i = 0,n = colliding_items.size();i < n;i++) {
        if(typeid(*(colliding_items[i])) == typeid(Enemy)) {
            game->score->increase();
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    setPos(x(),y()-10);
    setRotation(this->rotation()+20);
    if (pos().y()+50 < 0) {
        scene()->removeItem(this);
        this->deleteLater();
    }
}
