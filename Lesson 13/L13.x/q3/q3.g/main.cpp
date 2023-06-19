/*
 Let’s create a random monster generator. This one should be fun.

 g) Modify the function generate() from the prior quiz to generate a
        random Monster::Type (between 0 and Monster::Type::max_monster_types-1)
        and a random hit points (between 1 and 100).
    This should be fairly straightforward.

    Once you’ve done that, define two static fixed arrays of size 6 inside the function
        (named s_names and s_roars) and initialize them with 6 names and 6 sounds of your choice.
    Pick a random name and roar from these arrays.

    The following program should compile:

    h) Why did we declare variables s_names and s_roars as static?
    A:  These values are constant for the duration of main (program duration) 
            but scope needed only for MonsterGenerator::generate().
        This avoids constant reinitialization for every generate() call

*/

#include <array>
#include <string>
#include <string_view>
#include <cassert>
#include <iostream>

#include "random.h" // for std::mt19937 and std::random_device

class Monster
{
public:
    enum class Type
    {
        dragon,
        goblin,
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,
        max_monster_types
    };

private:
    // const MonsterType m_type; q3.a
    Type m_type; // pneto why can't this be of const type?!
    const std::string m_name;
    const std::string m_roar;
    int m_hit_points;

public:
    std::string_view getTypeString() const
    {
        switch (m_type)
        {
        case Type::dragon:
            return "dragon";
        case Type::goblin:
            return "goblin";
        case Type::ogre:
            return "ogre";
        case Type::orc:
            return "orc";
        case Type::skeleton:
            return "skeleton";
        case Type::troll:
            return "troll";
        case Type::vampire:
            return "vampire";
        case Type::zombie:
            return "zombie";
        default:
            assert(false && "invalid type");
        }
    }

    // Constructor
    Monster(const Type type, std::string_view name, std::string_view roar, const int hit_points)
        : m_type{type}, m_name{name}, m_roar{roar}, m_hit_points{hit_points}
    {
    }

    void print() const
    {
        std::cout << m_name << " the " << getTypeString() << " has " << m_hit_points
                  << " hit points and says " << m_roar << "\n";
    }
};

// q3.f) Create a namespace named MonsterGenerator.
namespace MonsterGenerator
{
    Monster generate()
    {
        // define two static fixed arrays of size 6
        static std::array<std::string_view, 6> s_names{"n_1", "n_2", "n_3", "n_4", "n_5", "n_6"};
        static std::array<std::string, 6> s_sounds{"s_1", "s_2", "s_3", "s_4", "s_5", "s_6"};

        // Pick a random name and roar from these arrays.
        const int r_name = Random::get(0, 5);
        const int r_sound = Random::get(0, 5);

        // random Monster hitpoints
        const int r_hitpoints = Random::get(1, 100);

        // random Monster type
        Monster::Type r_type =
            static_cast<Monster::Type>(Random::get(0, static_cast<int>(Monster::Type::max_monster_types) - 1));

        // const int type_id=static_cast<Monster::Type>();

        return Monster{r_type, s_names.at(r_name), s_sounds.at(r_sound), r_hitpoints};
    }
}

int main()
{
    Monster m{MonsterGenerator::generate()};
    m.print();

    return 0;
}