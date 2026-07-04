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
 > Step #5

 Goal: Implement a helper class that will make it easier for us to handle
directional commands.

 After implementing the prior step, we can accept commands from the user (as
characters ‘w’, ‘a’, ‘s’, ‘d’, and ‘q’). These characters are essentially magic
numbers in our code. While it’s fine to handle these commands in our UserInput
namespace and function main(), we don’t want to propagate them throughout our
whole program. For example, the Board class should have no knowledge of what ‘s’
means.

 Implement a helper class named Direction, which will allow us to create objects
that represent the cardinal directions (up, left, down, or right). operator-
should return the opposite direction, and operator<< should print the direction
to the console. We will also need a member function that will return a Direction
object containing a random direction. Lastly, add a function to namespace
UserInput that converts a directional game command (‘w’, ‘a’, ‘s’, or ‘d’) to a
Direction object.

 The more we can use Direction instead of directional game commands, the easier
our code will be to read and understand.


Finally, modify the program you wrote in the prior step so that the output
matches the following:

  1   2   3   4
  5   6   7   8
  9  10  11  12
 13  14  15
Generating random direction... up
Generating random direction... down
Generating random direction... up
Generating random direction... left

Enter a command: w
You entered direction: up
a
You entered direction: left
s
You entered direction: down
d
You entered direction: right
q


Bye!

*/

#include <cassert>
#include <iostream>
#include <limits>

#include "random.h"

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

class Player {
   private:
    int m_num_moves{};

   public:
    enum Command {  // Player available commands
        up,
        down,
        left,
        right,
        quit,
        confirm,
        invalid
    };

   private:
    static constexpr std::streamsize max_buffer{
        std::numeric_limits<std::streamsize>::max()};

    void resetCin() {
        // Clear cin error flags
        std::cin.clear();

        // Ignore entire buffer entry
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    static Command parceCommand(char cmd) {
        switch (cmd) {
            case 'w':
                return Command::up;
            case 'a':
                return Command::left;
            case 's':
                return Command::down;
            case 'd':
                return Command::right;
            case 'q':
                return Command::quit;
            case 'y':
                return Command::confirm;
            default:
                // ignore invalid command or extraneous input
                return Command::invalid;
        }
    }

   public:
    // Queries user command
    static Command getCommand() {
        char input{};
        Command cmd{Command::invalid};

        do {
            std::cin >> input;
            cmd = parceCommand(input);
        } while (std::cin.fail() || cmd == Command::invalid);

        return cmd;
    }
};

//  Implement a helper class named Direction, which will allow us to create
//  objects that represent the cardinal directions (up, left, down, or right).
class Direction {
   public:
    enum Cardinal { up, down, left, right, invalid };

   private:
    Cardinal m_value{invalid};

    Direction::Cardinal getCardinal() { return m_value; }

   public:
    Direction(Direction::Cardinal direction) : m_value{direction} {}

    // Add a member function that will return a Direction object containing a
    // random direction.
    static Direction getRandomDirection() {
        return static_cast<Cardinal>(
            Random::get(Direction::up, Direction::invalid - 1));
    }

    friend std::ostream& operator<<(std::ostream& out, Direction direction);
};

//  operator- returns the opposite direction
Direction::Cardinal operator-(const Direction::Cardinal& direction) {
    switch (direction) {
        case Direction::up:
            return Direction::down;
        case Direction::down:
            return Direction::up;
        case Direction::left:
            return Direction::right;
        case Direction::right:
            return Direction::left;
        default:
            assert(false && "Should never be reached!");
            return Direction::invalid;
    }
}

// operator<< prints the direction to the console.
std::ostream& operator<<(std::ostream& out, Direction direction) {
    switch (direction.getCardinal()) {
        case Direction::up:
            out << "up";
            break;
        case Direction::down:
            out << "down";
            break;
        case Direction::left:
            out << "left";
            break;
        case Direction::right:
            out << "right";
            break;
        default:
            assert(false && "Should never be reached!");
    }

    return out;
}

Direction Command2Direction(Player::Command cmd) {
    switch (cmd) {
        case Player::Command::up:
            return Direction::up;
        case Player::Command::down:
            return Direction::down;
        case Player::Command::left:
            return Direction::left;
        case Player::Command::right:
            return Direction::right;
        default:
            assert(false && "Should never be reached!");
            return Direction::invalid;
    }
}

int main() {
    Board board{};
    std::cout << board;

    std::cout << "Generating random direction... "
              << Direction::getRandomDirection() << '\n';
    std::cout << "Generating random direction... "
              << Direction::getRandomDirection() << '\n';
    std::cout << "Generating random direction... "
              << Direction::getRandomDirection() << '\n';
    std::cout << "Generating random direction... "
              << Direction::getRandomDirection() << "\n\n";

    // query_until_quit
    Player::Command cmd{Player::Command::invalid};
    std::cout << "Enter a command: ";
    while (cmd != Player::Command::quit) {
        cmd = Player::getCommand();

        if (cmd != Player::Command::quit || cmd != Player::Command::confirm) {
            std::cout << "You entered direction: " << Command2Direction(cmd)
                      << '\n';
        }
    }
    std::cout << "\n\nBye!\n\n";

    return 0;
}
