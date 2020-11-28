#ifndef RATIKKAITEM_H
#define RATIKKAITEM_H

#include "imgactoritem.h"
namespace Game {
/**
 * @brief The RatikkaItem class creates ui implementation for ratikka
 */
class RatikkaItem : public ImgActorItem
{
public:
    /**
     * @brief RatikkaItem default constructor.
     * @param x ratikka x coordinate
     * @param y ratikka y coordinate
     */
    RatikkaItem(int x=0, int y=0);
    /**
     * @brief move moves ratikka to given position
     * @param x ratikka new x coordinate
     * @param y raeikka new y coordinate
     * @return pair of x and y coordinate
     */
    QPair<int,int> move(int x, int y);
private:
    QPixmap ratikkaleft;
    QPixmap ratikkaright;
};
}
#endif // RATIKKAITEM_H
