#ifndef CONTAINER_H
#define CONTAINER_H

#include <QObject>

struct Participant : public QObject
{
    explicit Participant (QObject *parent = nullptr);

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

class Container : public QObject
{
    Q_OBJECT
    // Сможем обращаться к полям из QML
    Q_PROPERTY(int number READ number WRITE setNumber NOTIFY numberChanged)
    Q_PROPERTY(QString name READ name WRITE setMessage NOTIFY messageChanged)

public:
    explicit Container(QObject *parent = nullptr);

    // А также вызвать в QML этот метод
    Q_INVOKABLE QString getFullInfo() const;

    int number() const;
    QString name() const;

public slots:
    void setNumber(int number);
    void setMessage(QString message);

signals:
    void numberChanged(int number);
    void messageChanged(QString message);

private:
    int m_number;
    QString m_name;
};

#endif // CONTAINER_H
