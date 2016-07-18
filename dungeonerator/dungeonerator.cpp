#include <stdio.h>
#include "SDL.h"
#include "Dungeonerator.h"

Dungeonerator::Dungeonerator() {
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("- D U N G E O N E R A T O R -", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, NULL);
	if (!window) {
		printf("Error creating window! %s", SDL_GetError());
		return;
	}
	surface = SDL_GetWindowSurface(window);
	if (!surface) {
		printf("Error creating window surface! %s", SDL_GetError());
		return;
	}
}

Dungeonerator::~Dungeonerator() {
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Dungeonerator::run() {
	while (true) {
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_QUIT:
				return;
			}
		}
		SDL_FillRect(surface, NULL, 0x00CC00);
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

