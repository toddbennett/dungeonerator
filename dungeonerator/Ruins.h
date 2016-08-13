#pragma once
#include "Biome.h"
class Ruins :
	public Biome
{
public:
	Ruins();
	~Ruins();
	virtual Room *createRoom(int x, int y);
};

