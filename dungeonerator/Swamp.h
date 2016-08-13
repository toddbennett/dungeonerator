#pragma once
#include "Biome.h"
class Swamp :
	public Biome
{
public:
	Swamp();
	~Swamp();
	virtual Room *createRoom(int x, int y);
};

