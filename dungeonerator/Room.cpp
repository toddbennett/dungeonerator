#include <string.h>
#include "Room.h"

Room::Room(biomeType biome, int x, int y, char *path) : GameObject(x, y)
{
	this->biome = biome;
	char *sprPath = new char[256];
	sprPath[0] = 0;
	strcat(sprPath, path);
	switch (biome) {
	case BIO_GRASSLAND:
		strcat(sprPath, "biome1.bmp");
		break;
	case BIO_VILLAGE:
		strcat(sprPath, "biome2.bmp");
		break;
	case BIO_FOREST:
		strcat(sprPath, "biome3.bmp");
		break;
	case BIO_VOLCANO:
		strcat(sprPath, "biome4.bmp");
		break;
	case BIO_ICE:
		strcat(sprPath, "biome5.bmp");
		break;
	case BIO_LAKE:
		strcat(sprPath, "biome6.bmp");
		break;
	case BIO_GRAVEYARD:
		strcat(sprPath, "biome7.bmp");
		break;
	case BIO_RIVER:
		strcat(sprPath, "biome8.bmp");
		break;
	case BIO_CASTLE:
		strcat(sprPath, "biome9.bmp");
		break;
	case BIO_SWAMP:
		strcat(sprPath, "biome10.bmp");
		break;
	case BIO_RUINS:
		strcat(sprPath, "biome11.bmp");
		break;
	case BIO_DESERT:
		strcat(sprPath, "biome12.bmp");
		break;
	case BIO_FARM:
		strcat(sprPath, "biome13.bmp");
		break;
	case BIO_EARTHQUAKE:
		strcat(sprPath, "biome14.bmp");
		break;
	case BIO_SKY:
		strcat(sprPath, "biome15.bmp");
		break;
	default:
		strcat(sprPath, "biome0.bmp");
		break;
	}
	setSprite(sprPath);
	delete[] sprPath;
}


Room::~Room()
{
	
}
