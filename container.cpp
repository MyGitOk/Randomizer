#include "Container.h"

Participant::Participant(QString _name, QObject *parent) : QObject(parent), m_name(_name)
{

}

QString Participant::getFullInfo() const
{
    return QString("Full information from Structure %1").arg(m_number);
}

