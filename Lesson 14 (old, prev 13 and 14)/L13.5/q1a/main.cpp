/*
 Quizz 1: (deprecated by new 14.2.q1)
 a) Write a class named Ball. Ball should have two private member variables with default values: 
 		m_color (“black”) and m_radius (10.0). Ball should provide constructors to set only m_color, 
		set only m_radius, set both, or set neither value. For this quiz question, 
		do not use default parameters for your constructors. 
	Also write a function to print out the color and radius of the ball.

	The following sample (main) program should compile:
*/
#include <iostream>
#include <string>
#include <string_view>

class Ball{
private:
    std::string m_color{"black"};
    double m_radius{10.0};

public:
    // Default constructure
    Ball() = default;

	// Constructor to set only m_color
	Ball(std::string_view c)
	{
		m_color=c;
	}

	// Constructor to set only m_radius
	Ball(double r)	{
		m_radius=r;
	}

	// Constructor to set m_color and m_radius
    Ball(std::string_view c, double r)
	{
		m_color=c;
		m_radius=r;
	}

    void print(){
        std::cout << "color= " << m_color << ", raidus= " << m_radius << '\n';
    }
}; 

int main()
{
	Ball def{};
	def.print();

	Ball blue{ "blue" };
	blue.print();

	Ball twenty{ 20.0 };
	twenty.print();

	Ball blueTwenty{ "blue", 20.0 };
	blueTwenty.print();

	return 0;
}