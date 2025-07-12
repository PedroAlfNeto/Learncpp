/*
 Quizz 1:

 Question #1

Write a class named MyString that holds a std::string. 
Overload operator<< to output the string. 
Overload operator() to return the substring that starts at the index of the 
first parameter (as a MyString). The length of the substring should be defined 
    by the second parameter.

The following code should run:
*/

#include <iostream>
#include <string>
#include <cassert>

class MyString {
   private:
    std::string m_str{"Hello, world!"};

   public:
    MyString (std::string str): m_str{str}{};
    friend std::ostream& operator<<(std::ostream& out, const MyString& str);

    MyString operator() (std::size_t start, std::size_t n_chars) const {
        assert(start >= 0);
        assert(start + n_chars <= static_cast<std::size_t>(m_str.length()) && "MyString::operator(int, int): Substring is out of range");
        return m_str.substr(start,n_chars);
    } 
};

std::ostream& operator<<(std::ostream& out, const MyString& str) {
    return out << str.m_str;
}

int main() {
    MyString s{"Hello, world!"};
    std::cout << s(7, 5) << '\n';  // start at index 7 and return 5 characters

    return 0;
}