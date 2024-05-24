/*
 Let’s create a random monster generator. This one should be fun.

 a) First, let’s create an enumeration of monster types named MonsterType.
    Include the following monster types:
        Dragon, Goblin, Ogre, Orc, Skeleton, Troll, Vampire, and Zombie.
    Add an additional max_monster_types enum so we can count how many enumerators there are.

 b) Now, let’s create our Monster class. Our Monster will have 4 attributes (member variables):
    a type (MonsterType), a name (std::string), a roar (std::string),
        and the number of hit points (int).
    Create a Monster class that has these 4 member variables.

 c) enum MonsterType is specific to Monster, so move the enum inside
    the class as a public declaration.
 When the enum is inside the class, “MonsterType” can be renamed “Type”
    since the context is already Monster.

 d) Create a constructor that allows you to initialize all of the member variables.
 The following program should compile:

 e) Now we want to be able to print our monster so we can validate it’s correct.
 To do that, we’re going to need to write a function that converts a Monster::Type into a string.
 Write that function (called getTypeString()), as well as a print() member function.

 f)Now we can create a random monster generator. Let’s consider how our monster generator will work.
 Ideally, we’ll ask it to give us a Monster, and it will create a random one for us.
 We don’t need more than one monster generator, and we are not maintaining any state,
    so this is a good candidate for a namespace.
 Create a namespace named MonsterGenerator.
 Create a function named generate() that returns a Monster.

 The following main program should compile:
*/

#include <string>
#include <string_view>
#include <cassert>
#include <iostream>

// q3.a
// enum class MonsterType
// {
//     Dragon,
//     Goblin,
//     Ogre,
//     Orc,
//     Skeleton,
//     Troll,
//     Vampire,
//     Zombie,
//     max_monster_types
// };



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
            return "???";
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
    Monster generateMonster()
    {
        return Monster{Monster::Type::skeleton, "Bones", "*rattle*", 4};
    }
}

int main()
{
    // // const MonsterType m_type; q3.d
    // Monster skeleton{Monster::Type::skeleton, "Bones", "*rattle*", 4};
    // skeleton.print();

    Monster m{MonsterGenerator::generateMonster()};
    m.print();

    return 0;
}