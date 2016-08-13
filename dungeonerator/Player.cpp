#include "Globals.h"
#include "Player.h"

Player::Player(int x, int y) : GameObject(x, y)
{
	setSprite("player.bmp");
}

Player::~Player()
{
}

void Player::moveRight(bool b)
{
	right = b;
}

void Player::moveUp(bool b)
{
	up = b;
}

void Player::moveLeft(bool b)
{
	left = b;
}

void Player::moveDown(bool b)
{
	down = b;
}

void Player::moveStep()
{
	if (right) {
		x += moveSpeed;
	}
	if (up) {
		y -= moveSpeed;
	}
	if (left) {
		x -= moveSpeed;
	}
	if (down) {
		y += moveSpeed;
	}
}

void Player::draw(int w, int h)
{
	SDL_Rect d{ x*w/16,y*h/16,w,h };
	SDL_RenderCopy(RENDERER, texture, NULL, &d);
}