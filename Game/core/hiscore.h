#ifndef HISCORE_H
#define HISCORE_H

#include <QFile>

class HiScore
{
public:
    static int readScore();
    static void writeScore(int score);
};

#endif // HISCORE_H
