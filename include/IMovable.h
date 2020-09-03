#pragma once

struct Window;
struct IShape;

struct IMovable
{
    IMovable(IShape * shape);
    virtual void moveLeft(Window &window) = 0;
    virtual void moveRight(Window &window) = 0;
    virtual void moveUp(Window &window) = 0;
    virtual void moveDown(Window &window) = 0;
    IShape * shape();
private:
    IShape *m_shape = nullptr;
};
