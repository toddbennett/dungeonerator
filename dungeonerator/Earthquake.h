#pragma once
#include "Biome.h"
class Earthquake :
	public Biome
{
public:
	Earthquake();
	~Earthquake();
	virtual Room *createRoom(int x, int y);
};

