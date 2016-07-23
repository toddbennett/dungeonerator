#pragma once

#include "SDL.h"

class GameObject
{
public:
	GameObject(char *sprPath, int x, int y);
	~GameObject();
	void draw(SDL_Surface *surface, int w, int h);
protected:
	// a subclass can use this as their base constructor but please remember to set a sprite afterwards!
	GameObject(int x, int y);
	void setSprite(char *sprPath);
private:
	SDL_Surface *sprite;
	int x, y;
};

