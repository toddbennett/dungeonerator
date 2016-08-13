#pragma once
#include "Biome.h"
class Desert :
	public Biome
{
public:
	Desert();
	~Desert();
	virtual Room *createRoom(int x, int y);
};

