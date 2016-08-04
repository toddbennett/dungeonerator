#pragma once

#include "Biome.h"
#include "GameObject.h"

class Room : public GameObject
{
public:
	Room(biomeType biome, int x, int y, char *path);
	~Room();
private:
	biomeType biome;
};

