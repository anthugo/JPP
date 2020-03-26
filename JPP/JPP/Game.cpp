#include "Game.h"
#include <QWidget>
#include <QtGui>
#include <QGraphicsScene>
#include "Player.h"
#include <QGraphicsProxyWidget>
#include <QGraphicsView>
#include <QTimer>


Game::Game(QWidget *parent)
{
    scene = new QGraphicsScene();
    player = new Player();

    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene->setSceneRect(0,0,800,600);
    setScene(scene);

    player->setRect(0,0,100,100);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    player->setPos(width()/2,height()- player->rect().height());
    scene->addItem(player);

    score = new Score();
    scene->addItem(score);

    health = new Health();
    scene->addItem(health);

    QTimer *timer = new QTimer;
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    show();
}
