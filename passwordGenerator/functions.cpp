#include "functions.h"
#include "characters.h"

char pickChar(std::vector<char> charVector)
{
	int index = ((double)rand() / RAND_MAX) * (charVector.size()-1);
	return charVector[index];
}

void generatePassword(int passwordLength)
{
	std::string password;
	srand(std::time(nullptr));
	char tempChar, prevChar = '\0';
	int mod4, prevMod4 = 9;
	for (int i = 0; i < passwordLength; i++)
	{
		do {
			mod4 = rand() % 4;
			if (mod4 == 0) // lowercase letters.
			{
				tempChar = pickChar(charLowerCase);
			}
			else if (mod4 == 1) // uppercase letters.
			{
				tempChar = pickChar(charUpperCase);
			}
			else if (mod4 == 2) // numbers.
			{
				tempChar = pickChar(numbers);
			}
			else // special characters.
			{
				tempChar = pickChar(special);
			}
		} while (tempChar == prevChar || mod4 == prevMod4);
		password.push_back(tempChar);
		prevChar = tempChar;
		prevMod4 = mod4;
	}

	std::cout << "\nYour new password:\n";
	std::cout << password << "\n";
}