#include <QCoreApplication>
#include <QString>
#include <QDebug>

#include <windef.h>
#include "VMProtectSDK.h"

// 2.1 字符串类
//      a. qt的调试输出，使用qDebug。
//      b. qDebug默认最后有换行了。
void test_QString()
{
    VMProtectBegin("test_QString");

    // 2.1.1 操作字符串
    //  a. 拼接，+，+=
    qDebug()<<endl<<"2.1.1 操作字符串";
    qDebug()<<endl<<"a. 拼接，+，+=";
    QString str1 = "Welcome ";
    str1 = str1 + "to you!";
    QString str2 = "Hello, ";
    str2 += "World!";
    qDebug()<<str1<<endl<<str2;

    // b. append
    qDebug()<<endl<<"b. append";
    str1 = "Welcome ";
    str2 = "to ";
    str1.append(str2);
    str1.append("you!");
    qDebug()<<str1;

    // c. 格式化：sprintf
    qDebug()<<endl<<"c. 格式化：sprintf";
    QString str;
    str.sprintf("%s", "Welcome ");
    qDebug()<<str;
    str.sprintf("%s", "to you! ");
    qDebug()<<str;
    str.sprintf("%s %s", "Welcome ",  "to you! ");
    qDebug()<<str;

    // d. 格式化：arg
    qDebug()<<endl<<"d. 格式化：arg";
    str = QString("%1 was born in %2").arg("John").arg(1982);
    qDebug()<<endl<<str;

    // e. insert,prepend,replace

    // f. trimmed,simplified
    qDebug()<<endl<<"f. trimmed,simplified";
    str = "  Welcome \t to \n you!   ";
    qDebug()<<str.trimmed();            // "Welcome \t to \n you!"
    qDebug()<<str.simplified();         // "Welcome to you!"
    // ***** 看上面的qDebug()<<str.trimmed()，输出结果已经把'\t'变成了'\\t'了，看来qDebug做了不少事儿。
    // 下面输出的则是Unicode的字符串，包含换行和tab。
    wprintf((wchar_t*)str.data());
    qDebug()<<endl;

    // 2.1.2 查询字符串数据
    qDebug()<<endl<<"2.1.2 查询字符串数据";
    //  1. startsWith
    qDebug()<<endl<<" 1. startsWith";
    str = "Welcome to you!";
    qDebug()<<str.startsWith("Welcome", Qt::CaseSensitive);
    qDebug()<<str.startsWith("you!", Qt::CaseSensitive);

    //  2. endsWith
    qDebug()<<endl<<" 2. endsWith";
    str = "Welcome to you!";
    qDebug()<<str.endsWith("Welcome", Qt::CaseSensitive);
    qDebug()<<str.endsWith("you!", Qt::CaseSensitive);

    // 3. contains
    qDebug()<<endl<<" 3. contains";
    str = "Welcome to you!";
    qDebug()<<str.contains("come", Qt::CaseSensitive);
    qDebug()<<str.contains("come_", Qt::CaseSensitive);

    // 4. 比较功能：operator<,<=,==,>=,>
    //      静态函数：localAwareCompare，基于本地字符集，平台相关的。
    //          compare，Unicode，可以指定大小写敏感。Qt::CaseSensitive

    // 2.1.3 字符串转换
    qDebug()<<endl<<"2.1.3 字符串转换";
    // 1. 数值型：toInt，toDouble，toFloat，toLong，toLongLong等等。
    qDebug()<<" 1. 数值型：toInt，toDouble，toFloat，toLong，toLongLong等等。";
    bool bOk;
    str = "10";
    qDebug()<<str.toInt(&bOk, 16);
    qDebug()<<str.toInt(&bOk, 8);

    // 字符编码
    str = "Welcome to you!";
    //qDebug()<<str.toAscii();        // QT5.0.1把这个函数取消掉了，可以用toLatin1这个函数
    QByteArray ba = str.toLatin1();
    qDebug()<<ba;
    ba.append("Hello,World!");
    qDebug()<<ba;
    qDebug()<<ba.data();

    str="我";
    qDebug()<<str.toLatin1();
    qDebug()<<str.toUtf8();
    qDebug()<<str.toLocal8Bit();


    // isNull,isEmpty()
    qDebug()<<QString().isNull();
    qDebug()<<QString().isEmpty();
    qDebug()<<QString("").isNull();
    qDebug()<<QString("").isEmpty();

    VMProtectEnd();
}

// 2.2 容器类
//      a. QWidget和QDialog等不能存储在容器中，（可存储的必须是：有默认构造函数、拷贝构造函数和赋值操作运算符函数）。
//      b. 支持Java、STL两种风格的迭代器。
//      c. 能通STL的算法一起使用，自称效率更胜一筹。
void test_QContainer()
{
//    VMProtectBegin("test_QContainer");
    VMProtectBegin(__FUNCTION__);

    qDebug()<<endl<<"2.2.1 test_QContainer"<<endl;
    QList<int> list;
    list<<1<<2<<3<<4<<5;

    // java 调用方式
    qDebug()<<" java 调用方式";
    QListIterator<int> i(list);
    for(;i.hasNext();)
        qDebug()<<i.next();
    // c++ 调用方式
    qDebug()<<endl<<" c++ 调用方式";
    QList<int>::iterator iter = list.begin();
    while(iter != list.end())
    {
        qDebug()<<*iter;
        ++iter;
    }

    VMProtectEnd();
}

int main(int argc, char *argv[])
{
//    test_QString();
    test_QContainer();

    return 0;
}
