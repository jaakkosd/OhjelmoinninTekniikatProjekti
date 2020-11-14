#ifndef PIC_ACTOR_ITEM_H
#define PIC_ACTOR_ITEM_H

#include <QGraphicsPixmapItem>

class ImgActorItem : public QGraphicsPixmapItem
{
public:
    ImgActorItem(int x, int y);
    void setCoord(int x, int y);
    virtual void move(int x, int y);
protected:
    int x_;
    int y_;
};


#endif // PIC_ACTOR_ITEM_H
