#pragma once
#include "Biome.h"
class Forest :
	public Biome
{
public:
	Forest(char *sprPath, SDL_Renderer *renderer);
	~Forest();
	virtual Room *createRoom(int x, int y);
};

