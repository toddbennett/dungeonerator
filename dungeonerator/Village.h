#pragma once
#include "Biome.h"
class Village :
	public Biome
{
public:
	Village(char *sprPath, SDL_Renderer *renderer);
	~Village();
	virtual Room *createRoom(int x, int y);
};

