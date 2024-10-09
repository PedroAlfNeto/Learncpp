/*
 Question #2

 Let’s say you’re writing a game where the player can hold 3 types of items:
 health potions, torches, and arrows.

 > Step #2

 Modify your program from the prior step so it now outputs:

 You have 1 health potion
 You have 5 torches
 You have 10 arrows
 You have 16 total items

 Use a loop to print out the number of items and the item names for each
 inventory item. Handle proper pluralization of the names.
*/

#include <cassert>
#include <iostream>
#include <string_view>
#include <vector>

namespace Items {
enum Type {
    healthPotions,  // 0
    torches,        // 1
    arrows,         // 2
    max,            // 3
};
const std::vector names{" health potion", " torch", " arrow"};
};  // namespace Items

void printItems(const std::vector<int>& vecItems) {

    int itemSum{};

    // print number of all items (cant use range-based loop)
    for (ssize_t item{0}; item < Items::max; ++item) {
        auto numItems{vecItems.at(item)};  // single vector access

        std::cout << "You have " << numItems << Items::names.at(item);

        // Handle proper pluralization of the names.
        if (numItems > 1) {
            if(item == Items::Type::torches) std::cout << 'e';
            std::cout << 's';
        }
        
        std::cout << "\n";

        itemSum += numItems;  // keep sum of items
    }

    std::cout << "You have " << itemSum << " total items\n";
}

int main() {
    std::vector<int> playerItems{1, 5, 10};  // initialized to starter items
    assert(std::size(playerItems) == Items::max && "items size incorrect!");

    printItems(playerItems);

    return 0;
}
