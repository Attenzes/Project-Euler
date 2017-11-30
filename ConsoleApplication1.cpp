// Project Euler Problem 9
// 29/11/2017
//
// Special Pythagorean triple
// Find the product abc, where a + b + c = 1000 and a, b, and c are a pythagorean triplet whereby a^2 + b^2 = c^2
//
// Features:
// - Same input validation without overflow checks
// - Allows user to insert any value of d to find product abc, where a, b, and c are related by a + b + c = d
//
// Note: This is a more brute force method, when d is set to 200000 it already takes about 15 seconds, 400000 about a minute and the rest far too long
// For fun: When d = 1,000,000, a = 218750, b = 360000, c = 421250
//

#include <iostream>
#include <iomanip>
#include <string>

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

double powered(double a, short i)	//Returns a x 10^i
{
	double b{a};
	for (; i > 0; i--)
	{
		b *= a;
	}
	return a;
}

unsigned int findLongestRecurdec(std::string &longest_recur, unsigned int user_input)
{
	unsigned int d{};
	unsigned short length_of_recur{};
	unsigned short new_length_of_recur{};
	for (unsigned int i = 1; i < user_input; i++)
	{
		double decnum = 1.0 / i;
		
		bool found_recur = true;
		for (unsigned int j = 1; found_recur == true || j == 15; j++)
		{
			double decnumpowered = powered(decnum, j);
			double difference = decnumpowered - decnum;
			if (difference == floor(difference)) //Difference is an integer (Found recurring decimal)
			{
				found_recur = true;
				length_of_recur = j;
			}
		}
		
		if (new_length_of_recur > length_of_recur)
		{
			length_of_recur = new_length_of_recur;
			d = i;
		}
	}
	return d;
}

int main()
{
	for (unsigned int user_input{1}; user_input != 0;)
	{
		std::cout << "Insert a number to find the value of d for which 1/d contains the longest recurring cycle in its decimal fraction part\n"
			<< "Where d < the number inserted (Enter 0 to exit)" << std::endl;
		std::cin >> user_input;
		if (!validInput());
		else if (user_input == 0) return 0;
		else if (user_input > 5000) std::cout << "Number too large!\n" << std::endl;	//Set limit to 500000
		else
		{
			std::string longest_recur{ "" };
			unsigned int d = findLongestRecurdec(longest_recur, user_input);
			std::cout << "\nThe value of d is: " << d << " where 1/d = " << longest_recur << std::endl;	//Ignore longest_recur for now, not implemented
		}
		std::cout << std::endl;
	}
}