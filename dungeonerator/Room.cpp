#include <string.h>
#include "Globals.h"
#include "Room.h"

Room::Room(BiomeType biome, int x, int y) : GameObject(x, y)
{
	this->biome = biome;
	switch (biome) {
	case BIO_GRASSLAND:
		setSprite("biome1.bmp");
		break;
	case BIO_VILLAGE:
		setSprite("biome2.bmp");
		break;
	case BIO_FOREST:
		setSprite("biome3.bmp");
		break;
	case BIO_VOLCANO:
		setSprite("biome4.bmp");
		break;
	case BIO_ICE:
		setSprite("biome5.bmp");
		break;
	case BIO_LAKE:
		setSprite("biome6.bmp");
		break;
	case BIO_GRAVEYARD:
		setSprite("biome7.bmp");
		break;
	case BIO_RIVER:
		setSprite("biome8.bmp");
		break;
	case BIO_CASTLE:
		setSprite("biome9.bmp");
		break;
	case BIO_SWAMP:
		setSprite("biome10.bmp");
		break;
	case BIO_RUINS:
		setSprite("biome11.bmp");
		break;
	case BIO_DESERT:
		setSprite("biome12.bmp");
		break;
	case BIO_FARM:
		setSprite("biome13.bmp");
		break;
	case BIO_EARTHQUAKE:
		setSprite("biome14.bmp");
		break;
	case BIO_SKY:
		setSprite("biome15.bmp");
		break;
	default:
		setSprite("biome0.bmp");
		break;
	}
}

Room::~Room()
{
	
}

void Room::setTiles(std::string filename, int n)
{
	const int TILE_SIZE = 16;

	numTiles = n;
	tiles = SDL_LoadBMP((SPR_PATH + filename).c_str());
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
	background = SDL_CreateTextureFromSurface(RENDERER, bg);
	SDL_FreeSurface(bg);
}

void Room::drawBackground()
{
	SDL_RenderCopy(RENDERER, background, NULL, NULL);
}