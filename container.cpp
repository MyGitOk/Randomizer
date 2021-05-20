#include "Container.h"

Participant::Participant(QObject *parent) : QObject(parent)
{

}

QString Participant::getFullInfo() const
{
    return QString("Full information from Structure %1").arg(m_number);
}

Container::Container(QObject *parent) : QObject(parent)
{

}

QString Container::getFullInfo() const
{
    return QString("Full information from Container %1").arg(m_number);
}

int Container::number() const
{
    return m_number;
}

QString Container::name() const
{
    return m_name;
}

void Container::setNumber(int number)
{
    if (m_number == number)
        return;

    m_number = number;
    emit numberChanged(m_number);
}

void Container::setMessage(QString name)
{
    if (m_name == name)
        return;

    m_name = name;
    emit messageChanged(m_name);
}
