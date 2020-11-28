#ifndef BUS_UI_ITEM_H
#define BUS_UI_ITEM_H

#include "imgactoritem.h"
#include <QDebug>
#include <QtMath>
namespace Game {
/**
 * @brief The BusUiItem class creates ui implementation for bus
 */
class BusUiItem : public ImgActorItem
{
public:
    /**
     * @brief BusUiItem default constructor
     * @param x bus x coordinate
     * @param y bus y coordinate
     */
    BusUiItem(int x, int y);
    /**
     * @brief moveTo move bus to given postion
     * @param x bus new x coordinate
     * @param y bus new y coordinate
     */
    void moveTo(int x,int y);
private:
    QPixmap pixmapLeft_;
    QPixmap pixmapRight_;
    float angle_ = 90;

};
}
#endif // BUS_UI_ITEM_H
