#include "mainwidget.h"
#include "ui_mainwidget.h"

#include <QWidget>
#include <QFrame>
#include <QPushButton>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    QPushButton *button =  new QPushButton("Bouton");

    setWindowTitle("JPP");

}

MainWidget::~MainWidget()
{
    delete ui;
}

