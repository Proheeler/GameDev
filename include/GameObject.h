#pragma once
#include "LoaderParams.h"

class GameObject
{
protected:
	GameObject() {}


public:
    virtual ~GameObject(){}
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;

	//new load function
	virtual void load(const LoaderParams* pParams) = 0;
};
