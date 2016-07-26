#pragma once

#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(int x, int y, char *path);
	~Player();
	void moveRight();
	void moveUp();
	void moveLeft();
	void moveDown();
	virtual void draw(SDL_Surface *surface, int w, int h);
private:
	int moveSpeed = 4;
};

