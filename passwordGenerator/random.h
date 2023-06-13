#pragma once
#define _CRT_RAND_S
#include <iostream>
#include <stdlib.h>

void setSeed(int randomType, int seed);
unsigned int getRandomNum(int randomType);