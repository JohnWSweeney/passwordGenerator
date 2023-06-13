#include "random.h"

void setSeed(int randomType, int seed)
{
	switch (randomType)
	{
	case 0: // user seeded rand.
		srand(seed);
		break;
	case 1: // system time seeded rand.
		srand(std::time(nullptr));
		break;
	case 2: // no seed for rand_s.
		// placeholder
		break;
	case 3:
		// mersene twister.
		break;
	//default:
		//
	}
}

unsigned int getRandomNum(int randomType)
{
	if (randomType == 0 || randomType == 1) // rand.
	{
		return rand();
	}
	else if (randomType == 2) // rand_s.
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
			return num;
		}
	}
	else
	{
		// ?
	}
	

}