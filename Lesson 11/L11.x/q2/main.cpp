/*
 Quizz 2:
 Create a struct that holds a student’s first name and grade (on a scale of 0-100).
 Ask the user how many students they want to enter.
 Create a std::vector to hold all of the students.
 Then prompt the user for each name and grade.
 Once the user has entered all the names and grade pairs, sort the list by grade (highest first).
 Then print all the names and grades in sorted order.
*/
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm> // for std::sort

constexpr std::streamsize max_buffer{std::numeric_limits<std::streamsize>::max()};

// Struct holds student’s first name and grade (on a scale of 0-100).
struct student_data
{
    std::string name{};
    int grade{};
};

// Queries number of students to user
int getStudentsNum();

// Queries number of students to user
void getStudentData(std::vector<student_data>& student_list);

// Resets Cin status and clears buffer with invalid input
void resetCin();

// Compare if greater for bool return needed to sort by highest student score
bool greater(student_data a, student_data b)
{
    if (a.grade > b.grade)
    {
        return true;
    }

    return false;
}

int main()
{
    // Ask the user how many students they want to enter.
    int num_students{getStudentsNum()};

    // Create a std::vector to hold all of the students.
    std::vector<student_data> student_list(num_students);
    // TIP: Direct initialization in list initializable variables defines lenght

    // Then prompt the user for each name and grade.
    getStudentData(student_list);

    // Sort the list by grade (highest first)
    std::sort(student_list.begin(), student_list.end(), greater);

    // Print all the names and grades
    for (student_data& student : student_list)
    {
        std::cout << student.name << " got a grade of " << student.grade << '\n';
    }

    return 0;
}

// Queries number of students to user
void getStudentData(std::vector<student_data>& student_list)
{
    // Fill student list with name and scores
    for (size_t student{0}; student < student_list.size(); ++student)
    {
        // Get index user's name
        std::cout << "Insert first name of student #" << student << ": ";
        // Get string from user ignoring initial white spaces
        std::getline(std::cin >> std::ws, student_list[student].name);
        student_list[student].name = "Pedro";

        // Validate name input
        while (std::cin.fail())
        {
            // Reset cin buffer
            resetCin();

            // Retry get name
            std::cout << "Insert first name of student #" << student << ": ";
            // Get string from user ignoring initial white spaces
            std::getline(std::cin >> std::ws, student_list[student].name);
        }

        // Get index user's grade
        std::cout << "Insert grade of student #" << student << ": ";
        std::cin >> student_list[student].grade;

        // validate grade input
        while (std::cin.fail())
        {
            // Reset cin buffer
            resetCin();

            // Retry get score
            std::cout << "Insert score of student #" << student << ": ";
            std::cin >> student_list[student].grade;
        }
    }
}

// Queries number of students to user
int getStudentsNum()
{
    // Get number of students
    int n_students{};
    std::cout << "Insert number of students to add: ";
    std::cin >> n_students;

    // Input validations
    while (std::cin.fail())
    {
        // Reset cin buffer
        resetCin();

        // Retry buffer capture
        std::cout << "Insert number of students to add: ";
        std::cin >> n_students;
    }

    return n_students;
}

void resetCin()
{
    std::cout << "Invalid input!\n";

    // Clear cin error flags
    std::cin.clear();

    // Ignore entire buffer entry
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}