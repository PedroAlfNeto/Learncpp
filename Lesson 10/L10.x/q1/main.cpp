/*
 Quizz 1:
 1-In designing a game, we decide we want to have monsters, because everyone likes fighting monsters.
 Declare a struct that represents your monster.
 The monster should have a type that can be one of the following:
    an ogre, a dragon, an orc, a giant spider, or a slime. Use an enum class for this.

 2- Each individual monster should also have a name (use a std::string or std::string_view),
    as well as an amount of health that represents how much damage they can take before they die.
 Write a function named printMonster() that prints out all of the struct’s members.
 Instantiate an ogre and a slime, initialize them using an initializer list,
    and pass them to printMonster().

 Your program should produce the following output:
    This Ogre is named Torg and has 145 health.
    This Slime is named Blurp and has 23 health.
*/

#include "main.hpp"
#include <iostream>
#include <string>  // For std::string usage
#include <cassert> // For assert usage
#include <string_view> // C++17

int main()
{
    Monster torg{monster_type::ogre, "Torg", 145};
    Monster blurp{monster_type::slime, "Blurp", 23};

    printMonster(torg);
    printMonster(blurp);

    return 0;
}

constexpr std::string_view getMonsterTypeString(monster_type type)
{
    switch (type)
    {
    case monster_type::ogre:
        return "This Ogre is named ";
    case monster_type::dragon:
        return "This Dragon is named ";
    case monster_type::orc:
        return  "This Orc is named ";
    case monster_type::giant_spider:
        return "This Giant Spider is named ";
    case monster_type::slime:
        return "This Slime is named ";
    default:
        assert(!true && "Invalid monster type at printMonster()!\n");
    }

    return "Unknown"; // Should never be reached
}

void printMonster(Monster &monster)
{
    std::cout << getMonsterTypeString(monster.type) <<
    monster.name << " and has " << monster.health << " health.\n";
}