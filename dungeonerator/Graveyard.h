#pragma once
#include "Biome.h"
class Graveyard :
	public Biome
{
public:
	Graveyard();
	~Graveyard();
	virtual Room *createRoom(int x, int y);
};

