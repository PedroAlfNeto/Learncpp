/*
 Quizz 3:

 Write your own integer array class named IntArray from scratch (dont use
 std::array or std::vector).

 Users should pass in the size of the array when it is created, and the array
 should be dynamically allocated. Use assert statements to guard against bad
 data.

 Create any constructors or overloaded operators needed to make the following
 main operate correctly and print:

    5 8 2 3 6
    5 8 2 3 6

*/

#include <cassert>
#include <iostream>

class IntArray {
   private:
    // pointer to array to be dynamically allocated
    int* m_arr;
    // size of array
    std::size_t m_len;

   public:
    // Constructor takes in size and dynamically allocates array (Rule of three
    // due to dyn memory) (Move assingment not learned yet else was rule of
    // five)
    IntArray(std::size_t size) {
        assert(size > 0 && "Size of array must be at least 1");
        m_len = size;
        m_arr = new int[m_len];
        // zeroe array to not contain garbage
        for (std::size_t idx{0}; idx < m_len; ++idx) {
            m_arr[idx] = 0;
        }
    }

    // Copy constructor (required for deep copy)
    IntArray(IntArray& intarr) {
        // allocate new array and copy data from referrence intArray
        m_arr = new int[intarr.lenght()];
        for (std::size_t idx{0}; idx < intarr.lenght(); ++idx) {
            m_arr[idx] = intarr[idx];
        }
    }

    ~IntArray() {
        delete[] m_arr;  // dynamic memory cleanup
    }

    // accessor to array length, following std::array
    std::size_t lenght() const { return m_len; }

    // assignment operator required
    IntArray& operator=(const IntArray& intarr) {
        // check for self assignment
        if (this == &intarr) return *this;

        // dealocate old array
        delete[] m_arr;

        // allocate new array and copy data from referrence intArray
        m_len = intarr.lenght();
        m_arr = new int[m_len];

        for (std::size_t idx{0}; idx < intarr.lenght(); ++idx) {
            m_arr[idx] = intarr.m_arr[idx];  // cant use subscript operator as
                                             // it cant use const qualifier
        }

        // return the existing object so we can chain this operator
        return *this;
    }

    // osteam operator required
    friend std::ostream& operator<<(std::ostream& out, const IntArray& intarr);

    // subscript operator required
    int& operator[](std::size_t idx) { 
        assert(idx >= 0 && idx < m_len && "Index outside bounds of IntArray");
        return m_arr[idx]; }
};

std::ostream& operator<<(std::ostream& out, const IntArray& intarr) {
    for (std::size_t idx{0}; idx < intarr.m_len; ++idx) {
        out << intarr.m_arr[idx] << ' ';
    }
    return out;
}

IntArray fillArray() {
    IntArray a(5);

    a[0] = 5;
    a[1] = 8;
    a[2] = 2;
    a[3] = 3;
    a[4] = 6;

    return a;
}

int main() {
    IntArray a{fillArray()};

    std::cout << a << '\n';

    auto& ref{a};  // we're using this reference to avoid compiler
                   // self-assignment errors
    a = ref;

    IntArray b(1);
    b = a;

    a[4] = 7;

    std::cout << b << '\n';

    return 0;
}