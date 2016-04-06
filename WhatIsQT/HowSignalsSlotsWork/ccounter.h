#ifndef CCOUNTER_H
#define CCOUNTER_H

#include <QObject>

class CCounter : public QObject
{
    Q_OBJECT
public:
    explicit CCounter(QObject *parent = 0);

    int value() const;

signals:
    void valueChanged(int newValue);

public slots:
    void setValue(int value);

private:
    int m_value;
};

#endif // CCOUNTER_H
