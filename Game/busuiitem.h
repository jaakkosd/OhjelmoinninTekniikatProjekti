#ifndef BUS_UI_ITEM_H
#define BUS_UI_ITEM_H

#include "imgactoritem.h"
#include <QDebug>
#include <QtMath>
class BusUiItem : public ImgActorItem
{
public:
    BusUiItem(int x, int y);
    void move(int x,int y);
private:
    QPixmap pixmapLeft_;
    QPixmap pixmapRight_;
    float angle_ = 90;

};

#endif // BUS_UI_ITEM_H
