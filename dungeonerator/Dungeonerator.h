#pragma once
#include "SDL.h"
#include "overworld.h"

class Dungeonerator {
public:
	Dungeonerator();
	~Dungeonerator();
	void run();
private:
	SDL_Window *window;
	SDL_Surface *surface;
	char *path;
	overworld *o;
};
