#ifndef STOPUIITEM_H
#define STOPUIITEM_H

#include "imgactoritem.h"

class StopUiItem : public ImgActorItem
{
public:
    StopUiItem(int x,int y);
private:
    QPixmap pixmap_;
};

#endif // STOPUIITEM_H