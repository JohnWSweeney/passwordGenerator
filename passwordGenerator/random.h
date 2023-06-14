#pragma once
#define _CRT_RAND_S
#include <iostream>
#include <stdlib.h>
#include <random>

class random
{
	std::mt19937 mt;
public:
	void seedRand(int randSeed);
	void seedRandSYS();
	int getRandNum(int min, int max);
	unsigned int getRand_sNum(unsigned int min, unsigned int max);
	void initMt(bool rdSeed, int mtSeed);
	unsigned int getMtNum(unsigned int min, unsigned int max);
	void setSeed(int randomType, int seed);
	unsigned int getNum(int randomType, unsigned int min, unsigned int max);
};