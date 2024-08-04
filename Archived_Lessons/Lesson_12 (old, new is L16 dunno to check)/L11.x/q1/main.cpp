/*
 Quizz 1:
 Pretend you’re writing a game where the player can hold 3 types of items:
    health potions, torches, and arrows.
 Create an enum to identify the different types of items, and an std::array to store the number of
    each item the player is carrying (the enumerators are used as indexes of the array).
 The player should start with 2 health potions, 5 torches, and 10 arrows.
 Write a function called countTotalItems() that returns how many items the player has in total.
 Have your main() function print the output of countTotalItems() as well as the number of torches.
*/

#include <iostream>
#include <array>
#include <numeric>

namespace items
{ // Scope the soft scoping of enum to items::
   enum Item_vars
   { // Enum instead of Enum class so as to use the elements and integer indexes
      HP_potions,
      torches,
      arrows,
      max_items,
   };
   // Initial items for player
   constexpr int starter_HP_potions{2};
   constexpr int starter_torches{5};
   constexpr int starter_arrows{10};
};

int countTotalItems(std::array<int, items::max_items> playerItems);

int main()
{
   // Holds player's number of items
   std::array<int, items::max_items> player_items{
       items::starter_HP_potions,
       items::starter_torches,
       items::starter_arrows};

   player_items[0] = 1; // TMP compile

   // Print the TotalItems as well as the number of torches.
   std::cout << "Total items: " << countTotalItems(player_items)
             << "\nNumber of torches: "<< player_items[items::torches];

   return 0;
}

int countTotalItems(std::array<int, items::max_items> playerItems)
{

   int total{0};

   // sum all items in array
   for (int index{0}; index < items::max_items; ++index)
   {
      total += playerItems[index];
   }

   // Alternative sum with std::algorithm from STL
   // total=std::accumulate(playerItems.begin(),playerItems.end(),0);

   return total;
}