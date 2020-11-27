#ifndef PASSANGERUIITEM_H
#define PASSANGERUIITEM_H
#include "imgactoritem.h"
namespace Game {
class PassangerUiItem : public ImgActorItem
{
public:
    PassangerUiItem(int x, int y);
    void moveTo(int x,int y);
private:
    QPixmap pixmap_;
};
}
#endif // PASSANGERUIITEM_H
