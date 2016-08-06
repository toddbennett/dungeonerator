#pragma once
#include "Biome.h"
class Ruins :
	public Biome
{
public:
	Ruins(char *sprPath, SDL_Renderer *renderer);
	~Ruins();
	virtual Room *createRoom(int x, int y);
};

