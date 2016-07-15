#pragma once
class overworld
{
public:
	overworld();
	~overworld();
private:
	int biomeGrid[16][16]; //the map of which tiles are part of which biomes
	int biomeNumber; //how many biomes this map will contain
	bool biomelist[16]; //a t/f list indicating for each biome whether it is in the map
};

