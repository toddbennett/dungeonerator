#pragma once
#include "Biome.h"
class Castle :
	public Biome
{
public:
	Castle();
	~Castle();
	virtual Room *createRoom(int x, int y);
};

