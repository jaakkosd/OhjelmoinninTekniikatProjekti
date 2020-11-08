#include "imgactoritem.h"

imgActorItem::imgActorItem(int x, int y):x_(x), y_(y)
{
    setPos(x_, y_ );

}

void imgActorItem::setCoord(int x, int y)
{
    x_=x;
    y_=y;
    setPos(x_, y_ );
}
