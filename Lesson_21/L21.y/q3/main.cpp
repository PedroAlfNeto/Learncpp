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
 > Step #3

 Goal: Create a solved board (4×4 grid of tiles) and display it on the screen.

 Define a Board class that will represent 4×4 grid of tiles. A newly created
Board object should be in the solved state. To display the board, first print
g_consoleLines (defined in code snippet below) empty lines and then print the
board itself. Doing so will ensure that any prior output is pushed out of view
so that only the current board is visible on the console.

 Why initiate the board in the solved state? When you buy a physical version of
these puzzles, the puzzles typically start in the solved state -- you have to
manually mix them up (by sliding tiles around) before trying to solve them. We
will mimic that process in our program (we’ll do the mixing up in a future
step).

 The following program should run and output the following:

  1   2   3   4
  5   6   7   8
  9  10  11  12
 13  14  15

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
            assert(false && "Invalid configuration for tiles");
        }
    }

    bool isEmpty() const { return m_tile_value == 0; }

    int getNum() const { return m_tile_value; }
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

// Increase amount of new lines if your board isn't
// at the very bottom of the console
constexpr int g_consoleLines{25};

// Your code goes here
class Board {
   private:
    static constexpr std::size_t kBoardWidth{4};  // square width

    Tile m_board[kBoardWidth][kBoardWidth]{
        {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}};

    friend std::ostream& operator<<(std::ostream& out, const Board& board) {
        for (std::size_t collumn{}; collumn < kBoardWidth; ++collumn) {
            for (std::size_t row{}; row < kBoardWidth; ++row) {
                // out << board[collumn][row];
                out << board.m_board[collumn][row];
            }
            out << "\n";
        }

        return out;
    }
};

int main() {
    Board board{};
    std::cout << board;

    return 0;
}