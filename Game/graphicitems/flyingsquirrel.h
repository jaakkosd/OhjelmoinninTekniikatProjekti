#ifndef FLYINGSQUIRREL_H
#define FLYINGSQUIRREL_H

#include "imgactoritem.h"

namespace Game {
/**
 * @brief The FlyingSquirrel class creates ui implementation for flying squirrel
 */
class FlyingSquirrel : public ImgActorItem
{
public:
    /**
     * @brief FlyingSquirrel default constructor
     * @param x actor's x coordinate
     * @param y actor's y coordinate
     */
    FlyingSquirrel(int x, int y);

public slots:
    /**
     * @brief move squirrel to given position
     * @param x new x coordinate
     * @param y new y coordinate
     * @return pair of coordinates
     */
    QPair<int, int> move(int x, int y);
private:
    QPixmap squirrelUp;
};
}

#endif // FLYINGSQUIRREL_H
