#ifndef FACTORY_H
#define FACTORY_H

#include <QObject>


class Factory : public QObject
{
    Q_OBJECT
public:
    explicit Factory(QObject *parent = nullptr);

    Q_INVOKABLE QObject* createContainer(); // Для создания контейнеров
    Q_INVOKABLE QObject* addParticipant(QString _participant); // Для создания структур
    //Q_INVOKABLE Participant* getParticipant(int index); // участник по индексу

private:
    int m_count {0};
    int m_structureCount {0};
};

#endif // FACTORY_H
