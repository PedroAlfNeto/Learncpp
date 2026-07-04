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
 > Step #7

Goal: Add the ability for players to slide the tiles on the board.

First, we should take a closer look at how sliding tiles actually works:

Given a puzzle state that looks like this:

     15   1   4
  2   5   9  12
  7   8  11  14
 10  13   6   3

When the user enters ‘w’ on the keyboard, the only tile that can go up is
tile 2.

After moving the tile, the board looks like this:

  2  15   1   4
      5   9  12
  7   8  11  14
 10  13   6   3

So, essentially what happened is we swapped the empty tile with tile 2.

Let’s generalize this procedure. When the user enters a directional command, we
need to:

    Locate the empty tile.
    From the empty tile, find the adjacent tile that is in the direction
opposite of the direction the user entered. If the adjacent tile is valid (it’s
not off the grid), swap the empty tile and adjacent tile. If the adjacent tile
is not valid, do nothing.

 Implement this by adding a member function moveTile(Direction) to the class
Board. Add this to your game loop from step 5. If the user successfully slides a
tile, the game should redraw the updated board.
*/

#include <cassert>
#include <iostream>
#include <limits>

#include "random.h"

constexpr int kBoardWidth{4};
constexpr int kNumBoardTiles{kBoardWidth * kBoardWidth};

class Tile {
   private:
    int m_tile_value{};
    static constexpr int kEmpty_value{0};

   public:
    Tile() : m_tile_value{0} {}  // default constructor

    Tile(int num) : m_tile_value{num} {
        // validate tile input
        if (num < 0 || num > kNumBoardTiles - 1) {
            assert(false && "Invalid configuration for tiles");
        }
    }

    bool isEmpty() const { return m_tile_value == kEmpty_value; }

    int readVal() const { return m_tile_value; }

    void writeVal(int value) { m_tile_value = value; }
};

