#include <QCoreApplication>
#include "ccounter.h"
#include <QDebug>

// http://blog.csdn.net/newthinker_wei/article/details/22785763
int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    CCounter a, doubleA;
    QObject::connect(&a, SIGNAL(valueChanged(int)),
                     &doubleA, SLOT(setValue(int)));

    qDebug()<<a.value();
    qDebug()<<doubleA.value();
    a.setValue(12);  // a.value() == 12, b.value() == 12
    qDebug()<<a.value();
    qDebug()<<doubleA.value();

    return app.exec();
}
