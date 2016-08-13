#pragma once
#include "Biome.h"
class Lake :
	public Biome
{
public:
	Lake();
	~Lake();
	virtual Room *createRoom(int x, int y);
};

