#include <QCoreApplication>
#include <QString>
#include <QDebug>


// 2.2 容器类
//      a. QWidget和QDialog等不能存储在容器中，（可存储的必须是：有默认构造函数、拷贝构造函数和赋值操作运算符函数）。
//      b. 支持Java、STL两种风格的迭代器。
//      c. 能通STL的算法一起使用，自称效率更胜一筹。

// QList、QLinkedList、QVector
//  QT东西很奇怪，上面的三个分别对应的是stl中的（没有、list、vector），有点别扭。QList是一个数组与链表的结合体（http://blog.csdn.net/jjjlike/article/details/7922972）。
//  QT推荐使用QList，没有特殊性能等要求的情况下，就用它吧，例子也只有它。java方式的不太了解，也不大打算经常用，只是把代码放上去，不解释了。
void test_QList()
{
    qDebug()<<endl<<"2.2.1 test_QContainer"<<endl;
    QList<int> list;
    list<<1<<2<<3<<4<<5;

    // java 调用方式（只读的）：QListIterator
    qDebug()<<" java 调用方式（只读的）";
    QListIterator<int> i(list);
    for(;i.hasNext();)
    {
        qDebug()<<i.next();
        //*i = 5;
    }

    // java 调用方式（可读写的）：QMutableListIterator
    qDebug()<<" java 调用方式（可读写的）";
    {
        QList<int> list;
        QMutableListIterator<int> i(list);
        for(int j=0;j<10;++j)
            i.insert(j);
        for(i.toFront();i.hasNext();)
            qDebug()<<i.next();
        for(i.toBack();i.hasPrevious();)
        {
            if(i.previous()%2==0)
                i.remove();
            else
                i.setValue(i.peekNext()*10);
        }
        for(i.toFront();i.hasNext();)
            qDebug()<<i.next();
    }

    // c++ 调用方式
    qDebug()<<endl<<" c++ 调用方式";
    {
        QList<int> list;
        for(int j=0;j<10;j++)
            list.insert(list.end(),j);
        QList<int>::iterator i;
        for(i=list.begin();i!=list.end();++i)
        {
           qDebug()<<(*i);
           *i=(*i)*10;
        }
        QList<int>::const_iterator ci;
        for(ci=list.constBegin();ci!=list.constEnd();++ci)
            qDebug()<<*ci;
    }
}

void test_QMap_QHash()
{
    // QMap
    qDebug()<<endl<<"QMap_java"<<endl;
    {
        QMap<QString,QString> map;
        map.insert("beijing","111");
        map.insert("shanghai","021");
        map.insert("nanjing","025");
        QMapIterator<QString,QString> i(map);
        for(;i.hasNext();)
            qDebug()<<"  "<<i.key()<<"  "<<i.next().value();
        QMutableMapIterator<QString,QString> mi(map);
        if(mi.findNext("111"))
            mi.setValue("010");
        QMapIterator<QString,QString> modi(map);
        qDebug()<<"  ";
        for(;modi.hasNext();)
            qDebug()<<" "<<modi.key()<<"  "<<modi.next().value();
    }
    // QMap_stl
    qDebug()<<endl<<"QMap_stl"<<endl;
    {
        QMap<QString,QString> map;
        map.insert("beijing","111");
        map.insert("shanghai","021");
        map.insert("nanjing","025");
        QMap<QString,QString>::const_iterator i;
        for(i=map.constBegin();i!=map.constEnd();++i)
            qDebug()<<"  "<<i.key()<<"  "<<i.value();

        QMap<QString,QString>::iterator mi;
        mi=map.find("beijing");
        if(mi!=map.end())
            mi.value()="010";
        QMap<QString,QString>::const_iterator modi;
        qDebug()<<"  ";
        for(modi=map.constBegin();modi!=map.constEnd();++modi)
            qDebug()<<"  "<<modi.key()<<"  "<<modi.value();
    }
}

int main(int argc, char *argv[])
{
    test_QList();

    test_QMap_QHash();

    return 0;
}
