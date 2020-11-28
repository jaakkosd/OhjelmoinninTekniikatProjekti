#ifndef PASSANGERUIITEM_H
#define PASSANGERUIITEM_H
#include "imgactoritem.h"
namespace Game {
/**
 * @brief The PassangerUiItem class creates ui implementation for passenger
 */
class PassangerUiItem : public ImgActorItem
{
public:
    /**
     * @brief PassangerUiItem default constructor
     * @param x passanger x coordinate
     * @param y passanger y coordinate
     */
    PassangerUiItem(int x, int y);
private:
    QPixmap pixmap_;
};
}
#endif // PASSANGERUIITEM_H
