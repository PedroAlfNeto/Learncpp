/*
    This chapter is pretty straightforward and a little more abstract than the
    previous ones, so this quiz will be short and to the point.

        What type of relationship (composition, aggregation, association, or
    dependency) do the following describe?

    1a) An Animal class that contains an animal type (enum) and name (string).
    A: Composition

    1b) A text editor class with a save() function that takes a File object as an
    argument. The save() function writes the contents of the editor to disk.
    A: Dependency

    1c) An Adventurer class that can carry various kinds of Items, such as swords,
    wands, potions, or spellbooks. These Items can be dropped and picked up by other
    Adventurers.
    A: Association


    1d) The Player prays at a Shrine (to receive a new power).
    A: Dependency 

    1e) A Computer class that contains a CPU class. The CPU can be removed from the
    Computer and tested on its own.
    A: Aggregation

    1f) A blacksmith has a specific anvil that he uses to do his work.
    A: Association

    Select one: If you can design a class using (pick one: composition,
    aggregation, association, or dependency), then you should:
    Weird grammar, allways prefer composition if suits usecases (if a part of whole, doesnt need to share members and can be unilateral)


*/