#pragma once
#include "Biome.h"
class Forest :
	public Biome
{
public:
	Forest();
	~Forest();
	virtual Room *createRoom(int x, int y);
};

