/*
 Question #4

 Modify the prior program so that the user can enter as many integers as they
    like.
 Stop accepting input when the user enters -1.

 Print the vector and find the min and max elements.

 When run with the input 3 8 5 2 3 7 -1, the program should produce the
    following output:

    Enter numbers to add (use -1 to stop): 3 8 5 2 3 7 -1
    With array ( 3, 8, 5, 2, 3, 7 ):
    The min element has index 3 and value 2
    The max element has index 1 and value 8

 Do something reasonable when the user enters -1 as the first input.

*/

#include <iostream>
#include <vector>
#include <limits>

template <typename T>
std::pair<std::size_t, std::size_t> findMinMaxIndices(const std::vector<T>& v) {
    std::size_t min{0};
    std::size_t max{0};
    for (std::size_t index{0}; index < v.size(); ++index) {
        if (v[index] < v[min]) min = index;
        if (v[index] > v[max]) max = index;
    }

    return {min, max};
}

template <typename T>
void printArray(const std::vector<T>& v) {
    bool comma{false};
    std::cout << "\n\nWith array ( ";
    for (const auto& e : v) {
        if (comma) std::cout << ", ";

        std::cout << e;
        comma = true;
    }
    std::cout << " ):\n";
}

template <typename T>
void getUserArray(std::vector<T>& vec){

    while (true)
	{
		std::cout << "Enter an array sequence (or -1 to finish): ";
		int x{};
		std::cin >> x;

		if (!std::cin) // handle bad input
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input ignored continue \n";
			continue;
		}

		// If we're done, break out of loop
		if (x == -1)
			break;

		// The user entered a valid element, so let's push it on the vector
		vec.push_back(x);
	}

}

int main() {
    std::vector<int> user_vec{};
    getUserArray(user_vec);


    printArray(user_vec);



    auto m1{findMinMaxIndices(user_vec)};
    std::cout << "The min element has index " << m1.first << " and value "
              << user_vec[m1.first] << '\n';
    std::cout << "The max element has index " << m1.second << " and value "
              << user_vec[m1.second] << '\n';

    return 0;
}