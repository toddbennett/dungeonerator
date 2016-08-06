#pragma once
#include "Biome.h"
class River :
	public Biome
{
public:
	River(char *sprPath, SDL_Renderer *renderer);
	~River();
	virtual Room *createRoom(int x, int y);
};

