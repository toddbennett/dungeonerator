#pragma once
#include "Biome.h"
class Swamp :
	public Biome
{
public:
	Swamp(char *sprPath, SDL_Renderer *renderer);
	~Swamp();
	virtual Room *createRoom(int x, int y);
};

