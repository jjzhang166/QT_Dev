#include "ccounter.h"

CCounter::CCounter(QObject *parent) : QObject(parent), m_value(0)
{

}
int CCounter::value() const
{
    return m_value;
}

void CCounter::setValue(int value)
{
    if (value != m_value)
    {
        m_value = value;
        emit valueChanged(value*2);
    }
}
