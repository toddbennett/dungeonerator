#pragma once
#include "Biome.h"
class Castle :
	public Biome
{
public:
	Castle(char *sprPath, SDL_Renderer *renderer);
	~Castle();
	virtual Room *createRoom(int x, int y);
};

