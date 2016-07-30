#pragma once

#include "SDL.h"
#include <string>

class GameObject
{
public:
	GameObject(char *sprPath, int x, int y, SDL_Renderer *renderer);
	~GameObject();
	virtual void draw(SDL_Renderer *renderer, int w, int h);
	int getDepth();
protected:
	// a subclass can use this as their base constructor but please remember to set a sprite afterwards!
	GameObject(int x, int y);
	void setSprite(char *sprPath, SDL_Renderer *renderer);
	int x, y;
	SDL_Texture *texture;
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