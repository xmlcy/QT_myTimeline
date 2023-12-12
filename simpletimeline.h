#ifndef SIMPLETIMELINE_H
#define SIMPLETIMELINE_H

#include <QObject>
#include <QtQuick/QQuickPaintedItem>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
#include <vector>


class SimpleTimeline : public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:
    explicit SimpleTimeline(QObject *parent = nullptr);
    ~SimpleTimeline(); // 在析构函数中释放动态分配的内存

    void createAnimate(QObject *target, const QByteArray &propertyName, int msecs);
    void addFrame(QObject *target, const QByteArray &propertyName, qreal step, const QVariant &value);

    void start();

private slots:
    void onAnimationFinished() {
        // Optionally perform cleanup or take additional actions when all animations finish
        // For example, you can emit a signal to notify the main application
        emit animationFinished();
    }
signals:
    void animationFinished();
private:
    QParallelAnimationGroup parGroup;
    std::vector<QSequentialAnimationGroup*> seqGroup;
    std::vector<QPropertyAnimation*> animation;

};

#endif // SIMPLETIMELINE_H