std::ostream& operator<<(std::ostream& out, const Tile& tile) {
    if (tile.readVal() > 9) {  // dual digit numbers
        out << " " << tile.readVal() << " ";
    } else if (tile.readVal() > 0) {  // single digit numbers
        out << "  " << tile.readVal() << " ";
    } else {  // empty tile
        out << "    ";
    }

    return out;
}

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
    static constexpr auto max_buffer{
        std::numeric_limits<std::streamsize>::max()};

    void resetCin() {
        // Clear cin error flags
        std::cin.clear();

        // Ignore entire buffer entry
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    static void ignoreLine() {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    static Command parseCommand(char cmd) {
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
        auto cmd{Command::invalid};

        do {
            std::cin >> input;
            ignoreLine();  // remove any extraneous input
            cmd = parseCommand(input);
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

    Cardinal getValue() { return m_value; }

    // Add a member function that will return a Direction object containing a
    // random direction.
    static Direction getRandomDirection() {
        return static_cast<Cardinal>(
            Random::get(Direction::up, Direction::invalid - 1));
    }

    // operator<< prints the direction to the console.
    friend std::ostream& operator<<(std::ostream& out, Direction direction) {
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

    //  operator- returns the opposite direction
    Direction operator-() const {
        switch (m_value) {
            case Direction::up:
                return Direction::down;
            case Direction::down:
                return Direction::up;
            case Direction::left:
                return Direction::right;
            case Direction::right:
                return Direction::left;
            default:
                assert(false && "Unsupported direction!");
                return Direction::invalid;
        }
    }

    friend class Board;  // temporary, shouldnt be needed
};

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
            assert(false && "Invalid direction command!");
            return Direction::invalid;
    }
}

class Point {
   private:
    // coordinates
    int m_x{};
    int m_y{};

   public:
    Point(int x, int y) : m_x{x}, m_y{y} {}

    Point getAdjacentPoint(Direction dir) {
        Point adjacent{
            *this};  // generates copy constructor (shallow copy is sufficient)
        switch (dir.getValue()) {
            case Direction::up:
                adjacent.m_y--;
                break;
            case Direction::down:
                adjacent.m_y++;
                break;
            case Direction::left:
                adjacent.m_x--;
                break;
            case Direction::right:
                adjacent.m_x++;
                break;
            default:
                assert(false && "Should never be reached!");
        }
        return adjacent;
    }

    friend bool operator==(const Point& p1, const Point& p2) {
        return (p1.m_x == p2.m_x) && (p1.m_y == p2.m_y);
    }
    friend bool operator!=(const Point& p1, const Point& p2) {
        return !(p1 == p2);
    }

    // operator<< prints the Point to the console (for debugging only)
    friend std::ostream& operator<<(std::ostream& out, const Point& point) {
        out << '{' << point.m_x << ", " << point.m_y << '}';

        return out;
    }

    // Check if Point object coordinates fit Board object dimensions
    bool isWithinBoard() {
        return (m_x >= 0 && m_y >= 0 && m_x < kBoardWidth && m_y < kBoardWidth);
    }

    // friend void Board::moveTile(Direction::Cardinal direction);
    friend class Board;  // temporary, need to only make Board::moveTile friend
};

// Increase amount of new lines if your board isn't
// at the very bottom of the console
constexpr int g_consoleLines{25};

class Board {
   private:
    Tile m_board[kBoardWidth][kBoardWidth]{
        Tile{1},  Tile{2},  Tile{3},  Tile{4},    // y0
        Tile{5},  Tile{6},  Tile{7},  Tile{8},    // y1
        Tile{9},  Tile{10}, Tile{11}, Tile{12},   // y2
        Tile{13}, Tile{14}, Tile{0},  Tile{15}};  // y3
    //  x0      , x1      , x2     ,  x3

    void writeTile(const Point& point, int value) {
        m_board[point.m_y][point.m_x].writeVal(value);
    }
    int readTile(const Point& point) const {
        return m_board[point.m_y][point.m_x].readVal();
    }

   public:
    // Board() {
    //     // iterate board searching for empty tile
    //     int val{1};
    //     for (int x_axis{}; x_axis < kBoardWidth; ++x_axis) {
    //         for (int y_axis{}; y_axis < kBoardWidth; ++y_axis) {
    //             if (val < kNumBoardTiles) {
    //                 writeTile(Point(x_axis, y_axis), val);
    //             } else {
    //                 writeTile(Point(x_axis, y_axis), 0);
    //             }
    //             val++;
    //         }
    //     }
    // }

    Point getEmptyTilePos() const {
        // iterate board searching for empty tile
        for (int y_axis{}; y_axis < kBoardWidth; ++y_axis) {
            for (int x_axis{}; x_axis < kBoardWidth; ++x_axis) {
                if (m_board[y_axis][x_axis].isEmpty()) {
                    return {x_axis,y_axis};// implicit construction of Point type object
                }
            }
        }
        assert(false && "Not able to find empty tile in board");
    }

    friend std::ostream& operator<<(std::ostream& out, const Board& board) {
        // Print emty lines to clear console before board
        for (int i = 0; i < g_consoleLines; ++i) std::cout << '\n';

        for (int y_axis{}; y_axis < kBoardWidth; ++y_axis) {
            for (int x_axis{}; x_axis < kBoardWidth; ++x_axis) {
                out << board.m_board[y_axis][x_axis];
            }
            out << "\n";
        }

        return out;
    }

    void moveTile(Player::Command cmd) {
        auto oposite_dir{-Command2Direction(cmd)};

        // identify point of
        auto empty_tile{getEmptyTilePos()};
        auto adj_tile{empty_tile.getAdjacentPoint(oposite_dir)};
        std::cout << "Debug\n Adjacent tile was: " << adj_tile << " = "
                  << readTile(adj_tile) << '\n'
                  << "Empty was: " << empty_tile << " = "
                  << readTile(empty_tile) << '\n';

        // check if adjacent tile is on the board
        if (adj_tile.isWithinBoard()) {
            // swap tiles
            std::swap(m_board[empty_tile.m_y][empty_tile.m_x],
                      m_board[adj_tile.m_y][adj_tile.m_x]);
            // writeTile(empty_tile, readTile(adj_tile));
            // writeTile(adj_tile, 0);

        }  // else, ignore move
    }
};

int main() {
    Board board{};

    std::cout << board;


    // query_until_quit
    auto cmd{Player::Command::invalid};
    std::cout << "Enter a command: ";
    while (cmd != Player::Command::quit) {
        cmd = Player::getCommand();

        if (cmd != Player::Command::quit || cmd != Player::Command::confirm) {
            std::cout << "You entered direction: " << Command2Direction(cmd)
                      << '\n';
            board.moveTile(cmd);
            std::cout << board;  // print updated board
        }
    }
    std::cout << "\n\nBye!\n\n";

    return 0;
}