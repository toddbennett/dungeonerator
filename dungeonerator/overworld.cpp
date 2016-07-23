#include <stdlib.h>
#include <time.h>

#include "overworld.h"
//Please refer to the Biome Types file on the github with regards to biome numbers and properties
point overworld::getFreePoint()
{
	point freePoint = { rand() % 16,rand() % 16 };
	while (biomeGrid[freePoint.x][freePoint.y] != 0) freePoint = { rand() % 16,rand() % 16 };
	return freePoint;
}

void overworld::growPoint(int biome,point nodule, int biomesize, int percentage)
{
	//larger percentage values will create more triangular/diamond shaped biomes, while smaller values will tend to create more snaking, fractal-like shapes
	biomeGrid[nodule.x][nodule.y] = biome;
	int a = 1; //number of points we have assigned to the biome so far
	int b = 0;//make sure we don't get stuck in this loop
	point biomePoints[40];

	biomePoints[0] = { nodule.x,nodule.y };
	while (a < biomesize && b < 300)
	{
		b++;
		for (int i = 0; i < a; i++)
		{
			//check the points adjacent to biomePoints[i] could be added to the biome. if so, has a chance to add them
			//left point
			if (biomePoints[i].x > 0)
			{
				if (biomeGrid[biomePoints[i].x - 1][biomePoints[i].y] == 0 && rand() % 100 < percentage)
				{
					biomeGrid[biomePoints[i].x - 1][biomePoints[i].y] = biome;
					biomePoints[a] = { biomePoints[i].x - 1,biomePoints[i].y };
					a++;
					if (a == biomesize) break;
				}
			}
			//right point
			if (biomePoints[i].x < 15)
			{
				if (biomeGrid[biomePoints[i].x + 1][biomePoints[i].y] == 0 && rand() % 100 < percentage)
				{
					biomeGrid[biomePoints[i].x + 1][biomePoints[i].y] = biome;
					biomePoints[a] = { biomePoints[i].x + 1,biomePoints[i].y };
					a++;
					if (a == biomesize) break;
				}
			}
			//up point
			if (biomePoints[i].y > 0)
			{
				if (biomeGrid[biomePoints[i].x][biomePoints[i].y - 1] == 0 && rand() % 100 < percentage)
				{
					biomeGrid[biomePoints[i].x][biomePoints[i].y - 1] = biome;
					biomePoints[a] = { biomePoints[i].x,biomePoints[i].y-1 };
					a++;
					if (a == biomesize) break;
				}
			}
			//down point
			if (biomePoints[i].y < 15)
			{
				if (biomeGrid[biomePoints[i].x][biomePoints[i].y + 1] == 0 && rand() % 100 < percentage)
				{
					biomeGrid[biomePoints[i].x][biomePoints[i].y + 1] = biome;
					biomePoints[a] = { biomePoints[i].x,biomePoints[i].y + 1};
					a++;
					if (a == biomesize) break;
				}
			}
		}
	}
}

void overworld::fillPoint(int biome)
{
	//fillPoint checks the grid for small gaps and crevices and fills them in
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			//finish me later pls
		}
	}
}

