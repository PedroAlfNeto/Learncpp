/*
 Quizz 1:

    Would you be more likely to implement the following as a composition or an
 aggregation? a) A ball that has a color A: composition, parent: ball, child:
 color (doesnt exist without parent)

    b) An employer that is employing multiple people
    A: aggregation, people (exist without employer)

    c) The departments in a university
    A: composition, parent: university, child: department (doesnt exist without
 parent)

    d) Your age
    A: composition, parent: me, child: age (doesnt exist without parent)

    e) A bag of marbles
    A: aggregation, marbles (exist without bag)
*/

/*
 Quizz 2:

    Update the Department/Teacher example so the Department can handle multiple
 Teachers.

    The following main should execute and print:

    Department: Bob Frank Beth
    Bob still exists!
    Frank still exists!
    Beth still exists!

*/

#include <functional>  // for std::reference_wrapper
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

class Teacher {
   private:
    std::string m_name{};

   public:
    Teacher(std::string_view name) : m_name{name} {}

    const std::string& getName() const { return m_name; }
};

class Department {
   private:
    std::vector<std::reference_wrapper<const Teacher>> m_teachers{};

   public:
    Department() {};

    void add(const Teacher& teacher) { m_teachers.push_back(teacher); }

    friend std::ostream& operator<<(std::ostream& out, const Department& dep) {
        out << "Department: ";
        for (const auto& teacher : dep.m_teachers) {
            out << teacher.get().getName()<<' ';
        }

        return out << '\n';
    }
};

int main() {
    // Create a teacher outside the scope of the Department
    Teacher t1{"Bob"};
    Teacher t2{"Frank"};
    Teacher t3{"Beth"};

    {
        // Create a department and add some Teachers to it
        Department department{};  // create an empty Department

        department.add(t1);
        department.add(t2);
        department.add(t3);

        std::cout << department;

    }  // department goes out of scope here and is destroyed

    std::cout << t1.getName() << " still exists!\n";
    std::cout << t2.getName() << " still exists!\n";
    std::cout << t3.getName() << " still exists!\n";

    return 0;
}