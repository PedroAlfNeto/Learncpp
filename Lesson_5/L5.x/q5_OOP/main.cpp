/*
 Question #5: (pneto: now do it in OOP style)
 a) Write a program that asks for the name and age of two people,
 then prints which person is older.

 The following sample main should compile:
*/

#include <iostream>
#include <string>
#include <string_view>

class Person {
 public:
  Person(){};
  Person(std::string_view name, int age) : m_name{name}, m_age{age} {}
  void setName(int num) {
    std::string name{};
    std::cout << "Enter the name of person " << num << ": ";
    std::getline(std::cin >> std::ws, name);  // capture name with white spaces
    m_name = name;
  }
  void setAge() {
    int age{};
    std::cout << "Enter the age of " << m_name << ": ";
    std::cin >> age;
    m_age = age;
  }
  std::string_view getName() { return m_name; }
  int getAge() { return m_age; }

 private:
  std::string m_name{};
  int m_age{};
};

void printOlder(Person person1, Person person2) {

  // More efficient for int to call only once and copy
  // More efficient for strings to call with string_view once and dont copy
  const int age1 = person2.getAge();
  const int age2 = person2.getAge();

  if (age1 > age2) {
    std::cout << person1.getName() << " (age " << age1 << ") is older than "
              << person2.getName() << " (age " << age2 << ").\n";
  } else if (age1 < age2) {
    std::cout << person2.getName() << " (age " << age1 << ") is older than "
              << person1.getName() << " (age " << age1 << ").\n";
  }  
  else {
    std::cout << person2.getName() << " (age " << age1 << ") is older than "
              << person1.getName() << " (age " << age1 << ").\n";
  }
}

int main() {

  Person personA{"Tesesa", 45};
  Person personB;
  personB.setName(2);
  personB.setAge();

  printOlder(personA, personB);

  return 0;
}