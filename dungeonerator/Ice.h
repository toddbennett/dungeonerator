#pragma once
#include "Biome.h"
class Ice :
	public Biome
{
public:
	Ice(char *sprPath, SDL_Renderer *renderer);
	~Ice();
	virtual Room *createRoom(int x, int y);
};

