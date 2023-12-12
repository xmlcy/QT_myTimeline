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

    timeline->createAnimate(this, "pos", "posani", 3000);
    timeline->addFrame("posani", 0, 0, QPoint(300, 300));
    timeline->addFrame("posani", 0, 0.2, QPoint(600, 300));
    timeline->addFrame("posani", 0, 0.5, QPoint(600, 600));
    timeline->addFrame("posani", 0, 0.7, QPoint(300, 600));
    timeline->addFrame("posani", 0, 1, QPoint(300, 300));

    timeline->createAnimate(this, "size", "sizeani", 2000);
    timeline->addFrame("sizeani", 0, 0, QSize(500, 300));
    timeline->addFrame("sizeani", 0, 0.2, QSize(600, 300));
    timeline->addFrame("sizeani", 0, 0.5, QSize(600, 600));
    timeline->addFrame("sizeani", 0, 1, QSize(500, 300));



}

Widget::~Widget()
{
}

