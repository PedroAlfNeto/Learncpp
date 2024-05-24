/*
 Quizz 1:
 Convert the Random namespace in the following example to a class with static
 members:
*/

#include <chrono>
#include <iostream>
#include <random>

namespace Random_namespace
{
	inline std::mt19937 generate()
	{
		std::random_device rd{};

		// Create seed_seq with high-res clock and 7 random numbers from std::random_device
		std::seed_seq ss{
			static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
				rd(), rd(), rd(), rd(), rd(), rd(), rd() };

		return std::mt19937{ ss };
	}

	inline std::mt19937 mt{ generate() }; // generates a seeded std::mt19937 and copies it into our global object

	// Generate a random int between [min, max] (inclusive)
	inline int get(int min, int max)
	{
		return std::uniform_int_distribution{min, max}(mt);
	}
} // namespace Random_namespace

class Random_class {
   private:
    
    static std::mt19937 generate() 
    {
        std::random_device rd{};
        // Create seed_seq with high-res clock and 7 random numbers from std::random_device
        std::seed_seq ss{
            static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
                rd(), rd(), rd(), rd(), rd(), rd(), rd() 
        };

        return std::mt19937{ss};
    }

    // generates a seeded std::mt19937 and copies it into our global object
    static std::mt19937 mt{generate()}; 
    
   public:

    // Generate a random int between [min, max] (inclusive)
    static int get(int min, int max) {
        return std::uniform_int_distribution{min, max}(mt);
    }
};

int main() {
    // Print a bunch of random numbers from namespace approach
    for (int count{1}; count <= 10; ++count)
        std::cout << Random_namespace::get(1, 6) << '\t';

    std::cout << '\n';

    // Print a bunch of random numbers from static class approach
    for (int count{1}; count <= 10; ++count)
        std::cout << Random_class::get(1, 6) << '\t';

    std::cout << '\n';

    return 0;
}