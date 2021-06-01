#ifndef CONTAINER_H
#define CONTAINER_H

#include <QObject>

struct Participant : public QObject
{
    explicit Participant (QString _name, QObject *parent = nullptr);

    int m_number;
    QString m_name;

private:
    Q_OBJECT
    // Сможем обращаться к полям из QML
    // параметр MEMBER указывает, что имеется возможность работать с этим полем и отслеживать его изменение в QML
    Q_PROPERTY(int number MEMBER m_number)
    Q_PROPERTY(QString name MEMBER m_name)

public:
    // А также вызвать в QML этот метод
    Q_INVOKABLE QString getFullInfo() const;
};

#endif // CONTAINER_H
