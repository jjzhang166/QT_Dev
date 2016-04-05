#include <QCoreApplication>
#include <QString>
#include <QDebug>


// 2.4 Algorithms
void test_Algorithms()
{
    qDebug()<<endl<<"2.4 test_Algorithms"<<endl;
    double a=-19.3,b=9.7;
    double c=qAbs(a);        //c=19.3
    double max=qMax(b,c);    //max=c=19.3

    int bn=qRound(b);        //bn=10
    int cn=qRound(c);        //cn=19

    qDebug()<<"a="<<a;
    qDebug()<<"b="<<b;
    qDebug()<<"c=qAbs(a)= "<<c;
    qDebug()<<"qMax(b,c)= "<<max;
    qDebug()<<"bn=qRound(b)= "<<bn;
    qDebug()<<"cn=qRound(c)= "<<cn;

    qSwap(bn,cn);
    qDebug()<<"qSwap(bn,cn)："<<"bn="<<bn<<" cn="<<cn;
}

void test_QRegexp()
{
    qDebug()<<endl<<"2.4 test_QRegexp"<<endl;
    QString pattern("(.*)=(.*)");
    QRegExp rx(pattern);

    QString str("a=100");
    int pos = str.indexOf(rx);              // 0, position of the first match.
                                            // Returns -1 if str is not found.
                                            // You can also use rx.indexIn(str);
    qDebug() << pos;
    if ( pos >= 0 )
    {
        qDebug() << rx.matchedLength();     // 5, length of the last matched string
                                            // or -1 if there was no match
        qDebug() << rx.capturedTexts();     // QStringList("a=100", "a", "100"),
                                            //   0: text matching pattern
                                            //   1: text captured by the 1st ()
                                            //   2: text captured by the 2nd ()

        qDebug() << rx.cap(0);              // a=100, text matching pattern
        qDebug() << rx.cap(1);              // a, text captured by the nth ()
        qDebug() << rx.cap(2);              // 100,

        qDebug() << rx.pos(0);              // 0, position of the nth captured text
        qDebug() << rx.pos(1);              // 0
        qDebug() << rx.pos(2);              // 2
    }
}
int main(int argc, char *argv[])
{
    test_Algorithms();
    test_QRegexp();

    return 0;
}
