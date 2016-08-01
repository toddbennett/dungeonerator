#pragma once

#include "Biome.h"
#include "GameObject.h"

class Room : public GameObject
{
public:
	Room(BiomeType biome, int x, int y, char *path, SDL_Renderer *renderer);
	~Room();
private:
	BiomeType biome;
};

