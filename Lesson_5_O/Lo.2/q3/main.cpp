/*
 Quizz 2:
 A bitwise rotation is like a bitwise shift, except that any bits shifted off one end are added 
 back to the other end. 
 For example 0b1001u << 1 would be 0b0010u, but a left rotate by 1 would result in 0b0011u instead. 
 Implement a function that does a left rotate on a std::bitset<4>. 
 For this one, it’s okay to use test() and set().
*/

#include <bitset>
#include <iostream>

// "rotl" stands for "rotate left"
std::bitset<4> rotl(std::bitset<4> bits)
{
    //Left bit mask
    std::bitset<4> rotlbit{0b1000};

    //Check bit 3 and save it
    rotlbit &= bits;

    //Shift bitset left
    bits <<= 1;

    //Copy old bit3 to bit0
    bits |= (rotlbit>>3);

    //Alternatively:
        //return (bits<<1|bits>>3);

    return bits;
}

int main()
{
	std::bitset<4> bits1{ 0b0001 };
	std::cout << rotl(bits1) << '\n';

	std::bitset<4> bits2{ 0b1001 };
	std::cout << rotl(bits2) << '\n';

	return 0;
}