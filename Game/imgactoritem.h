#ifndef PIC_ACTOR_ITEM_H
#define PIC_ACTOR_ITEM_H

#include <QGraphicsPixmapItem>

class imgActorItem : public QGraphicsPixmapItem
{
public:
    imgActorItem(int x, int y);
    void setCoord(int x, int y);
protected:
    int x_;
    int y_;
private:
    int oldx_;
    int oldy_;
};


#endif // PIC_ACTOR_ITEM_H
