#include "functions.h"
#include "random.h"
#include "characters.h"

char pickChar(std::vector<char> charVector, int randomType)
{
	unsigned int temp = getRandomNum(randomType);
	if (randomType == 0 || randomType == 1) // rand.
	{
		unsigned int index = ((double)temp / RAND_MAX) * (charVector.size()-1); // review casting, scaling.
		return charVector[index];
	}
	else if (randomType == 2) // rand_s.
	{
		unsigned int index = ((double)temp / UINT_MAX) * (charVector.size() - 1); // review casting, scaling.
		return charVector[index];
	}
}

std::string generatePassword(int passwordLength, int randomType)
{
	std::string password;
	char tempChar, prevChar = '\0';
	int mod4, prevMod4 = 9;
	setSeed(randomType, NULL);
	for (int i = 0; i < passwordLength; i++)
	{
		do {
			unsigned int temp = getRandomNum(randomType);
			mod4 = temp % 4;
			if (mod4 == 0) // lowercase letters.
			{
				tempChar = pickChar(charLowerCase, randomType);
			}
			else if (mod4 == 1) // uppercase letters.
			{
				tempChar = pickChar(charUpperCase, randomType);
			}
			else if (mod4 == 2) // numbers.
			{
				tempChar = pickChar(numbers, randomType);
			}
			else // special characters.
			{
				tempChar = pickChar(special, randomType);
			}
		} while (tempChar == prevChar || mod4 == prevMod4);
		password.push_back(tempChar);
		prevChar = tempChar;
		prevMod4 = mod4;
	}
	return password;
}