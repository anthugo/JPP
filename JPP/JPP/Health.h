#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QGraphicsItem>

class Health: public QGraphicsTextItem {
public:
    Health(QGraphicsItem *parent=nullptr);
    void decrease();
    int getHealth();
private:
    int health;
    void refresh();
};

#endif // HEALTH_H
