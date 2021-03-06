#pragma once
#include <queue>
#include <vector>
#include "SDL.h"
#include "Overworld.h"
#include "GameObject.h"

class Dungeonerator {
public:
	Dungeonerator();
	~Dungeonerator();
	void run();
private:
	SDL_Window *window;
	Overworld *o;
	GameObject *objList;
	std::priority_queue<GameObject *, std::vector<GameObject *>, DepthComparator> objQ;
};
