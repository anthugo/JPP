#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"
#include <QObject>

Player::Player(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    bulletsound =  new QMediaPlayer;
    bulletsound->setMedia(QUrl("qrc:/sounds/Resources/wololo.mp3"));

    setPixmap(QPixmap(":/images/Resources/skyrano.jpg").scaled(100,100));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        if (pos().x() > 0) {
            setPos(x()-10,y());
        }
    }
    else if (event->key() == Qt::Key_Right) {
        if (pos().x() + 100 < scene()->width()) {
            setPos(x()+10,y());
        }
    }
    else if (event->key() == Qt::Key_Up) {
        if (pos().y() > 0) {
            setPos(x(),y()-10);
        }
    }
    else if (event->key() == Qt::Key_Down) {
        if (pos().y() + 100 < scene()->height()) {
            setPos(x()+10,y()+10);
        }
    }
    else if (event->key() == Qt::Key_Space) {
        Bullet  *bullet = new Bullet();
        bullet->setPos(x()+20,y());
        scene()->addItem(bullet);
        if (bulletsound->state() == QMediaPlayer::PlayingState) {
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState) {
            bulletsound->play();
        }
    }
}

void Player::spawn()
{
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
