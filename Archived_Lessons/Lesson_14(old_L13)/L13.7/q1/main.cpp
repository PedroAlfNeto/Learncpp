/*
 Quizz 1:
 The program below has a lot of redundancy.
 Update the following program to use non-static member initialization and member initializer lists.
*/
#include <iostream>
#include <string>
#include <string_view>

class Ball
{
private:
	std::string_view m_color{"black"};
	const double m_radius{10.0};

public:
	// Default constructor with no parameters
	Ball() = default;

	// Constructor with only color parameter (radius will use default value)
	Ball(std::string_view color)
		: m_color{color}
	{
	}

	// Constructor with only radius parameter (color will use default value)
	Ball(double radius)
		: m_radius{radius}
	{
	}

	// Constructor with both color and radius parameters
	Ball(std::string_view color, double radius)
		: m_color{color}, m_radius{radius}
	{
	}

	void print()
	{
		std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
	}
};

int main()
{
	Ball def;
	def.print();

	Ball blue{"blue"};
	blue.print();

	Ball twenty{20.0};
	twenty.print();

	Ball blueTwenty{"blue", 20.0};
	blueTwenty.print();

	return 0;
}