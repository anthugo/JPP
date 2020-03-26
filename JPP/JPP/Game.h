#ifndef GAME_H
#define GAME_H
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "Player.h"
#include "Score.h"

class Game : public QGraphicsView {
public:
    Game(QWidget *parent=nullptr);
private:
    QGraphicsScene *scene;
    Player *player;
    Score *score;
};

#endif // GAME_H
