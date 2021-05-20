#ifndef FILE_H
#define FILE_H

#include <QObject>
#include <QFile>
#include <QDebug>
#include <ctime>

class File : public QObject
{
    Q_OBJECT
public:
    explicit File(QObject *parent = nullptr);

    Q_INVOKABLE int countParticipants(); // количество участников
    Q_INVOKABLE QString getParticipantByIndex(int index);
    Q_INVOKABLE QString getRandomParticipant();

private:
    QFile file;
    std::vector<QString> listOfParticipants;
};

#endif // FILE_H
