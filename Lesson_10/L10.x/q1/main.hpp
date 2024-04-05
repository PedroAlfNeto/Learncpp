#ifndef MAIN_HPP    // Header guards
#define MAIN_HPP

#include <string>  // For std::string usage

enum class monster_type
{
    ogre,
    dragon,
    orc,
    giant_spider,
    slime,
};

struct Monster
{
    monster_type type{};
    std::string name{};
    int health{};
};

// Print monster's type, name and healthpool
void printMonster(Monster &monster);

#endif