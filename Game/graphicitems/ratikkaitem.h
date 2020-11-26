#ifndef RATIKKAITEM_H
#define RATIKKAITEM_H

#include "imgactoritem.h"
namespace Game {
class RatikkaItem : public ImgActorItem
{
public:
    RatikkaItem(int x=0, int y=0);
    QPair<int,int> move(int x, int y);
private:
    QPixmap ratikkaleft;
    QPixmap ratikkaright;
};
}
#endif // RATIKKAITEM_H
