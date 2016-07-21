#include <stdio.h>
#include <string.h>
#include "SDL.h"
#include "Dungeonerator.h"

Dungeonerator::Dungeonerator() {
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("- D U N G E O N E R A T O R -", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, NULL);
	if (!window) {
		printf("Error creating window! %s", SDL_GetError());
		return;
	}
	surface = SDL_GetWindowSurface(window);
	if (!surface) {
		printf("Error creating window surface! %s", SDL_GetError());
		return;
	}

	path = new char[256];
	strcpy(path, SDL_GetBasePath());
	strcat(path, "spr\\");
	
	o = new overworld();
}

Dungeonerator::~Dungeonerator() {
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Dungeonerator::run() {
	printf("%s\n", path);
	SDL_Surface **biomeTable = new SDL_Surface *[16];
	for (int i = 0; i < 16; i++) {
		char *sprPath = new char[256];
		char *num = new char[16];
		sprPath[0] = 0;
		num[0] = 0;
		strcat(sprPath, path);
		strcat(sprPath, "biome");
		SDL_itoa(i, num, 10);
		strcat(sprPath, num);
		strcat(sprPath, ".bmp");
		biomeTable[i] = SDL_LoadBMP(sprPath);
		delete[] sprPath;
		delete[] num;
	}
	while (true) {
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_QUIT:
				return;
			case SDL_KEYDOWN:
				switch (e.key.keysym.scancode) {
				case SDL_SCANCODE_SPACE:
					delete o;
					o = new overworld();
					break;
				}
			}

		}
		SDL_FillRect(surface, NULL, 0x00CC00);
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 16; j++) {
				SDL_Rect d{ i * 50, j * 50, 50, 50 };
				SDL_BlitScaled(biomeTable[o->getBiome(i, j)], NULL, surface, &d);
			}
		}
		SDL_UpdateWindowSurface(window);
	}
}

int main(int argc, char **argv)
{
	Dungeonerator *d = new Dungeonerator();
	d->run();
	delete d;
    return 0;
}

