#pragma once

struct Window;
struct SDLGameObject;

struct IMovable
{
    IMovable(SDLGameObject *shape);
    virtual void moveLeft(Window &window) = 0;
    virtual void moveRight(Window &window) = 0;
    virtual void moveUp(Window &window) = 0;
    virtual void moveDown(Window &window) = 0;
    SDLGameObject *shape();
private:
    SDLGameObject *m_shape = nullptr;
};
