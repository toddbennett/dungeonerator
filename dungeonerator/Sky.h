#pragma once
#include "Biome.h"
class Sky :
	public Biome
{
public:
	Sky(char *sprPath, SDL_Renderer *renderer);
	~Sky();
	virtual Room *createRoom(int x, int y);
};

