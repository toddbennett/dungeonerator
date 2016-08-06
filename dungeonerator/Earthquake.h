#pragma once
#include "Biome.h"
class Earthquake :
	public Biome
{
public:
	Earthquake(char *sprPath, SDL_Renderer *renderer);
	~Earthquake();
	virtual Room *createRoom(int x, int y);
};

