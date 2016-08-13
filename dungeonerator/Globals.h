#pragma once
#include <string>
#include "SDL.h"

// Please think very hard before putting anything here. I have decided to put
// sprPath and renderer only because I noticed I had created a huge tree of
// constructors passing these to every object in the game, and then had started
// storing them seperately in each object so that I wouldn't also be passing
// them into each method individually (in other words, using them as globals
// anyways, so that it was pointless not to make them globals.)

// I'm still not convinced it's a good idea but it's better than that.

// They are both initialized in Dungeonerator's constructor.

extern std::string SPR_PATH;
extern SDL_Renderer *RENDERER;