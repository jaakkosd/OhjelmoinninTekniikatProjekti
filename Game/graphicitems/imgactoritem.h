#ifndef PIC_ACTOR_ITEM_H
#define PIC_ACTOR_ITEM_H

#include <QGraphicsPixmapItem>
#include "core/courseconverter.h"
namespace Game {
/**
 * @brief ImgActorItem is base class for our ui items.
 *
 * If class method doesn't have exception guarantee of nothrow, method can leak
 * out exception `std::bad_alloc` (out of memory)
 */
class ImgActorItem : public QGraphicsPixmapItem
{
public:
    /**
     * @brief ImgActorItem
     * @param x item's x uicoordinate
     * @param y item's y uicoordinate
     */
    ImgActorItem(int x, int y);
    CourseConverter::cords getCoords();
    virtual void moveTo(int x, int y);
protected:
    int x_=0;
    int y_=0;
};
}

#endif // PIC_ACTOR_ITEM_H
