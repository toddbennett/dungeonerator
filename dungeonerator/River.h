#pragma once
#include "Biome.h"
class River :
	public Biome
{
public:
	River();
	~River();
	virtual Room *createRoom(int x, int y);
};

