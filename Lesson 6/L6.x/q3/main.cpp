/*
 Quizz 3:
	Complete the following program by writing the passOrFail() function,
	which should return true for the first 3 calls, and false thereafter.
	Do this without modifying the main() function.
*/

#include <iostream>

bool passOrFail();

int main()
{
	std::cout << "User #1: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "User #2: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "User #3: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "User #4: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "User #5: " << (passOrFail() ? "Pass\n" : "Fail\n");

	return 0;
}

bool passOrFail()
{
	static int cnt { 0 };

	if (cnt < 3)
	{
		cnt++;
		return true;
	}
	else
		return false;
}