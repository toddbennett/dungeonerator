#pragma once

#include "Biome.h"
#include "GameObject.h"

class Room
{
public:
	Room();
	~Room();
private:
	Biome biome;
	GameObject *board[16][16];
	Room *left;
	Room *up;
	Room *right;
	Room *down;
};

