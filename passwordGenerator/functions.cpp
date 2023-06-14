#include "functions.h"
#include "random.h"
#include "characters.h"

std::string generatePassword(int passwordLength, int randomType)
{
	std::string password;
	char tempChar, prevChar = '\0';
	int temp, prevtemp = 9;
	random rando;
	rando.setSeed(randomType, NULL);
	for (int i = 0; i < passwordLength; i++)
	{
		do {
			temp = rando.getNum(randomType, 0, 3);
			unsigned int index;
			if (temp == 0) // lowercase letters.
			{
				index = rando.getNum(randomType, 0, charLowerCase.size() - 1);
				tempChar = charLowerCase[index];
			}
			else if (temp == 1) // uppercase letters.
			{
				index = rando.getNum(randomType, 0, charUpperCase.size() - 1);
				tempChar = charUpperCase[index];
			}
			else if (temp == 2) // numbers.
			{
				index = rando.getNum(randomType, 0, numbers.size() - 1);
				tempChar = numbers[index];
			}
			else // special characters.
			{
				index = rando.getNum(randomType, 0, special.size() - 1);
				tempChar = special[index];
			}
		} while (tempChar == prevChar || temp == prevtemp);
		//} while (tempChar == prevChar);
		password.push_back(tempChar);
		prevChar = tempChar;
		prevtemp = temp;
	}
	return password;
}