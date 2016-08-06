#pragma once
#include "Biome.h"
class Volcano :
	public Biome
{
public:
	Volcano(char *sprPath, SDL_Renderer *renderer);
	~Volcano();
	virtual Room *createRoom(int x, int y);
};

