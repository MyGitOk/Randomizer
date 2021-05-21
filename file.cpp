#include "file.h"

File::File(QObject *parent) : QObject(parent)
{
    file.setFileName("list_of_participants.txt");
}

int File::countParticipants() //возвращает количество строк из файла
{
    if (listOfParticipants.empty())
    {
        if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
        {
            QTextStream in(&file);
            while(!in.atEnd())
            {
                listOfParticipants.push_back(in.readLine());
                //qDebug() << count;
            }
            file.close();
        }
    }
    return listOfParticipants.size();
}

QString File::getParticipantByIndex(int index)
{
    //qDebug() << listOfParticipants[index];
    return listOfParticipants[index];
}

QString File::getRandomParticipant()
{
    int random_index = -1;
    if (!listOfParticipants.empty())
    {
        srand(time(0));
        rand();
        random_index = rand() % listOfParticipants.size();
    }
    return listOfParticipants.empty() ? "" : listOfParticipants[random_index];
}

