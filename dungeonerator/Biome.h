#pragma once
enum BiomeType {
	BIO_BLANK,
	BIO_GRASSLAND,
	BIO_VILLAGE,
	BIO_FOREST,
	BIO_VOLCANO,
	BIO_ICE,
	BIO_LAKE,
	BIO_GRAVEYARD,
	BIO_RIVER,
	BIO_CASTLE,
	BIO_SWAMP,
	BIO_RUINS,
	BIO_DESERT,
	BIO_FARM,
	BIO_EARTHQUAKE,
	BIO_SKY
};

class Biome
{
public:
	Biome();
	~Biome();
protected:
	int low_x;
	int high_x;
	int low_y;
	int high_y;
};