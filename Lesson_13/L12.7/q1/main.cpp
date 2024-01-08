/*
 Quizz 1:
 Create a struct Student that stores the name and points of a student. 
 Create an array of students and use std::max_element to find the student with the most points, 
    then print that student’s name.
 std::max_element takes the begin and end of a list, and a function that takes 2 parameters and 
    returns true if the first argument is less than the second.
*/

#include <iostream>
#include <limits>   // for numeric_limits
#include <functional> // for std::function
#include <string>
#include <cassert>
#include <algorithm> // for std::max_element

// constexpr std::streamsize streamMax{std::numeric_limits<std::streamsize>::max()};


// Declarations

struct Student
{
    std::string name{};
    int points{};
};

int main()
{
    // Provided array
    std::array<Student, 8> arr{
    { { "Albert", 3 },
        { "Ben", 5 },
        { "Christine", 2 },
        { "Dan", 8 }, // Dan has the most points (8).
        { "Enchilada", 4 },
        { "Francis", 1 },
        { "Greg", 3 },
        { "Hagrid", 5 } }
    };

    // Find the student with the most points
    // const auto bestStudent{
    const Student* bestStudent{
        std::max_element(arr.begin(), arr.end(), 
        // Lambda {
            [](const auto& a, const auto& b)
            {
                // returns true if the first argument is less than the second.
                return (a.points < b.points);
            })
        // }
    };

    // Print the name of the student witht he most points
    std::cout << bestStudent->name << " has the most points (" << bestStudent->points << ")\n";
  
    return 0;
}
