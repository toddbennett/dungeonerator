#pragma once

#include "Biome.h"
#include "GameObject.h"

class Room : public GameObject
{
public:
	Room(biomeType biome, int x, int y, char *path, SDL_Renderer *renderer);
	~Room();
private:
	biomeType biome;
};

