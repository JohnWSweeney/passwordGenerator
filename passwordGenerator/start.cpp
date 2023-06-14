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
	else if (tokens[0] == "wall")
	{
		int wallOfTextLength = 1000000;
		std::string wallOfText = generatePassword(wallOfTextLength, 3);
		std::cout << wallOfText;
	}
	else
	{
		try {
			int passwordLength = std::stoi(tokens[0]);
			if (passwordLength < 8)
			{
				throw 20;
			}
			std::string randPassword = generatePassword(passwordLength, 1);
			std::string rand_sPassword = generatePassword(passwordLength, 2);
			std::string mtPassword = generatePassword(passwordLength, 3);
			std::cout << "\nPRNG:\t\tPassword:\n";
			std::cout << "rand\t\t" << randPassword << '\n';
			std::cout << "rand_s\t\t" << rand_sPassword << '\n';
			std::cout << "mt19937\t\t" << mtPassword << '\n';
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