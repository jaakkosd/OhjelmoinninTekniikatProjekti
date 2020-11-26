#include "statistics.h"
#include "QDebug"

namespace Game {
Statistics::Statistics(QString filename)
{
    filename_ = filename;
    readHiScore();
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

void Statistics::addPoints(int points)
{
    points_ += points;
}

int Statistics::Points()
{
    return points_;
}
void Statistics::saveHiScore()
{
    if(hiScore_ > points_){
        return;
    }
    QFile file(QDir::currentPath()+"\\"+filename_);
    if (!file.open(QIODevice::WriteOnly))
    {
        qDebug("Error in writing file");
    }
    QByteArray a(QString("%1").arg(points_).toUtf8());
    file.write(a);
    file.close();
}

void Statistics::readHiScore(){
    QFile file(QDir::currentPath()+"\\"+filename_);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug("Error in reading file");
        hiScore_ = 0;
    }
    QByteArray line = file.readLine();
    file.close();
    hiScore_ = line.toInt();
}

int Statistics::hiScore()
{
    return hiScore_;
}

int Statistics::nysses()
{
    return nysses_;
}

int Statistics::passangers()
{
    return passangers_;
}

}
