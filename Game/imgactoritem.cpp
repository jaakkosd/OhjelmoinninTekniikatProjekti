#include "imgactoritem.h"

ImgActorItem::ImgActorItem(int x, int y):x_(x), y_(y)
{
    setPos(x_, y_ );

}

void ImgActorItem::setCoords(int x, int y)
{
    x_=x;
    y_=y;
    setPos(x_, y_ );
}

courseConverter::cords ImgActorItem::getCoords()
{
    return courseConverter::cords {x_, y_};
}

void ImgActorItem::moveTo(int x, int y)
{
    setCoords(x,y);
}
