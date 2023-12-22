/*
 Question #5:
 a) Write a program that asks for the name and age of two people,
 then prints which person is older.

 The following sample main should compile:
*/

#include <iostream>
#include <string>
#include <string_view>

int main() {
  std::string personA{};
  std::string personB{};
  int ageA{};
  int ageB{};

  std::cout << "Enter the name of person #1: ";
  std::cin >> personA;

  std::cout << "Enter the age of " << personA << ':';
  std::cin >> ageA;
  std::cout << "Enter the name of person #2: ";
  std::cin >> personB;
  std::cout << "Enter the age of" << personB << ':';
  std::cin >> ageB;

  if (ageA < ageB) {
    std::cout << personA << " (age " << ageA << ") is older than " << personB << " (age " << ageB << ").\n";
  } else {
    std::cout << personB << " (age " << ageB << ") is older than " << personA << " (age " << ageA << ").\n";
  }

  return 0;
}