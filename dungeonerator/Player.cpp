#include "Player.h"

Player::Player(int x, int y, char *path, SDL_Renderer *renderer) : GameObject(x, y)
{
	char *sprPath = new char[256];
	sprPath[0] = 0;
	strcat(sprPath, path);
	strcat(sprPath, "player.bmp");
	setSprite(sprPath, renderer);
	delete[] sprPath;
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

void Player::draw(SDL_Renderer *renderer, int w, int h)
{
	SDL_Rect d{ x*w/16,y*h/16,w,h };
	SDL_RenderCopy(renderer, texture, NULL, &d);
}