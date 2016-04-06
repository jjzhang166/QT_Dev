#include <QDateTime>
#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize( 200, 120 );
    setMaximumSize( 200, 120 );
    this->datelabel = new QLabel(this);
    this->timer = new QTimer(parent);
    connect(this->timer, SIGNAL(timeout()), this, SLOT(slottimedone()));

    this->slottimedone();
    this->timer->start(1000);
}

Widget::~Widget()
{

}

void Widget::slottimedone()
{
    QDateTime dt = QDateTime::currentDateTime();
    QString strDateTime = dt.toString();
    this->datelabel->setText(strDateTime);
}
