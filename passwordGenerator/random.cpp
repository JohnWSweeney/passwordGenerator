#include "random.h"

void random::seedRand(int randSeed)
{
	srand(randSeed);
}

void random::seedRandSYS()
{
	srand(std::time(nullptr));
}

int random::getRandNum(int min, int max)
{
	return ((double)rand() / RAND_MAX) * (max + 1 - min) + min; // review distribution algorithm.
}

unsigned int random::getRand_sNum(unsigned int min, unsigned int max)
{
	unsigned int num;
	errno_t err;
	err = rand_s(&num);
	if (err != 0)
	{
		std::cout << "rand_s failed with error: " << err << '\n';
	}
	else
	{
		return (unsigned int) ((double)num / ((double)UINT_MAX + min) * (double)max + 1) + min; // review distribution algorithm.
	}
}

void random::initMt(bool rdSeed, int mtSeed)
{
	if (rdSeed == true) // random_device seeded.
	{
		std::random_device rd;
		mt.seed(rd());
	}
	else // seeded with user int.
	{
		mt.seed(mtSeed);
	}
}

unsigned int random::getMtNum(unsigned int min, unsigned int max)
{
	std::uniform_int_distribution<> dist(min, max);
	return dist(mt);
}

void random::setSeed(int randomType, int seed)
{
	switch (randomType)
	{
	case 0: // user seeded rand.
		this->seedRand(seed);
		break;
	case 1: // system time seeded rand.
		this->seedRandSYS();
		break;
	case 2: // placeholder, no seed for rand_s.
		break;
	case 3: // randon_device seeded mersenne twister.
		this->initMt(true, NULL);
		break;
	case 4: // user seeded mersenne twister.
		this->initMt(false, seed);
		break;
	}
}

unsigned int random::getNum(int randomType, unsigned int min, unsigned int max)
{
	switch (randomType)
	{
	case 0: // return number from user seeded rand.
		return this->getRandNum(min, max);
		break;
	case 1:  // return number from
		return this->getRandNum(min, max);
		break;
	case 2:  // return number from rand_s.
		return this->getRand_sNum(min, max);
		break;
	case 3:  // return number from randon_device seeded mersenne twister.
		return this->getMtNum(min, max);
		break;
	case 4:  // return number from user seeded mersenne twister.
		return this->getMtNum(min, max);
		break;
	}
}