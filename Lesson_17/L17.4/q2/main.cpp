/*
 Quizz 2:
 Update your solution to quiz 1 to not explicitly specify the element type for
 each initializer.
*/

#include <array>
#include <iostream>
#include <string_view>

struct Item {
    std::string_view name;
    int gold{};
};

template <auto N>
void printStore(const std::array<Item, N>& arr) {
    for (const auto& item : arr) {
        std::cout << "A " << item.name << " costs " << item.gold << " gold.\n";
    }
}

int main() {
    constexpr std::array<Item, 4> items{{ // No CTAD, double braces required for std::array
        Item{"sword", 5},
        Item{"dagger", 3},
        Item{"club", 2},
        Item{"spear", 7},
    }};
    printStore(items);

    return 0;
}