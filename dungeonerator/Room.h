#pragma once

#include "Biome.h"
#include "GameObject.h"

class Room : public GameObject
{
public:
	Room(Biome biome, int x, int y, char *path);
	~Room();
private:
	Biome biome;
};

