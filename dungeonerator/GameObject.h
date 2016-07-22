#pragma once

#include "SDL.h"

class GameObject
{
public:
	GameObject();
	~GameObject();
private:
	SDL_Surface *sprite;
};

