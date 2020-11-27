#include "graphicitems/imgactoritem.h"
namespace Game {
ImgActorItem::ImgActorItem(int x, int y)
{
    moveTo(x, y);


}

CourseConverter::cords ImgActorItem::getCoords()
{
    return CourseConverter::cords {x_, y_};
}

void ImgActorItem::moveTo(int x, int y)
{
    x_=x;
    y_=y;
    setPos(x_, y_ );
    setZValue(y_);
}
}