overworld::overworld()
{
	srand(time(NULL));
	//later these will be selectable from the start screen
	mapwidth = 16;
	mapheight = 16;
	biomeNumber = 10; 

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

		int biomesize = 20 + (rand() % 5) + (rand() % 5); //random value between 20 and 30, likely to be close to 25
		growPoint(4,node, biomesize, 50);
	}
	if (biomeList[5])
	{
		if (biomeGrid[0][0] == 0)
		{
			if (biomeGrid[15][0]!=0)	node = { 0,0 };
			else if (rand() % 2 == 1)	node = { 0,0 };
			else node = { 15,0 };
		}
		else
		{
			node = { 15,0 };
			biomeGrid[15][0] = 0;
		}

		int biomesize = 20 + (rand() % 5) + (rand() % 5); //random value between 20 and 30, likely to be close to 25
		growPoint(5, node, biomesize, 50);
	}
	//next place graveyard and castle, which require rectangular shapes
	if (biomeList[7])
	{
		int gwidth = 2 + rand() % 2;  //2 or 3 squares wide
		int gheight = 3 + rand() % 2;  //3 or 4 squares tall
		node.x = rand() % (16 - gwidth);
		node.y = rand() % (16 - gheight);

		while (!(biomeGrid[node.x][node.y] == 0 &&
			biomeGrid[node.x + gwidth - 1][node.y] == 0 &&
			biomeGrid[node.x][node.y + gheight - 1] == 0 &&
			biomeGrid[node.x + gwidth - 1][node.y + gheight - 1] == 0)) //we can cut into another biome a little bit, but try to minimize it
		{
			node.x = rand() % (16-gwidth);
			node.y = rand() % (16-gheight);
		}
		for (int i = 0; i < gwidth; i++)
		{
			for (int j = 0; j < gheight; j++)
			{
				biomeGrid[i + node.x][j + node.y] = 7;
			}
		}
	}
	if (biomeList[9])
	{
		node = { rand() % 13,rand() % 13 };
		while (!(biomeGrid[node.x][node.y] == 0 &&
			biomeGrid[node.x + 2][node.y] == 0 &&
			biomeGrid[node.x][node.y + 2] == 0 &&
			biomeGrid[node.x + 2][node.y + 2] == 0)) //we can cut into another biome a little bit, but try to minimize it
		{
			node.x = rand() % 13;
			node.y = rand() % 13;
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				biomeGrid[i+node.x][j+node.y] = 9;
			}
		}
	}
	//next place the lake
	if (biomeList[6])
	{
			node = { rand() % 16,15 };
				while (biomeGrid[node.x][node.y] != 0)
				{
					node = { rand() % 16,15 };
				}
				growPoint(6, node, 20, 80);
	}
	//river
	if (biomeList[8])
	{

		point target;  //the mouth of the river
		//is there a lake?
		if (biomeList[6])
		{
			target = node;//our target is the centre of the lake
		}
		else
		{
			target = { rand() % 16,15 };
			while (biomeGrid[target.x][target.y]!= 0) target = { rand() % 16,15 };
		}
		//find a spot for the source of the river
		node = { rand() % 16,0 };
		while (biomeGrid[node.x][node.y] != 0)
		{
			for (int i = 0; biomeGrid[node.x][node.y] != 0 && i < 100; i++)
			{
				node = { rand() % 16,0 };
			}
			node.y = node.y + 1;
		}
		biomeGrid[node.x][node.y] = 8;
		//worm our way down to the bottom
		int b = 0; //make sure we don' get stuck forever
		while (node.y != target.y && b<1000)
		{
			//should we step down?
			if (biomeGrid[node.x][node.y + 1] == 0 && node.y < target.y && rand()%2 ==1)
			{
				node.y++;
				biomeGrid[node.x][node.y] = 8;
			}
			//should we step right?
			if (biomeGrid[node.x+1][node.y] == 0 && node.x < target.x && rand() % 2 == 1)
			{
				node.x++;
				biomeGrid[node.x][node.y] = 8;
			}
			//should we step left?
			if (biomeGrid[node.x - 1][node.y] == 0 && node.x > target.x && rand() % 2 == 1)
			{
				node.x--;
				biomeGrid[node.x][node.y] = 8;
			}
			//should we stop?
			if ((node.x == target.x && node.y == target.y) || biomeGrid[node.x + 1][node.y] == 6 || biomeGrid[node.x - 1][node.y] == 6 || biomeGrid[node.x][node.y + 1] == 6) break;
			b++;
		}
	}
	//the rest are all simple
	if (biomeList[2])
	{
		node = getFreePoint();
		growPoint(2, node, 5 + rand() % 5, 50);
	}
	if (biomeList[3])
	{
		node = getFreePoint();
		growPoint(3, node, 15 + rand() % 20, 50);
	}
	if (biomeList[10])
	{
		node = getFreePoint();
		growPoint(10, node, 15 + rand() % 20, 50);
	}
	if (biomeList[11])
	{
		node = getFreePoint();
		growPoint(11, node, 15 + rand() % 20, 70);
	}
	if (biomeList[12])
	{
		node = getFreePoint();
		growPoint(12, node, 15 + rand() % 20, 50);
	}
	if (biomeList[13])
	{
		node = getFreePoint();
		growPoint(13, node, 15 + rand() % 20, 40);
	}
	if (biomeList[14])
	{
		node = getFreePoint();
		growPoint(14, node, 15 + rand() % 20, 40);
	}
	if (biomeList[15])
	{
		node = getFreePoint();
		growPoint(15, node, 15 + rand() % 20, 40);
	}
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (biomeGrid[i][j] == 0) biomeGrid[i][j] = 1;
		}
	}
}


overworld::~overworld()
{
}

Biome overworld::getBiome(int x, int y)
{
	switch (biomeGrid[x][y]) {
	case 1:
		return BIO_GRASSLAND;
	case 2:
		return BIO_VILLAGE;
	case 3:
		return BIO_FOREST;
	case 4:
		return BIO_VOLCANO;
	case 5:
		return BIO_ICE;
	case 6:
		return BIO_LAKE;
	case 7:
		return BIO_GRAVEYARD;
	case 8:
		return BIO_RIVER;
	case 9:
		return BIO_CASTLE;
	case 10:
		return BIO_SWAMP;
	case 11:
		return BIO_RUINS;
	case 12:
		return BIO_DESERT;
	case 13:
		return BIO_FARM;
	case 14:
		return BIO_EARTHQUAKE;
	case 15:
		return BIO_SKY;
	default:
		return BIO_BLANK;
	}
}