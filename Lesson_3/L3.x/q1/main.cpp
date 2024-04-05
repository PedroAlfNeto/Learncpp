#include <iostream>

int readNumber()
{
    int val{};
	std::cout << "Please enter a number: ";
	std::cin >> val;
	return val;
}

void writeAnswer(int x)
{
	std::cout << "The sum is: " << x << '\n';
}

int main()
{
	int x {};
	x= readNumber();
	x = x + readNumber();
	writeAnswer(x);

	return 0;
}