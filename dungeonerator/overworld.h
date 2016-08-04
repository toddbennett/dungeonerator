#pragma once
#include "Biome.h"

struct point {
	int x;
	int y;
};

class overworld
{
public:
	overworld();
	~overworld();
	biomeType getBiome(int x, int y);
private:
	void growPoint(biomeType biome, point nodule, int biomesize, int percentage);
	void fillPoint(biomeType biome);
	point getFreePoint();
	int mapwidth;
	int mapheight;
	int mapsize;
	biomeType biomeGrid[16][16]; //the map of which tiles are part of which biomes
	int biomeNumber; //how many biomes this map will contain
	bool biomeList[16]; //a t/f list indicating for each biome whether it is in the map
};

