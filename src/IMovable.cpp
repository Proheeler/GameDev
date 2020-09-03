#include <IMovable.h>

IMovable::IMovable(IShape *shape):m_shape(shape)
{

}

IShape *IMovable::shape(){
    return m_shape;
}
