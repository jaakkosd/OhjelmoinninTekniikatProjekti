#include "imgactoritem.h"

ImgActorItem::ImgActorItem(int x, int y):x_(x), y_(y)
{
    setPos(x_, y_ );

}

void ImgActorItem::setCoord(int x, int y)
{
    x_=x;
    y_=y;
    setPos(x_, y_ );
}

void ImgActorItem::moveTo(int x, int y)
{
    setCoord(x,y);
}
