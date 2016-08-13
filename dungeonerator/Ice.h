#pragma once
#include "Biome.h"
class Ice :
	public Biome
{
public:
	Ice();
	~Ice();
	virtual Room *createRoom(int x, int y);
};

