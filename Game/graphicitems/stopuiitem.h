#ifndef STOPUIITEM_H
#define STOPUIITEM_H

#include "imgactoritem.h"
namespace Game {
/**
 * @brief The StopUiItem class creates ui implementation for stops
 */
class StopUiItem : public ImgActorItem
{
public:
    /**
     * @brief StopUiItem default constructor
     * @param x stop x coordinate
     * @param y stop y coordinate
     */
    StopUiItem(int x,int y);
private:
    QPixmap pixmap_;
};
}
#endif // STOPUIITEM_H
