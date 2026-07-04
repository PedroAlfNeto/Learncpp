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
 > Step #6

 Goal: Implement a helper class that will make it easier for us to index the
tiles in our game board.

 Our game board is a 4×4 grid of Tile, which we store in two-dimensional array
member m_tiles of the Board class. We will access a given tile using its {x, y}
coordinates. For example, the top left tile has coordinate {0, 0}. The tile to
the right of that has coordinate {1, 0} (x becomes 1, y stays 0). The tile one
down from that has coordinate {1, 1}.

 Since we’ll be working with coordinates a lot, create a helper class named
Point that stores an {x, y} pair of coordinates. We should be able to compare
two Point objects for equality and inequality. Also implement a member function
named getAdjacentPoint that takes a Direction object as a parameter and returns
the Point in that direction. For example, Point{1,
1}.getAdjacentPoint(Direction::right) == Point{2, 1}.

 The main() should run and print true for every test-case.
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

constexpr std::size_t kBoardWidth{4};  // square width

// Increase amount of new lines if your board isn't
// at the very bottom of the console
constexpr int g_consoleLines{25};

class Board {
   private:
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

// Your code goes here

//  Since we’ll be working with coordinates a lot, create a helper class named
// Point that stores an {x, y} pair of coordinates. We should be able to compare
// two Point objects for equality and inequality. Also implement a member
// function named getAdjacentPoint that takes a Direction object as a parameter
// and returns the Point in that direction. For example, Point{1,
// 1}.getAdjacentPoint(Direction::right) == Point{2, 1}.

class Point {
   private:
    // coordinates
    int m_x{};
    int m_y{};

   public:
    Point(int x, int y) : m_x{x}, m_y{y} {}

    Point getAdjacentPoint(Direction::Cardinal cardinal) {
        Point AdjacentPoint{*this};  // enforces generation of default copy
                                     // constructor (shallow copy)

        switch (cardinal) {
            case Direction::up:
                AdjacentPoint.m_y--;
                break;
            case Direction::down:
                AdjacentPoint.m_y++;
                break;
            case Direction::left:
                AdjacentPoint.m_x--;
                break;
            case Direction::right:
                AdjacentPoint.m_x++;
                break;
            default:
                assert(false && "Should never be reached!");
        }
        // check out of bounds for adjancent points
        if (AdjacentPoint.m_x < 0 || AdjacentPoint.m_y < 0 ||
            AdjacentPoint.m_x >= kBoardWidth ||
            AdjacentPoint.m_y >= kBoardWidth) {
            std::cout
                << "Beware adjacent point requested is out of board bounds.";
        }
        return AdjacentPoint;
    }

    friend bool operator==(const Point& p1, const Point& p2) {
        return (p1.m_x == p2.m_x) && (p1.m_y == p2.m_y);
    }
    friend bool operator!=(const Point& p1, const Point& p2) {
        return !(p1 == p2);
    }

    // operator<< prints the Point to the console.
    friend std::ostream& operator<<(std::ostream& out, const Point& point) {
        out << '{' << point.m_x << ", " << point.m_y << '}';

        return out;
    }
};

int main() {
    // print booleans as strings "true" and "false" instead of numerics "1" and
    // "0" respectively
    std::cout << std::boolalpha;

    std::cout << (Point{1, 1} == Point{1, 1}) << '\n';

    std::cout << (Point{1, 1}.getAdjacentPoint(Direction::up) == Point{1, 0})
              << '\n';
    std::cout << Point{1, 1}.getAdjacentPoint(Direction::up) << '\n';

    std::cout << (Point{1, 1}.getAdjacentPoint(Direction::down) == Point{1, 2})
              << '\n';
    std::cout << Point{1, 1}.getAdjacentPoint(Direction::down) << '\n';

    std::cout << (Point{1, 1}.getAdjacentPoint(Direction::left) == Point{0, 1})
              << '\n';
    std::cout << Point{1, 1}.getAdjacentPoint(Direction::left) << '\n';

    std::cout << (Point{1, 1}.getAdjacentPoint(Direction::right) == Point{2, 1})
              << '\n';
    std::cout << Point{1, 1}.getAdjacentPoint(Direction::right) << '\n';

    std::cout << (Point{1, 1} != Point{2, 1}) << '\n';
    std::cout << (Point{1, 1} != Point{1, 2}) << '\n';
    std::cout << !(Point{1, 1} != Point{1, 1}) << '\n';

    return 0;
}