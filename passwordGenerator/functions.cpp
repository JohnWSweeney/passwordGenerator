#include "functions.h"
#include "characters.h"

void setSeed()
{
	srand(std::time(nullptr));
}

int getRandomNum()
{
	return rand() % 4;
}

char pickChar(char *charArray, int size)
{
	int index = ((double)rand() / RAND_MAX) * size;
	return charArray[index];
}

void generatePassword(int passwordLength)
{
	charSrc src;
	std::vector<char> password;
	setSeed();
	for (int i = 0; i < passwordLength; i++)
	{
		int mod4 = getRandomNum();
		char tempChar;

		if (mod4 == 0) // lowercase letters.
		{
			tempChar = pickChar(src.lowerCase, sizeof(src.lowerCase));
		}
		else if (mod4 == 1) // uppercase letters.
		{
			tempChar = pickChar(src.upperCase, sizeof(src.upperCase));
		}
		else if (mod4 == 2) // numbers.
		{
			tempChar = pickChar(src.numbers, sizeof(src.numbers));
		}
		else // special characters.
		{
			tempChar = pickChar(src.special, sizeof(src.special));
		}
		password.push_back(tempChar);
	}

	std::cout << "\nYour new password:\n\n";
	for (int i = 0; i < password.size(); i++)
	{
		std::cout << password[i];
	}
	std::cout << "\n";
}