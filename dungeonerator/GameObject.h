#pragma once

#include "SDL.h"
#include <string>

class GameObject
{
public:
	GameObject(char *sprPath, int x, int y);
	~GameObject();
	virtual void draw(SDL_Surface *surface, int w, int h);
	int getDepth();
protected:
	// a subclass can use this as their base constructor but please remember to set a sprite afterwards!
	GameObject(int x, int y);
	void setSprite(char *sprPath);
	int x, y;
	SDL_Surface *sprite;
private:
	
	std::string getName();
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