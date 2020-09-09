#pragma once

#include "GameObject.h"
#include "Vector2D.h"

class SDLGameObject: public GameObject
{
protected:

	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;

	int m_width;
	int m_height;

	int m_currentRow;
	int m_currentFrame;
	int m_numFrames;
	int m_callbackID;

	std::string m_textureID;

public:

	SDLGameObject();
    virtual ~SDLGameObject()=default;

	virtual void draw();
	virtual void update();
	virtual void clean();

	Vector2D& getPosition() { return m_position; }
	int getWidth() { return m_width; }
	int getHeight() { return m_height; }
    void setPosition(Vector2D value)
    {
        m_position = value;
    }
	virtual void load(const LoaderParams* pParams);
};
