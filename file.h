#ifndef FILE_H
#define FILE_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <ctime>
#include <container.h>

class File : public QObject
{
    Q_OBJECT
public:
    explicit File(QObject *parent = nullptr);

    Q_INVOKABLE int countParticipant();
    Q_INVOKABLE QString getParticipantByIndex(int index);
    Q_INVOKABLE QString getRandomParticipant();

private:
    QFile file;
    std::vector<Participant*> listOfParticipant;
};

#endif // FILE_H
