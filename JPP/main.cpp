#include "mainwidget.h"

#include <QApplication>
#include <QWidget>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsProxyWidget>
#include <QGraphicsView>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QGraphicsScene *scene = new QGraphicsScene();

    QGraphicsRectItem *rect = new QGraphicsRectItem();
    rect->setRect(0,0,100,100);

    scene->addItem(rect);

    QGraphicsView * view = new QGraphicsView(scene);

    view->show();

    //MainWidget w;
    //w.show();

    return app.exec();
}
