#pragma once
#include "Biome.h"
class Volcano :
	public Biome
{
public:
	Volcano();
	~Volcano();
	virtual Room *createRoom(int x, int y);
};

