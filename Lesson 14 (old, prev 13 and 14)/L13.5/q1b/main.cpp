/*
 Quizz 1:
 b)  Update your answer to the previous question to use constructors with default parameters. 
 Use as few constructors as possible.

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
	// Constructor to set only m_color (also default constructor)
	Ball(std::string c="black", double r=10.0) //cannot compile with std::string_view here
	{
		m_color=c;
		m_radius={10};
	}

	// Constructor to set only m_radius
	Ball(double r)
	{
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