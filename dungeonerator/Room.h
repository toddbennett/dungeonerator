#pragma once

#include "GameObject.h"

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
	BIO_SKY,
	BIO_TEST
};


class Room : public GameObject
{
public:
	Room(BiomeType biome, int x, int y, char *sprPath, SDL_Renderer *renderer);
	~Room();
	void setTiles(char *path, int n);
	void createBackground(int** tileMap);
	void drawBackground();
private:
	BiomeType biome;
	SDL_Texture *background;
	char *sprPath;
	SDL_Surface *tiles;
	int numTiles;
};

