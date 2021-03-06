// Project Euler Problem 1
// 28/11/2017
// 
// Additional features:
// - Input validation
// - Allows user to input any value, and program finds the sum of multiples of 3 or 5 less than that value
//
// Limitations:
// - Does not check if variables overflow, including input and output
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

unsigned long long findSumOfMultiples3or5(unsigned int user_input)
{
	unsigned long long sum{ 0 };
	for (unsigned int i{ 1 }; i < user_input; i++)
	{
		if ((i % 3) == 0 || (i % 5 == 0))
		{
			sum += i;
		}
	}
	return sum;
}

int main()
{
	for (unsigned int user_input{1}; user_input != 0;)
	{
		std::cout << "Insert the number (Max 4 billion) under which the sum of multiples of 3 or 5 you want to find (Enter 0 to exit)" << std::endl;
		std::cin >> user_input;
		if (!validInput());
		else if (user_input == 0) return 0;
		else
		{
			std::cout << "Sum of the multiples of the number you inputted: " << findSumOfMultiples3or5(user_input) <<"\n" << std::endl;
		}
	}
}