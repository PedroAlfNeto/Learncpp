/*
 Quizz 2:

 Use std::sort and a lambda in the following code to sort the seasons by
 ascending average temperature.

 The program should print

    Winter
    Spring
    Fall
    Summer

 [ captureClause ] ( parameters ) -> returnType
    {
        statements;
    }
*/

#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

struct Season {
    std::string_view name{};
    double avgTemp{};
};

int main() {
    std::array<Season, 4> seasons{{{"Spring", 285.0},
                                   {"Summer", 296.0},
                                   {"Fall", 288.0},
                                   {"Winter", 263.0}}};

    /*
     * Use std::sort here
     */
    std::sort(seasons.begin(), seasons.end(),
              [](const Season& a, const Season& b) -> bool {
                  return a.avgTemp < b.avgTemp;
              });

    for (const auto& season : seasons) {
        std::cout << season.name << '\n';
    }

    return 0;
}