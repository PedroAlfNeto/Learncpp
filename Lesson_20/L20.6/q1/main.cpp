/*
 Quizz 1:

 Create a struct Student that stores the name and points of a student.

 Create an array of students and use std::max_element to find the student with
 the most points, then print that student’s name.

 std::max_element takes the begin and end of a list, and a function that takes 2
 parameters and returns true if the first argument is less than the second.

 [ captureClause ] ( parameters ) -> returnType
    {
        statements;
    }
*/

#include <algorithm>
#include <array>
#include <iostream>
#include <string>

struct Student {
    std::string name{""};
    int points{};
};

int main() {
    const std::array<Student, 8> arr{{{"Albert", 3},
                                {"Ben", 5},
                                {"Christine", 2},
                                {"Dan", 8},  // Dan has the most points (8).
                                {"Enchilada", 4},
                                {"Francis", 1},
                                {"Greg", 3},
                                {"Hagrid", 5}}};
    const auto best_student {
        std::max_element(arr.begin(), arr.end(),
                         [](const Student& a,const Student& b) -> bool { return a.points < b.points; }
                         )
    };
    
    std::cout << best_student->name << " is the best student\n";

    return 0;
}
