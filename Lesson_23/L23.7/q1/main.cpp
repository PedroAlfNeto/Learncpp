/*
 Quizz 1:

   Using the IntArray class above, implement an overloaded assignment operator
that takes an initializer list.

The following code should run:

    The following main should execute and print:

    5 4 3 2 1
    1 3 5 7 9 11

*/

#include <algorithm>         // for std::copy()
#include <cassert>           // for assert()
#include <initializer_list>  // for std::initializer_list
#include <iostream>


class IntArray {
   private:
    int m_length{};
    int* m_data{};

   public:
    IntArray() = default;

    IntArray(int length)
        : m_length{length},
          m_data{new int[static_cast<std::size_t>(length)]{}} {}

    IntArray(
        std::initializer_list<int>
            list)  // allow IntArray to be initialized via list initialization
        : IntArray(static_cast<int>(list.size()))  // use delegating constructor
                                                   // to set up initial array
    {
        // Now initialize our array from the list
        std::copy(list.begin(), list.end(), m_data);
    }

    ~IntArray() { delete[] m_data; }

    // to avoid shallow copies
   //  IntArray(const IntArray&) = delete;
   //  IntArray& operator=(const IntArray& list) = delete;

    int& operator[](int index) {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    // Overload assignment operator for initializer_list
    void operator=(std::initializer_list<int> list){

      // realocate array to size of initializing list
      delete m_data;
      m_data=new int[static_cast<std::size_t>(list.size())];

      // Now initialize our array from the list
      std::copy(list.begin(), list.end(), m_data);

    }

    int getLength() const { return m_length; }
};

int main()
{
	IntArray array { 5, 4, 3, 2, 1 }; // initializer list
	for (int count{ 0 }; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	std::cout << '\n';

	array = { 1, 3, 5, 7, 9, 11 };

	for (int count{ 0 }; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	std::cout << '\n';

	return 0;
}