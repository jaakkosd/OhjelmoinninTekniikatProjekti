#include "core/movement.h"
namespace Game {
Movement::Movement(QObject *parent) : QObject(parent)
{

}
bool Movement::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        pressedKeys.insert(keyEvent->key());
        emit keyPressed(pressedKeys);
        return true;

    }else if(event->type() == QEvent::KeyRelease){
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        pressedKeys.remove(keyEvent->key());
        emit keyPressed(pressedKeys);
        return true;
    } else if( event->type() == QEvent::GraphicsSceneWheel
               ||event->type() == QEvent::Wheel) {
        // standard event processing
        return true;
    } else {
        // standard event processing
        return QObject::eventFilter(obj, event);
    }
}
}
