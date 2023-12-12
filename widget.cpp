#include "widget.h"
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setGeometry(300, 300, 500, 300);

    button = new QPushButton("Animate");
    button->setParent(this);
    button->setGeometry(10, 10, 180, 80);

    QObject::connect(button, &QPushButton::clicked, [&]() {
        qDebug() << "button clicked";
        qDebug() << timeline;
        timeline->start();
    });

    timeline = new SimpleTimeline();

    timeline->createAnimate(this, "pos", 2000);
//    timeline->createAnimate(this, "size", 1000);
    timeline->addFrame(this, "pos", 0, QPoint(300, 300));
    timeline->addFrame(this, "pos", 0.2, QPoint(600, 300));
    timeline->addFrame(this, "pos", 0.5, QPoint(600, 600));
    timeline->addFrame(this, "pos", 1, QPoint(300, 300));



}

Widget::~Widget()
{
}

