/*
 Quizz 1:
 Define a std::array that will hold the high temperature for each day of the
 year (to the nearest tenth of a degree).
*/

#include <array>

constexpr double kLowestTmp {-100.0};

constexpr std::array<double, 366> highTemp{{kLowestTmp}}; 
// default initialize to lowest temps 