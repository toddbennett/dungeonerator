#include <string.h>
#include "Room.h"

Room::Room(BiomeType biome, int x, int y, char *sprPath, SDL_Renderer *renderer) : GameObject(x, y)
{
	this->renderer = renderer;
	this->sprPath = sprPath;
	this->biome = biome;
	char *spritePath = new char[256];
	spritePath[0] = 0;
	strcat(spritePath, sprPath);
	switch (biome) {
	case BIO_GRASSLAND:
		strcat(spritePath, "biome1.bmp");
		break;
	case BIO_VILLAGE:
		strcat(spritePath, "biome2.bmp");
		break;
	case BIO_FOREST:
		strcat(spritePath, "biome3.bmp");
		break;
	case BIO_VOLCANO:
		strcat(spritePath, "biome4.bmp");
		break;
	case BIO_ICE:
		strcat(spritePath, "biome5.bmp");
		break;
	case BIO_LAKE:
		strcat(spritePath, "biome6.bmp");
		break;
	case BIO_GRAVEYARD:
		strcat(spritePath, "biome7.bmp");
		break;
	case BIO_RIVER:
		strcat(spritePath, "biome8.bmp");
		break;
	case BIO_CASTLE:
		strcat(spritePath, "biome9.bmp");
		break;
	case BIO_SWAMP:
		strcat(spritePath, "biome10.bmp");
		break;
	case BIO_RUINS:
		strcat(spritePath, "biome11.bmp");
		break;
	case BIO_DESERT:
		strcat(spritePath, "biome12.bmp");
		break;
	case BIO_FARM:
		strcat(spritePath, "biome13.bmp");
		break;
	case BIO_EARTHQUAKE:
		strcat(spritePath, "biome14.bmp");
		break;
	case BIO_SKY:
		strcat(spritePath, "biome15.bmp");
		break;
	default:
		strcat(spritePath, "biome0.bmp");
		break;
	}
	setSprite(spritePath, renderer);
	delete[] spritePath;
}

Room::~Room()
{
	
}

void Room::setTiles(char *path, int n)
{
	const int TILE_SIZE = 16;

	numTiles = n;
	char spritePath[256];
	spritePath[0] = 0;
	strcat(spritePath, sprPath);
	strcat(spritePath, path);
	tiles = SDL_LoadBMP(spritePath);
}

void Room::createBackground(int** tileMap) {
	SDL_Surface *bg = SDL_CreateRGBSurface(0, 256, 256, 32, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			SDL_Rect src{ tileMap[i][j] * 16, 0, 16, 16 };
			SDL_Rect dst{ i * 16, j * 16, 16, 16 };
			SDL_BlitSurface(tiles, &src, bg, &dst);
		}
	}
	background = SDL_CreateTextureFromSurface(renderer, bg);
	SDL_FreeSurface(bg);
}

void Room::drawBackground()
{
	SDL_RenderCopy(renderer, background, NULL, NULL);
}