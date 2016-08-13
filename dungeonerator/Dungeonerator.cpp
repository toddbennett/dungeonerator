#include <stdio.h>
#include <string.h>
#include <iostream>
#include <time.h>
#include "SDL.h"
#include "Dungeonerator.h"
#include "Room.h"
#include "Player.h"
#include "Globals.h"

std::string SPR_PATH;
SDL_Renderer *RENDERER;


Dungeonerator::Dungeonerator() {
	srand((unsigned int) time(NULL));
	SDL_Init(SDL_INIT_EVERYTHING);

	SPR_PATH = SDL_GetBasePath();
	SPR_PATH += "spr\\";

	window = SDL_CreateWindow("- D U N G E O N E R A T O R -", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, NULL);
	if (!window) {
		printf("Error creating window! %s", SDL_GetError());
		return;
	}

	RENDERER = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	if (!RENDERER) {
		printf("Error creating renderer! %s", SDL_GetError());
		return;
	}

	o = new Overworld();
}

Dungeonerator::~Dungeonerator() {
	delete o;
	SDL_DestroyRenderer(RENDERER);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Dungeonerator::run() {
	Room ***map = new Room**[16];
	for (int i = 0; i < 16; i++) {
		map[i] = new Room *[16];
		for (int j = 0; j < 16; j++) {
			map[i][j] = new Room(o->getBiome(i, j), i, j);
		}
	}
	Player *player = new Player(8, 8);
	std::cout << player->getName() << "\n";
	Biome *testBiome = new Biome();
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
							map[i][j] = new Room(o->getBiome(i, j), i, j);
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
		SDL_SetRenderDrawColor(RENDERER, 0, 0, 0, 255);
		SDL_RenderFillRect(RENDERER, NULL);
		testRoom->drawBackground();
		while (!objQ.empty()) {
			objQ.top()->draw(50, 50);
			objQ.pop();
		}
		SDL_RenderPresent(RENDERER);
	}
}

int main(int argc, char **argv)
{
	Dungeonerator *d = new Dungeonerator();
	d->run();
	delete d;
    return 0;
}

