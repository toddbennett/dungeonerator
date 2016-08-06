#pragma once
#include "Biome.h"
class Lake :
	public Biome
{
public:
	Lake(char *sprPath, SDL_Renderer *renderer);
	~Lake();
	virtual Room *createRoom(int x, int y);
};

