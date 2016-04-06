#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QTimer>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void slottimedone();

private:
    QLabel  *datelabel;
    QTimer  *timer;
};

#endif // WIDGET_H
