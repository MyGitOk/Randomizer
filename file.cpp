#include "file.h"

File::File(QObject *parent) : QObject(parent)
{
    file.setFileName("list_of_participants.txt");
}

int File::countParticipant() //test method
{
    if (listOfParticipant.empty())
    {
        //qDebug() << "StructList entered";
        if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
        {
            QTextStream in(&file);
            while(!in.atEnd())
            {
                listOfParticipant.push_back(new Participant(in.readLine()));
                //qDebug() << count;
            }
            file.close();
        }
    }
    return listOfParticipant.size();
}

QString File::getParticipantByIndex(int index)
{
    return listOfParticipant[index]->m_name;
}

QString File::getRandomParticipant()
{
    int random_index = -1;
    if (!listOfParticipant.empty())
    {
        srand(time(0));
        rand();
        random_index = rand() % listOfParticipant.size();
    }
    return listOfParticipant.empty() ? "" : listOfParticipant[random_index]->m_name;
}
