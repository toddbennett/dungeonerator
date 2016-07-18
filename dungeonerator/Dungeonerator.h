#pragma once
#include "SDL.h"

class Dungeonerator {
public:
	Dungeonerator();
	~Dungeonerator();
	void run();
private:
	SDL_Window *window;
	SDL_Surface *surface;
};
