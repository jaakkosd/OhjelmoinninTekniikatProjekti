#include "hiscore.h"

#include <QDir>
#include "QDebug"

int HiScore::readScore(){
    QFile file(QDir::currentPath()+"\\hiscore.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug("Error in reading file");
        return 0;
    }
    QByteArray line = file.readLine();
    file.close();
    return line.toInt();
}

void HiScore::writeScore(int score)
{
    QFile file(QDir::currentPath()+"\\hiscore.txt");
    if (!file.open(QIODevice::WriteOnly))
    {
        qDebug("Error in writing file");
    }
    QByteArray a(QString("%1").arg(score).toUtf8());
    file.write(a);
    file.close();
}
