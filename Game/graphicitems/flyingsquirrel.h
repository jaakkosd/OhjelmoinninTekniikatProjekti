#ifndef FLYINGSQUIRREL_H
#define FLYINGSQUIRREL_H

#include "imgactoritem.h"

namespace Game {
class FlyingSquirrel : public ImgActorItem
{
public:
    FlyingSquirrel(int x, int y);

public slots:
    QPair<int, int> move(int x, int y);
private:
    QPixmap squirrelUp;
};
}

#endif // FLYINGSQUIRREL_H
