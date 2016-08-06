#pragma once
#include "Biome.h"
class Grassland :
	public Biome
{
public:
	Grassland(char *sprPath, SDL_Renderer *renderer);
	~Grassland();
	virtual Room *createRoom(int x, int y);
};

