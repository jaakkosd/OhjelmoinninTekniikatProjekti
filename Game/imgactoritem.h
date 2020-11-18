#ifndef PIC_ACTOR_ITEM_H
#define PIC_ACTOR_ITEM_H

#include <QGraphicsPixmapItem>
#include "courseconverter.h"
namespace Game {
class ImgActorItem : public QGraphicsPixmapItem
{
public:
    ImgActorItem(int x, int y);
    void setCoords(int x, int y);
    courseConverter::cords getCoords();
    virtual void moveTo(int x, int y);
protected:
    int x_;
    int y_;
};
}

#endif // PIC_ACTOR_ITEM_H
