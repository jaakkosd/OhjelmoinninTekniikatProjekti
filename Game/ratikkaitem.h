#ifndef RATIKKAITEM_H
#define RATIKKAITEM_H

#include "imgactoritem.h"

class ratikkaitem : public imgActorItem
{
public:
    ratikkaitem(int x, int y);
    void move(int x,int y);
private:
    QPixmap ratikka;
};

#endif // RATIKKAITEM_H
