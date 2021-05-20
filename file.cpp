#include "file.h"

File::File(QObject *parent) : QObject(parent)
{
    file.setFileName("list_of_participients.txt");
}

int File::countParticipants() // рабочий метод. возвращает количество строк из файла
{
    int count= 0;
    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {
        while(!file.atEnd())
        {
            count++;
            file.readLine();
        }
        file.close();
    }

    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {
        listOfParticipants.resize(count);
        //qDebug() << listOfParticipants;

        QTextStream in(&file);
        for(auto i = 0; i < count; i++)
        {
            //QString line = in.readLine();
            listOfParticipants[i] = in.readLine();
            //process_line(line);
        }

//        for(auto i = 0; i < count; i++)
//        {
//            // QTextStream::readLine
//            listOfParticipants[i] = file.readLine();
//            qDebug() << listOfParticipants[i];
//        }
        file.close();
    }
    return count;
}

QString File::getParticipantByIndex(int index)
{
    //qDebug() << listOfParticipants[index];
    return listOfParticipants[index];
}

QString File::getRandomParticipant()
{
    srand(time(0));
    rand();
    return listOfParticipants[rand() % listOfParticipants.size()];
}

