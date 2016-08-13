#pragma once
#include "Biome.h"
class Grassland :
	public Biome
{
public:
	Grassland();
	~Grassland();
	virtual Room *createRoom(int x, int y);
};

