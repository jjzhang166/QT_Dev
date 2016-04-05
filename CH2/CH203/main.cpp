#include "widget.h"
#include <QApplication>


// 2.3 QVariant类
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
