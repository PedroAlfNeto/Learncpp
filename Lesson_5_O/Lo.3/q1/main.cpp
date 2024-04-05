/*
 Quizz 2:
 Do not use std::bitset in this quiz. We’re only using std::bitset for printing.
 Write a line of code to set the article as viewed: 00000101
*/

#include <bitset>
#include <cstdint>
#include <iostream>

int main()
{
    constexpr std::uint8_t option_viewed{0x01};
    constexpr std::uint8_t option_edited{0x02};
    constexpr std::uint8_t option_favorited{0x04};
    constexpr std::uint8_t option_shared{0x08};
    constexpr std::uint8_t option_deleted{0x10};

    std::uint8_t myArticleFlags{option_favorited};

    // a) Write a line of code to set the article as viewed.
    myArticleFlags |= option_viewed;
    // --- END --- //

    std::cout << std::bitset<8>{myArticleFlags} << '\n';

    // b) Write a line of code to check if the article was deleted.
    bool wasdeleted = static_cast<bool>(myArticleFlags & option_deleted);
    std::cout << "Was the article deleted? " << (wasdeleted ? "Yes!\n" : "No!\n");

    // c) Write a line of code to clear the article as a favorite: 00000001
    myArticleFlags &= ~option_favorited;
    std::cout << "Removed as favourite\n" << std::bitset<8>{myArticleFlags} << '\n';

    return 0;
}