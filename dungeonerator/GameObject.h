#pragma once

#include "SDL.h"
#include <string>

class GameObject
{
public:
	GameObject(int x, int y, std::string filename);
	~GameObject();
	virtual void draw(int w, int h);
	int getDepth();
	std::string getName();
protected:
	GameObject(int x, int y);
	void setSprite(std::string filename);
	int x, y;
	SDL_Texture *texture;
private:
	
	
	int depth = 1;
};

class DepthComparator
{
public:
	bool operator() (GameObject *lhs, GameObject *rhs) const
	{
		return (lhs->getDepth() <= rhs->getDepth());
	}
};