#include "Biome.h"

Biome::Biome(char *sprPath, SDL_Renderer *renderer)
{
	this->sprPath = sprPath;
	this->renderer = renderer;
	type = BIO_BLANK;
	low_x = -1;
	low_y = -1;
	high_x = -1;
	high_y = -1;
}

Biome::~Biome()
{

}

Room *Biome::createRoom(int x, int y)
{
	Room *r = new Room(type, x, y, sprPath, renderer);
	r->setTiles("biome0.bmp", 1);
	int **map = new int*[16];
	for (int i = 0; i < 16; i++) {
		map[i] = new int[16];
		for (int j = 0; j < 16; j++) {
			map[i][j] = 0;
		}
	}
	r->createBackground(map);
	for (int i = 0; i < 16; i++) {
		delete[] map[i];
	}
	delete[] map;
	rooms.push_back(r);
	return r;
}