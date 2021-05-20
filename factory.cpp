#include "Factory.h"

#include "Container.h"


Factory::Factory(QObject *parent) : QObject(parent)
{

}

QObject* Factory::createContainer()
{
    Container* container = new Container(this);
    container->setNumber(++m_count);
    container->setMessage(QString("Container %1").arg(m_count));
    return container;
}

QObject* Factory::addParticipant(const QString _participant)
{
    Participant* participant = new Participant(this);
    participant->m_number = ++m_structureCount;
    participant->m_name = _participant;
    return participant;
}

