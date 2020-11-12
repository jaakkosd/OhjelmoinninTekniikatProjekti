#ifndef PASSANGERUIITEM_H
#define PASSANGERUIITEM_H
#include "imgactoritem.h"

class PassangerUiItem : public ImgActorItem
{
public:
    PassangerUiItem(int x, int y);
    void move(int x,int y);
private:
    QPixmap pixmap_;
};

#endif // PASSANGERUIITEM_H
