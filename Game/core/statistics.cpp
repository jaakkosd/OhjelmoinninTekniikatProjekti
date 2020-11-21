#include "statistics.h"
#include "QDebug"

namespace Game {
Statistics::Statistics()
{
    points_ = 0;
}

void Statistics::morePassengers(int num)
{
    passangers_ += num;
}

void Statistics::nysseRemoved()
{
    nysses_ -= 1;
}

void Statistics::newNysse()
{
     nysses_ += 1;
}

void Statistics::nysseLeft()
{
     nysses_ -= 1;
}

void Statistics::addPoints()
{
    points_ += 1;
}

int Statistics::getPoints()
{
    return points_;
}
void Statistics::saveHiScore()
{
    QFile file(QDir::currentPath()+"\\hiscore.txt");
    if (!file.open(QIODevice::WriteOnly))
    {
        qDebug("Error in writing file");
    }
    QByteArray a(QString("%1").arg(points_).toUtf8());
    file.write(a);
    file.close();
}

int Statistics::readHiScore(){
    QFile file(QDir::currentPath()+"\\hiscore.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug("Error in reading file");
        return 0;
    }
    QByteArray line = file.readLine();
    file.close();
    return line.toInt();
}



}
