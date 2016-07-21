#include <stdlib.h>
#include <time.h>

#include "overworld.h"
//Please refer to the Biome Types file on the github with regards to biome numbers and properties
void overworld::growPoint(int biome,point node, int biomesize, int percentage)
{
	//larger percentage values will create more triangular/diamond shaped biomes, while smaller values will tend to create more snaking, fractal-like shapes
	biomeGrid[node.x][node.y] = biome;
	int a = 1; //number of points we have assigned to the biome so far
	point biomePoints[40];
	for (int i = 0; i < 40; i++) {
		biomePoints[i] = { 0,0 };
	}
	while (a < biomesize)
	{
		for (int i = 0; i < a; i++)
		{
			//check the points adjacent to biomePoints[a] could be added to the biome. if so, has a chance to add them
			//left point
			if (biomePoints[a].x > 0)
			{
				if (biomeGrid[biomePoints[a].x - 1][biomePoints[a].y] == 0 && rand() % 100 < percentage)
				{
					biomeGrid[biomePoints[a].x - 1][biomePoints[a].y] = biome;
					a++;
					if (a == biomesize) break;
				}
			}
			//right point
			if (biomePoints[a].x < 15)
			{
				if (biomeGrid[biomePoints[a].x + 1][biomePoints[a].y] == 0 && rand() % 100 < percentage)
				{
					biomeGrid[biomePoints[a].x + 1][biomePoints[a].y] = biome;
					a++;
					if (a == biomesize) break;
				}
			}
			//up point
			if (biomePoints[a].y > 0)
			{
				if (biomeGrid[biomePoints[a].x][biomePoints[a].y - 1] == 0 && rand() % 100 < percentage)
				{
					biomeGrid[biomePoints[a].x][biomePoints[a].y - 1] = biome;
					a++;
					if (a == biomesize) break;
				}
			}
			//down point
			if (biomePoints[a].y < 15)
			{
				if (biomeGrid[biomePoints[a].x][biomePoints[a].y + 1] == 0 && rand() % 100 < percentage)
				{
					biomeGrid[biomePoints[a].x][biomePoints[a].y + 1] = biome;
					a++;
					if (a == biomesize) break;
				}
			}
		}
	}
}

overworld::overworld()
{
	srand(time(NULL));
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
	point node = { 0, 0 }; //make sure each biome initializes this 
	//place mountains first
	if (biomeList[4])
	{
		if (rand() % 2 == 1) node = { 0,0 };
		else node = { 15,0 };

		int biomesize = 20 + (rand() % 10) + (rand() % 10); //random value between 20 and 40, likely to be close to 30
		//growPoint(4,node, biomesize, 50);
	}
	if (biomeList[5])
	{
		if (rand() % 2 == 1 && biomeGrid[0][0]==0) node = { 0,0 };
		else node = { 15,0 };

		int biomesize = 20 + (rand() % 10) + (rand() % 10); //random value between 20 and 40, likely to be close to 30
		//growPoint(5,node, biomesize, 50);
	}
	//next place graveyard and castle, which require rectangular shapes
	if (biomeList[7])
	{
		int gwidth = 2 + rand() % 2;  //2 or 3 squares wide
		int gheight = 3 + rand() % 2;  //3 or 4 squares tall

		while (!(biomeGrid[node.x][node.y] == 0 &&
			biomeGrid[node.x + gwidth - 1][node.y] == 0 &&
			biomeGrid[node.x][node.y + gheight - 1] == 0 &&
			biomeGrid[node.x + gwidth - 1][node.y + gheight - 1] == 0)) //we can cut into another biome a little bit, but try to minimize it
		{
			node.x = rand() % 16;
			node.y = rand() % 16;
		}
		for (int i = 0; i < gwidth; i++)
		{
			for (int j = 0; j < gheight; j++)
			{
				biomeGrid[i][j] = 7;
			}
		}
	}
	if (biomeList[9])
	{
		while (!(biomeGrid[node.x][node.y] == 0 &&
			biomeGrid[node.x + 2][node.y] == 0 &&
			biomeGrid[node.x][node.y + 2] == 0 &&
			biomeGrid[node.x + 2][node.y + 2] == 0)) //we can cut into another biome a little bit, but try to minimize it
		{
			node.x = rand() % 16;
			node.y = rand() % 16;
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				biomeGrid[i][j] = 9;
			}
		}
	}

}


overworld::~overworld()
{
}

int overworld::getBiome(int x, int y)
{
	return biomeGrid[x][y];
}