#include "movement.h"

Movement::Movement(QObject *parent) : QObject(parent)
{

}
bool Movement::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        qDebug("Ate key press %d", keyEvent->key());
        pressedKeys.insert(keyEvent->key());
        emit keyPressed(pressedKeys);
        return true;

    }else if(event->type() == QEvent::KeyRelease){
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        qDebug("Ate key release %d", keyEvent->key());
        pressedKeys.remove(keyEvent->key());
        emit keyPressed(pressedKeys);
        return true;
    } else if( event->type() == QEvent::GraphicsSceneWheel
               ||event->type() == QEvent::Wheel) {
        // standard event processing
        qDebug("Ate mouse event");
        return true;
    } else {
        // standard event processing
        return QObject::eventFilter(obj, event);
    }
}
