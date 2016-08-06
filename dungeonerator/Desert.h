#pragma once
#include "Biome.h"
class Desert :
	public Biome
{
public:
	Desert(char *sprPath, SDL_Renderer *renderer);
	~Desert();
	virtual Room *createRoom(int x, int y);
};

