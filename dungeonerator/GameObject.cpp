#include "GameObject.h"

GameObject::GameObject(char *sprPath, int x, int y)
{
	sprite = SDL_LoadBMP(sprPath);
	this->x = x;
	this->y = y;
}

GameObject::GameObject(int x, int y) {
	sprite = NULL;
	this->x = x;
	this->y = y;
}

GameObject::~GameObject()
{
	SDL_FreeSurface(sprite);
}

void GameObject::draw(SDL_Surface *surface, int w, int h)
{
	SDL_Rect d{ x*w,y*h,w,h };
	SDL_BlitScaled(sprite, NULL, surface, &d);
}

void GameObject::setSprite(char *sprPath)
{
	if (sprite) {
		SDL_FreeSurface(sprite);
	}
	sprite = SDL_LoadBMP(sprPath);
}