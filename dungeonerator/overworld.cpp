#include "overworld.h"
#include <stdlib.h>
//Please refer to the Biome Types file on the github with regards to biome numbers and properties

overworld::overworld()
{
	//later these will be selectable from the start screen
	mapwidth = 16;
	mapheight = 16;
	biomeNumber = 8; 

	mapsize = mapwidth*mapheight;

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
	
	//start placing the biomes we have picked
	//place mountains first
	if (biomeList[4])
	{
		point node;
		if (rand() % 2 == 1) node = { 0,0 };
		else node = { 15,0 };

		biomeGrid[node.x][node.y] = 4;
		int biomesize = 20 + (rand() % 10) + (rand() % 10); //random value between 20 and 40, likely to be close to 30
		int a = 1; //number of points we have assigned to the biome so far
		point biomePoints[40];
		while (a < biomesize)
		{
			for (int i = 0; i < a; i++)
			{
				//check the points adjacent to biomePoints[a] could be added to the biome. if so, has a chance to add them
				//left point
				if (biomePoints[a].x > 0)
				{
					if (biomeGrid[biomePoints[a].x - 1][biomePoints[a].y] == 0 && rand() % 2 == 1)
					{
						biomeGrid[biomePoints[a].x - 1][biomePoints[a].y] = 4;
						a++;
						if (a == biomesize) break;
					}
				}
				//right point
				if (biomePoints[a].x < 15)
				{
					if (biomeGrid[biomePoints[a].x + 1][biomePoints[a].y] == 0 && rand() % 2 == 1)
					{
						biomeGrid[biomePoints[a].x + 1][biomePoints[a].y] = 4;
						a++;
						if (a == biomesize) break;
					}
				}
				//up point
				if (biomePoints[a].y > 0)
				{
					if (biomeGrid[biomePoints[a].x][biomePoints[a].y - 1] == 0 && rand() % 2 == 1)
					{
						biomeGrid[biomePoints[a].x][biomePoints[a].y - 1] = 4;
						a++;
						if (a == biomesize) break;
					}
				}
				//down point
				if (biomePoints[a].y < 15)
				{
					if (biomeGrid[biomePoints[a].x][biomePoints[a].y + 1] == 0 && rand() % 2 == 1)
					{
						biomeGrid[biomePoints[a].x][biomePoints[a].y + 1] = 4;
						a++;
						if (a == biomesize) break;
					}
				}
			}
		}
	}
	if (biomeList[7])
	{
		point node;
		node.x = rand() % 16;
		node.y = rand() % 16;
	}
}


overworld::~overworld()
{
}
