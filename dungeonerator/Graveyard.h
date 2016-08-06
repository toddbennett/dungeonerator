#pragma once
#include "Biome.h"
class Graveyard :
	public Biome
{
public:
	Graveyard(char *sprPath, SDL_Renderer *renderer);
	~Graveyard();
	virtual Room *createRoom(int x, int y);
};

