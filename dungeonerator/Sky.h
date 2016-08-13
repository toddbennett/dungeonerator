#pragma once
#include "Biome.h"
class Sky :
	public Biome
{
public:
	Sky();
	~Sky();
	virtual Room *createRoom(int x, int y);
};

