/*
 Quizz 1:
 In this quiz, we’re going to implement Roscoe’s potion emporium,
    the finest potion shop in the land!
 This is going to be a bigger challenge.

 Implement a program that outputs the following:
 ...

 The player starts with a randomized amount of gold, between 80 and 120.

 Sound fun? Let’s do it! Because this will be hard to implement all at once,
 we’ll develop this in steps.
*/

/*
    > Step #1

 Create a Potion namespace containing an enum named Type containing the potion
 types. Create two std::array: an int array to hold the potion costs, and a
 std::string_view array to hold the potion names.

 Also write a function named shop() that enumerates through the list of Potions
 and prints their numbers, names, and cost.

 The program should output the following:

    Here is our selection for today:
    0) healing costs 20
    1) mana costs 30
    2) speed costs 12
    3) invisibility costs 50
*/

#include <array>
#include <cassert>
#include <iostream>
#include <string_view>

int charNumToInt(char c);

namespace Potion {

enum Type  // enum name cant be omitted since its used
{
    healing,
    mana,
    speed,
    invisibility,
    max_potions
};

// A std::array containing all our enumerators for range-based for loops
constexpr std::array types{healing, mana, speed, invisibility};

constexpr std::array<int, max_potions> Cost{20, 30, 12, 50};
constexpr std::array<std::string_view, max_potions> Name{
    "healing", "mana", "speed", "invisibility"};

static_assert(types.size() == max_potions && "Invalid size of types array");
static_assert(Cost.size() == max_potions && "Invalid size of Cost array");
static_assert(Name.size() == max_potions && "Invalid size of Name array");

void shop() {
    std::cout << "Here is our selection for today:\n";

    for (auto pot : Potion::types) {
        std::cout << pot << ") " << Potion::Name[pot] << " costs "
                  << Potion::Cost[pot] << '\n';
    }
}

}  // namespace Potion

/*
> Step #2

 Create a Player class to store the player’s name, potion inventory, and
 gold. Add the introductory and goodbye text for Roscoe’s emporium. Get the
 player’s name and randomize their gold.

 Use the “Random.h” file in lesson 8.15 -- Global random numbers (Random.h) to
 make randomization easy.

 The program should output the following:
*/

#include <limits>  // for std::numeric_limits
#include <vector>

#include "random.h"  // for std::mt19937 and std::random_device

void ignoreLine() {
    // Ignore cin buffer entry
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

class Player {
   private:
    static constexpr int s_minGold{80};
    static constexpr int s_maxGold{120};
    std::string m_name{};
    int m_gold{Random::get(s_minGold, s_maxGold)};
    std::array<int, 10> m_inventory{};

   public:
    Player() {
        std::cout << "Welcome to Roscoe's potion emporium!\n";
        askName();

        game();
    }

    void askName() {
        std::cout << "Enter your name: ";

        // Get string from user ignoring initial white spaces
        std::getline(std::cin >> std::ws, m_name);

        // Retry if failed
        while (std::cin.fail()) {
            // Clear error flag
            std::cin.clear();

            ignoreLine();

            // Retry to get name
            std::cout << "Invalid entry\nEnter your name: ";
            std::getline(std::cin >> std::ws, m_name);
        }
    }

    int askChoice() {
        char choice_char{};
        char choice_int{};
        std::cout << "Enter the number of the potion you'd like to "
                     "buy, or 'q' "
                     "to quit:";

        std::cin >> choice_char;

        if (choice_char == 'q')
            return Potion::max_potions;  // max_potions represent exit

        choice_int = charNumToInt(choice_char);
        while (std::cin.fail() || choice_int < 0 || choice_int > 3) {
            // Clear error flag
            std::cin.clear();

            ignoreLine();

            // Retry to get name
            std::cout << "That is an invalid input.  Try again: ";
            std::cin >> choice_char;
            choice_int = charNumToInt(choice_char);

            // If there is extraneous input, treat as failure case
            if (!std::cin.eof() && std::cin.peek() != '\n') {
                std::cout << "I didn't understand what you said.  Try again: ";
                ignoreLine();  // ignore any extraneous input
                continue;
            }

            if (choice_char == 'q')
                return Potion::max_potions;  // max_potions represent exit
        }

        return choice_int;
    }

    void game() {
        char choice{};

        // Print player name and his gold
        std::cout << "Hello, " << m_name << ", you have " << m_gold
                  << " gold.\n\n";

        while (choice != Potion::max_potions) {
            // print shop selection
            Potion::shop();

            // request user choice
            choice = askChoice();

            //
            if (choice != Potion::max_potions) {
                // check for player gold
                if (m_gold > Potion::Cost[choice]) {
                    m_gold -= Potion::Cost[choice];  // pay for potion
                    m_inventory[choice] += 1;        // add potion to inventory
                    std::cout << "You purchased a potion of "
                              << Potion::Name[choice] << ". You have " << m_gold
                              << " gold left.\n\n";
                } else {  // not enough money
                    std::cout << "You can not afford that.\n"
                              << Potion::Name[choice] << " costs "
                              << Potion::Cost[choice] << "\n\n";
                }
            }
        }

        // Print player inventory before exiting
        printInventory();

        std::cout << "\nThanks for shopping at Roscoe's potion emporium!\n";
    }

    void printInventory() {
        std::cout << "\nYour inventory contains:\n";
        for (auto pot : Potion::types) {
            // print only potions in inventory
            if (m_inventory[pot] > 0) {
                std::cout << m_inventory[pot] << "x potion of "
                          << Potion::Name[pot] << '\n';
            }
        }
        std::cout << "\nYou escaped with " << m_gold << " gold remaining.";
    }
};
/*
> Step #3
 Add the ability to purchase potions, handling invalid input (treat any
extraneous input as a failure). Print the player’s inventory after they leave.
 The program should be complete after this step.

 Make sure you test for the following cases:

    User enters an invalid potion number (e.g. ‘d’)
    User enters a valid potion number but with extraneous input (e.g. 2d, 25)
*/

int charNumToInt(char c) { return c - '0'; }

int main() {
    Player newPlayer;

    return 0;
}