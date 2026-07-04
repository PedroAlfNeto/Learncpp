/*
 Quizz 1:
 Project time: Let’s implement the classic game 15 Puzzle!

 In our version of the game, each turn the user will enter a single letter
command. There are 5 valid commands:

    w - slide tile up
    a - slide tile left
    s - slide tile down
    d - slide tile right
    q - quit game

  at each step, we’ll present two things: a goal and tasks.
  The goal defines the outcome that the step is trying to achieve, along with
any additional relevant information. The tasks provide detail and hints about
how to implement the goal.

 ##############################################################################
 > Step #2

Goal: Be able to display individual tiles on the screen.

Our game board is a 4×4 grid of tiles that can slide around.
Therefore, it will be useful to have a Tile class that represents one of the
numbered tiles on our 4×4 grid or the missing tile. Each tile should be able to:

    Be given a number or be set as the missing tile
    Determine whether it is the missing tile.
    Draw to the console with the appropriate spacing (so the tiles will line up
when the board is displayed). See the sample output below for an example
indicating how tiles should be spaced.

The following main should compile and produce the output result you can see
below the code. Expected output (pay attention to the white spaces):

0123456789ABCDEF
 10   8       1
false true
Tile 2 has number: 8
Tile 4 has number: 1


  # ---------------------------------------------------------------------------
#

*/

#include <cassert>
#include <iostream>

class Tile {
   private:
    int m_tile_value{};

   public:
    Tile(int num) : m_tile_value{num} {
        // validate tile input
        if (num < 0 || num > 15) {
            assert("Invalid configuration for tiles");
        }
    }

    bool isEmpty() const { return m_tile_value == 0; }

    int getNum() const { return m_tile_value; }

    friend std::ostream& operator<<(std::ostream& out, const Tile& tile);
};

std::ostream& operator<<(std::ostream& out, const Tile& tile) {
    if (tile.getNum() > 9) {  // dual digit numbers
        out << " " << tile.getNum() << " ";
    } else if (tile.getNum() > 0) {  // single digit numbers
        out << "  " << tile.getNum() << " ";
    } else {  // empty tile
        out << "  ";
    }

    return out;
}

int main() {
    Tile tile1{10};
    Tile tile2{8};
    Tile tile3{0};  // the missing tile
    Tile tile4{1};

    std::cout << "0123456789ABCDEF\n";  // to make it easy to see how many
                                        // spaces are in the next line
    std::cout << tile1 << tile2 << tile3 << tile4 << '\n';

    std::cout << std::boolalpha << tile1.isEmpty() << ' ' << tile3.isEmpty()
              << '\n';
    std::cout << "Tile 2 has number: " << tile2.getNum()
              << "\nTile 4 has number: " << tile4.getNum() << '\n';

    return 0;
}