#pragma once

#include "SDL.h"
#include <vector>
#include "Room.h"

class Biome
{
public:
	Biome();
	~Biome();
	virtual Room *createRoom(int x, int y);
protected:
	std::vector<Room *> rooms;
	BiomeType type;
	int low_x;
	int high_x;
	int low_y;
	int high_y;
};