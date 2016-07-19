#pragma once

struct point {
	int x;
	int y;
};

class overworld
{
public:
	overworld();
	~overworld();
private:
	int mapwidth;
	int mapheight;
	int mapsize;
	int biomeGrid[16][16]; //the map of which tiles are part of which biomes
	int biomeNumber; //how many biomes this map will contain
	bool biomeList[16]; //a t/f list indicating for each biome whether it is in the map
};

