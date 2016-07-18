#include "overworld.h"
#include <stdlib.h>
//Please refer to the Biome Types file on the github with regards to biome numbers and properties

overworld::overworld()
{
	//later these will be selectable from the start screen
	mapwidth = 16;
	mapheight = 16;
	biomeNumber = 8; 


	for (int i=0;i<16;i++) //fill the array with 0s
	{ 
		for (int j = 0; j < 16; j++)
		{
			biomeGrid[i][j] = 0;
		}
	}
	
	//pick our biomes
	biomeList[0] = false; //no maps should contain blank tiles
	biomeList[1] = true;  //every map contains grassland
	biomeList[2] = true;  //every map contains a village
	int biomespicked = 2; //two biomes have already been picked
	for (int i=3;i<16;i++)
	{
		if (rand()%(16-i)<biomeNumber-biomespicked)
		{
			//select this as one of this map's biomes
			biomespicked += 1;
			biomeList[i] = true;
		}
		else biomeList[i] = false;
	}
}


overworld::~overworld()
{
}
