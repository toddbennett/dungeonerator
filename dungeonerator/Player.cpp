#include "Player.h"

Player::Player(int x, int y, char *path) : GameObject(x, y)
{
	char *sprPath = new char[256];
	sprPath[0] = 0;
	strcat(sprPath, path);
	strcat(sprPath, "player.bmp");
	setSprite(sprPath);
	delete[] sprPath;
}

Player::~Player()
{
}

void Player::moveRight()
{
	x += moveSpeed;
}

void Player::moveUp()
{
	y -= moveSpeed;
}

void Player::moveLeft()
{
	x -= moveSpeed;
}

void Player::moveDown()
{
	y += moveSpeed;
}

void Player::draw(SDL_Surface *surface, int w, int h)
{
	SDL_Rect d{ x*w/16,y*h/16,w,h };
	SDL_BlitScaled(sprite, NULL, surface, &d);
}