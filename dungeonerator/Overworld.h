#pragma once
#include "Biome.h"

struct Point {
	int x;
	int y;
};

class Overworld
{
public:
	Overworld();
	~Overworld();
	BiomeType getBiome(int x, int y);
private:
	void growPoint(BiomeType biome, Point nodule, int biomesize, int percentage);
	void fillPoint(BiomeType biome);
	Point getFreePoint();
	int mapWidth;
	int mapHeight;
	int mapSize;
	BiomeType biomeGrid[16][16]; //the map of which tiles are part of which biomes
	int biomeNumber; //how many biomes this map will contain
	bool biomeList[16]; //a t/f list indicating for each biome whether it is in the map

	Room ***map;
	Biome **biomes;
};

