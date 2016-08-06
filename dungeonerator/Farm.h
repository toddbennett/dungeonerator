#pragma once
#include "Biome.h"
class Farm :
	public Biome
{
public:
	Farm(char *sprPath, SDL_Renderer *renderer);
	~Farm();
	virtual Room *createRoom(int x, int y);
};

