/*
 Quizz 1:
    A map is a class that stores elements as a key-value pair.
    The key must be unique, and is used to access the associated pair.
    In this quiz, we’re going to write an application that lets us assign grades
        to students by name, using a simple map class.
    The student’s name will be the key, and the grade (as a char) will be the
        value.

    a) First, write a struct named StudentGrade that contains the student’s name
        (as a std::string) and grade (as a char).

    b) Add a class named GradeMap that contains a std::vector of StudentGrade
        named m_map.

    c) Write an overloaded operator[] for this class.
    This function should take a std::string parameter,
        and return a reference to a char.

    In the body of the function, first see if the student’s name already exists
        (You can use std::find_if from <algorithm>).
    If the student exists, return a reference to the grade and you’re done.
    Otherwise, use the std::vector::emplace_back() or std::vector::push_back()
        function to add a StudentGrade for this new student.
     When you do this, std::vector will add a copy of your StudentGrade itself
        (resizing if needed, invalidating all previously returned references).

    Finally, we need to return a reference to the grade for the student we just
        added to the std::vector.
    We can access the student we just added using std::vector::back().

    The following main should run.
*/

/*
Question 2:
    Extra credit #1: The GradeMap class and sample program we wrote is
inefficient for many reasons. Describe one way that the GradeMap class could be
improved.

    1) initial size of m_map{} vector is minimum, constantly getting expanded,
could be allocated with some elements to begin with. 20 (typical student class
size) 2) unsorted student vector. If sorted we could use binary search for
faster find_if
*/

#include <algorithm>  // for std::find_if
#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>

struct StudentGrade {
    std::string name{};
    char grade{'F'};  // default to fail
};

class GradeMap {
   private:
    std::vector<StudentGrade> m_map{};

   public:
    char& operator[](const std::string& name) {
        [[maybe_unused]] auto found = std::find_if(
            m_map.begin(), m_map.end(), [name](const StudentGrade& student) {
                return (student.name == name);
            });

        if (found != m_map.end()) {
            // If the student exists, return its grade.
            return found->grade;
        } else {
            // Add a new student and return referrence grade.
            return m_map.emplace_back(std::string{name}).grade;
        }
    }
};

// The following main should run:
int main() {
    GradeMap grades{};

    grades["Joe"] = 'A';
    grades["Frank"] = 'B';

    std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
    std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

    return 0;
}

/*
    Question #3

    Extra credit #2: Why does this program potentially not work as expected?

    #include <iostream>

int main()
{
	GradeMap grades{};

	char& gradeJoe{ grades["Joe"] }; // does an emplace_back
	gradeJoe = 'A';

	char& gradeFrank{ grades["Frank"] }; // does a emplace_back
	gradeFrank = 'B';

	std::cout << "Joe has a grade of " << gradeJoe << '\n';
	std::cout << "Frank has a grade of " << gradeFrank << '\n';

	return 0;
}
A: Dynamic allocation of std::array may invalidate old referrences. Here gradeJoe 
referrence may be invalid when Frank is added to the vector.

*/

