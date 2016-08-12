#include <stdio.h>
#include <string.h>
#include <iostream>
#include <time.h>
#include "SDL.h"
#include "Dungeonerator.h"
#include "Room.h"
#include "Player.h"


Dungeonerator::Dungeonerator() {
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("- D U N G E O N E R A T O R -", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, NULL);
	if (!window) {
		printf("Error creating window! %s", SDL_GetError());
		return;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	if (!renderer) {
		printf("Error creating renderer! %s", SDL_GetError());
		return;
	}

	path = new char[256];
	strcpy(path, SDL_GetBasePath());
	strcat(path, "spr\\");
	
	o = new Overworld();
}

Dungeonerator::~Dungeonerator() {
	delete[] path;
	delete o;
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Dungeonerator::run() {
	Room ***map = new Room**[16];
	for (int i = 0; i < 16; i++) {
		map[i] = new Room *[16];
		for (int j = 0; j < 16; j++) {
			map[i][j] = new Room(o->getBiome(i, j), i, j, path, renderer);
		}
	}
	Player *player = new Player(8, 8, path, renderer);
	std::cout << player->getName() << "\n";
	Biome *testBiome = new Biome(path, renderer);
	Room *testRoom = testBiome->createRoom(0, 0);
	while (true) {
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_QUIT:
				return;
			case SDL_KEYDOWN:
				switch (e.key.keysym.scancode) {
				case SDL_SCANCODE_SPACE:
					std::cout << player->getName() << "\n";
					delete o;
					o = new Overworld();
					for (int i = 0; i < 16; i++) {
						for (int j = 0; j < 16; j++) {
							delete map[i][j];
							map[i][j] = new Room(o->getBiome(i, j), i, j, path, renderer);
						}
					}
					break;
				case SDL_SCANCODE_RIGHT:
					player->moveRight(true);
					break;
				case SDL_SCANCODE_UP:
					player->moveUp(true);
					break;
				case SDL_SCANCODE_LEFT:
					player->moveLeft(true);
					break;
				case SDL_SCANCODE_DOWN:
					player->moveDown(true);
					break;
				case SDL_SCANCODE_ESCAPE:
					return;
				}
				break;
			case SDL_KEYUP:
				switch (e.key.keysym.scancode) {
				case SDL_SCANCODE_RIGHT:
					player->moveRight(false);
					break;
				case SDL_SCANCODE_UP:
					player->moveUp(false);
					break;
				case SDL_SCANCODE_LEFT:
					player->moveLeft(false);
					break;
				case SDL_SCANCODE_DOWN:
					player->moveDown(false);
					break;
				}
				break;
			}

		}
		player->moveStep();
		objQ.push(player);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderFillRect(renderer, NULL);
		testRoom->drawBackground();
		while (!objQ.empty()) {
			objQ.top()->draw(renderer, 50, 50);
			objQ.pop();
		}
		SDL_RenderPresent(renderer);
	}
}

int main(int argc, char **argv)
{
	srand(time(NULL));
	Dungeonerator *d = new Dungeonerator();
	d->run();
	delete d;
    return 0;
}

