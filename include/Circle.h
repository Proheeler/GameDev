#pragma once
#include <SDLGameObject.h>
#include <GameParameters.h>
class Circle : public SDLGameObject
{
public:
    Circle();
    ~Circle(){}
	void load(const LoaderParams * pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();
    int radius();
    void setSpeedX();
    void setSpeedY();

    int m_speedX = GameParameters::ballSpeed.x;
    int m_speedY = GameParameters::ballSpeed.y;

private:
    int m_radius;
};
