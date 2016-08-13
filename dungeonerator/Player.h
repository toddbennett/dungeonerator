#pragma once

#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(int x, int y);
	~Player();
	void moveRight(bool b);
	void moveUp(bool b);
	void moveLeft(bool b);
	void moveDown(bool b);
	void moveStep();
	virtual void draw(int w, int h);
private:
	int moveSpeed = 1;
	bool right = false;
	bool up = false;
	bool left = false;
	bool down = false;
};

