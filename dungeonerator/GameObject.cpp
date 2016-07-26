#include "GameObject.h"
#include <string>

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

int GameObject::getDepth()
{
	return depth;
}

std::string getName()
{
//100% sure this is a bad implementation

	char* consonant[21];
	char* vowel[5];
	std::string returnstring = "";
	//consonant and vowel arrays
	consonant[0] = "b";
	consonant[1] = "c";
	consonant[2] = "d";
	consonant[3] = "f";
	consonant[4] = "g";
	consonant[5] = "h";
	consonant[6] = "j";
	consonant[7] = "k";
	consonant[8] = "l";
	consonant[9] = "m";
	consonant[10] = "n";
	consonant[11] = "p";
	consonant[12] = "q";
	consonant[13] = "r";
	consonant[14] = "s";
	consonant[15] = "t";
	consonant[16] = "v";
	consonant[17] = "w";
	consonant[18] = "x";
	consonant[19] = "y";
	consonant[20] = "z";

	vowel[0] = "a";
	vowel[1] = "e";
	vowel[2] = "i";
	vowel[3] = "o";
	vowel[4] = "u";

	if (rand() % 2 == 0) returnstring = consonant[rand() % 21];
	returnstring = returnstring + vowel[rand() % 5];
	if (rand() % 2 == 0) returnstring = returnstring + consonant[rand() % 21];
	returnstring = returnstring + consonant[rand() % 21];
	returnstring = returnstring + vowel[rand() % 5];
	if (rand() % 2 == 0) returnstring = returnstring + consonant[rand() % 21];
	return returnstring;
}

void GameObject::setSprite(char *sprPath)
{
	if (sprite) {
		SDL_FreeSurface(sprite);
	}
	sprite = SDL_LoadBMP(sprPath);
}