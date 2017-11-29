// Project Euler Problem 5
// 28/11/2017
//
// Additional features:
// - Input validation
// - User can choose the range of values from 1 to whichever integer they like to find the Lowest Common Multiple
//
// Limitations:
// - Does not check if variables overflow, including input and output (Overflow starts when user_input > 47)
//

#include <iostream>

bool validInput()
{
	if (!std::cin || !(std::cin.peek() == '\n'))
	{
		std::cout << "Invalid input, please try again\n" << std::endl;
		std::cin.clear();
		std::cin.ignore(1024, '\n');
		return false;
	}
	return true;
}

unsigned long long findLCM(unsigned int user_input)
{
	unsigned long long LCM{ 1 };
	for (unsigned int i{ 1 }; i <= user_input; i++)
	{
		if (LCM % i == 0);
		else
		{
			bool loop = true;
			for (unsigned int j{ 2 }; loop; j++) //Finds lowest multiple needed for LCM % i, and multiplies LCM by it
			{
				if ((LCM * j) % i != 0);	//loop
				else
				{
					LCM *= j;
					loop = false;
				}
			}
		}
	}
	return LCM;
}

int main()
{
	for (unsigned int user_input{ 1 }; user_input != 0;)
	{
		std::cout << "(Enter 0 to exit) Finds the smallest positive number divisble by all of the numbers from 1 to: ";
		std::cin >> user_input;
		if (!validInput());
		else if (user_input == 0) return 0;
		else
		{
			std::cout << "Smallest positive number divisible by all of the nubmers from 1 to " << user_input << " is " << findLCM(user_input) << "\n" << std::endl;
		}
	}
	return 0;
}
