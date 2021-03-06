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

unsigned long long findabc(unsigned long long &a, unsigned long long &b, unsigned long long &c, unsigned long long d)
{
	c = d - a - b;	//Ensures condition a + b + c = d
	for (a = 1; a < c;a++)
	{
		for (b = 1; b <= a; b++) //For this value of a, check all possible values of b and c and check condition a^2 + b^2 = c^2
		{
			c = d - a - b;
			if(a * a + b * b == c * c)
			return (a * b * c);
		}
		b = 1;
		c = d - a - b + 1;	//Next smallest value of c that will be checked (Exit if this c is definitely > a)
	}
	return 0;
}

int main()
{
	for (unsigned int user_input{1}; user_input != 0;)
	{
		std::cout << "Insert number (500000 or below) to find abc, where a + b + c = d and a^2 + b^2 = c^2 (Enter 0 to exit)" << std::endl;
		std::cin >> user_input;
		if (!validInput());
		else if (user_input == 0) return 0;
		else if (user_input > 500000) std::cout << "Number too large!\n" << std::endl;	//Set limit to 500000
		else
		{
			unsigned long long a{}, b{}, c{};
			unsigned long long abc{};
			abc = findabc(a, b, c, user_input); //Function sets the values of a, b and c that is found to satisfy the required conditions
			if (abc == 0) std::cout << "No real integer solutions found!\n" << std::endl;
			else
			{
				unsigned long long temp{ a }; //Just for appearance, show the larger number as b so a, b, c and in ascending order
				a = b;
				b = temp;
				std::cout << "Product abc = " << abc << " where a = " << a << " b = " << b << " c = " << c << "\n" << std::endl;
			}
		}
	}
}