#include <algorithm> // std::sort
#include <cstddef> // std::size_t
#include <iostream>
#include <string>
#include <vector>

struct Student
{
  std::string name{};
  int grade{};
};

int getNumberOfStudents();




std::vector<Student> getStudents()
{
  using Students = std::vector<Student>;

  int numberOfStudents{ getNumberOfStudents() };

  // Create a vector with numberOfStudents elements.
  Students students(static_cast<Students::size_type>(numberOfStudents));

  std::cout << "Size of student vector: "<<students.size();

  int studentNumber{ 1 };

  for (auto& student : students)
  {
    std::cout << "Enter name #" << studentNumber << ": ";
    std::cin >> student.name;
    std::cout << "Enter grade #" << studentNumber << ": ";
    std::cin >> student.grade;

    ++studentNumber;
  }

  return students;
}

// Pass by reference to avoid slow copies.
bool compareStudents(const Student& a, const Student& b)
{
  return (a.grade > b.grade);
}

int main()
{
  auto students{ getStudents() };

  std::sort(students.begin(), students.end(), compareStudents);

  // Print out all the names
  for (const auto& student : students)
  {
    std::cout << student.name << " got a grade of " << student.grade << '\n';
  }

  return 0;
}

int getNumberOfStudents()
{
  int numberOfStudents{};

  do
  {
    std::cout << "How many students do you want to enter? ";
    std::cin >> numberOfStudents;
  } while (numberOfStudents <= 0);

  return numberOfStudents;
}