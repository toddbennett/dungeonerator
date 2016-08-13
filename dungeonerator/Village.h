#pragma once
#include "Biome.h"
class Village :
	public Biome
{
public:
	Village();
	~Village();
	virtual Room *createRoom(int x, int y);
};

