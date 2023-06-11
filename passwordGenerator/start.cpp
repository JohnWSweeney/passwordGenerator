#include "start.h"
#include "functions.h"

void getInput(std::vector < std::string> &tokens)
{
	tokens.clear();
	do {
		std::string input, tempStr;
		std::getline(std::cin, input, '\n');
		std::stringstream strStream(input);
		while (getline(strStream, tempStr, ' '))
		{
			tokens.push_back(tempStr);
		}
	} while (tokens.empty());
}

void startMenu(bool &running)
{
	std::cout << "\nHow many characters do you want your password to have?\n";
	std::vector<std::string> tokens;
	getInput(tokens);
	if (tokens[0] == "exit")
	{
		running = false;
	}
	else
	{
		try {
			int passwordLength = std::stoi(tokens[0]);
			if (passwordLength < 8)
			{
				throw 20;
			}
			generatePassword(passwordLength);
		}
		catch (std::invalid_argument)
		{
			std::cout << "Invalid input for password length.\n";
		}
		catch (std::out_of_range)
		{
			std::cout << "Password length is out of range.\n";
		}
		catch (int e)
		{
			std::cout << "Password must have at least 8 characters.\n";
		}
	}

	
}