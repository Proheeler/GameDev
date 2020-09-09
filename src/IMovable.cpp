#include <IMovable.h>
#include <SDLGameObject.h>
IMovable::IMovable(SDLGameObject * shape):m_shape(shape)
{

}

SDLGameObject *IMovable::shape(){
    return m_shape;
}
