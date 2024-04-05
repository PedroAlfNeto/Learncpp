/*
 Question #5:
 a) Write a program that asks for the name and age of two people,
 then prints which person is older.

 The following sample main should compile:
*/

#include <iostream>
#include <string>
#include <string_view>

std::string getName(int num) {
  std::string name{};
  std::cout << "Enter the name of person" << num << ": ";
  std::getline(std::cin >> std::ws, name);

  return name;
}

int getAge(std::string_view name) {
  int age{};
  std::cout << "Enter the age of " << name << ": ";
  std::cin >> age;

  return age;
}

void printOlder(std::string_view name1, int age1, std::string_view name2,
                int age2) {
  if (age1 > age2) {
    std::cout << name1 << " (age " << age1 << ") is older than " << name2
              << " (age " << age2 << ").\n";
  } else {
    std::cout << name2 << " (age " << age2 << ") is older than " << name1
              << " (age " << age1 << ").\n";
  }
}

int main() {
  const std::string personA{getName(1)};
  const int ageA{getAge(personA)};
  const std::string personB{getName(2)};
  const int ageB{getAge(personB)};

  printOlder(personA, ageA, personB, ageB);

  return 0;
}