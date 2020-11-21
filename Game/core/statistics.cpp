#include "statistics.h"
#include "QDebug"

namespace Game {
Statistics::Statistics()
{
    points_ = 0;
}

void Statistics::morePassengers(int num)
{

}

void Statistics::nysseRemoved()
{

}

void Statistics::newNysse()
{

}

void Statistics::nysseLeft()
{

}

void Statistics::addPoints()
{
    points_ += 1;
}

int Statistics::getPoints()
{
    return points_;
}

}
