#include "Game.h"
#include <QWidget>
#include <QtGui>
#include <QGraphicsScene>
#include "Player.h"
#include <QGraphicsProxyWidget>
#include <QGraphicsView>
#include <QTimer>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QImage>


Game::Game(QWidget *parent)
{
    scene = new QGraphicsScene();
    player = new Player(nullptr);

    setBackgroundBrush(QBrush(QImage(":/images/Resources/back.jpg")));


    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene->setSceneRect(0,0,800,600);
    setScene(scene);

    //player->setRect(0,0,100,100);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    player->setPos(width()/2,height()- 100);
    scene->addItem(player);

    score = new Score();
    scene->addItem(score);

    health = new Health();
    scene->addItem(health);

    QTimer *timer = new QTimer;
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(1500);

    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/Resources/wololo.mp3"));
    playlist->addMedia(QUrl("qrc:/sounds/Resources/jdg_song.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer *music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();

    //music->setMedia(QUrl("qrc:/sounds/Resources/jdg_song.mp3"));
    //music->play();

    show();
}
