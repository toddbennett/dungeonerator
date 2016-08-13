#pragma once
#include "Biome.h"
class Farm :
	public Biome
{
public:
	Farm();
	~Farm();
	virtual Room *createRoom(int x, int y);
};

