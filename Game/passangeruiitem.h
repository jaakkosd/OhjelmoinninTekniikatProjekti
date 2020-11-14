#ifndef PASSANGERUIITEM_H
#define PASSANGERUIITEM_H
#include "imgactoritem.h"

class PassangerUiItem : public ImgActorItem
{
public:
    PassangerUiItem(int x, int y);
    void move(int x,int y);
    void setOffset(int x, int y);
private:
    QPixmap pixmap_;
    int offx_ = 0;
    int offy_ = 0;
};

#endif // PASSANGERUIITEM_H
