#ifndef RATIKKAITEM_H
#define RATIKKAITEM_H

#include "imgactoritem.h"

class Ratikkaitem : public ImgActorItem
{
public:
    Ratikkaitem(int x=100, int y=100);
    QPair<int,int> move(int x, int y);
private:
    QPixmap ratikka;
};

#endif // RATIKKAITEM_H
