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
 > Step #8

 Goal: In this step, we’ll finish our game. Randomize the initial state of the
game board. Also, detect when user wins, so after that we can print a win
message and quit the game.

 We need to be careful about how we randomize our puzzle, because not every
puzzle is solvable. For example, there is no way to solve this puzzle:

  1   2   3   4
  5   6   7   8
  9  10  11  12
 13  15  14

 If we just blindly randomize the numbers in the puzzle, there is a chance that
we will generate such an unsolvable puzzle. With a physical version of the
puzzle, we’d randomize the puzzle by sliding tiles in random directions until
the tiles were sufficiently mixed.
 The solution for such a randomized puzzle is to slide each tile in the opposite
direction that it was slid to randomize it in the first place. Thus, randomizing
puzzles this way always generates a solvable puzzle.

 We can have our program randomize the board in the same way.

 Once the user has solved the puzzle, the program should print "\n\nYou
won!\n\n" and then exit normally.
*/

#include <cassert>
#include <iostream>
#include <limits>

#include "random.h"

constexpr int kBoardWidth{4};
constexpr int kNumBoardTiles{kBoardWidth * kBoardWidth - 1};

class Tile {
   private:
    int m_tile_value{};
    static constexpr int kEmpty_value{0};

   public:
    // default constructor

    Tile(int num) : m_tile_value{num} {
        // validate tile input
        if (num < 0 || num > kNumBoardTiles) {
            assert(!"Invalid configuration for tiles");
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
   public:
    enum Command {  // Player available commands
        up,
        down,
        left,
        right,
        quit,
        confirm,
        cancel,
        invalid
    };
    static bool isDirection(Command cmd) {
        switch (cmd) {
            case Command::up:
            case Command::down:
            case Command::left:
            case Command::right:
                return true;
            default:
                return false;
        }
    }

   private:

    void resetCin() {
        // Clear cin error flags
        std::cin.clear();

        // Ignore entire buffer entry
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
            case 'c':
                return Command::cancel;
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
            // Reset cin buffer
            resetCin();

            std::cin >> input;
            cmd = parseCommand(input);
        } while (std::cin.fail() || cmd == Command::invalid);

        return cmd;
    }
};

//  Implement a helper class named Direction, which will allow us to create
//  objects that represent the cardinal directions (up, left, down, or right).
class Direction {
   public:
    enum Cardinal {
        up,
        down,
        left,
        right,
        invalid  // also functions as Cardinal max
    };

   private:
    Cardinal m_value{invalid};

    Direction::Cardinal getCardinal() const { return m_value; }

   public:
    Direction(Direction::Cardinal direction) : m_value{direction} {}

    Cardinal getValue() const{ return m_value; }

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
                assert(!"Should never be reached!");
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
                assert(!"Unsupported direction!");
                return Direction::invalid;
        }
    }
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
            assert(!"Invalid direction command!");
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

    Point getAdjacentPoint(Direction dir) const {
        Point adjacent{*this};  // generates default copy constructor (shallow
                                // copy is sufficient)
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
                assert(!"Should never be reached!");
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
    bool isWithinBoard() const {
        return (m_x >= 0 && m_y >= 0 && m_x < kBoardWidth && m_y < kBoardWidth);
    }

    friend class Board;  // required for Board::moveTile to access private x y
                         // vars
};

// Increase amount of new lines if your board isn't
// at the very bottom of the console
constexpr int g_consoleLines{50};

class Board {
   private:
    static constexpr int kNumShuffles{100};  // higher increases dificulty
    // Board must be solvable state initialized (swapped 15 and 0, still solvable)
    Tile m_board[kBoardWidth][kBoardWidth]{
        Tile{1},  Tile{2},  Tile{3},  Tile{4},    // y0
        Tile{5},  Tile{6},  Tile{7},  Tile{8},    // y1
        Tile{9},  Tile{10}, Tile{11}, Tile{12},   // y2
        Tile{13}, Tile{14}, Tile{15},  Tile{0}};  // y3
    //  x0      , x1      , x2     ,  x3

   private:
    int m_num_moves{};  // track number of moves for scoring win

    void writeTile(const Point& point, int value) {
        m_board[point.m_y][point.m_x].writeVal(value);
    }
    int readTile(const Point& point) const {
        return m_board[point.m_y][point.m_x].readVal();
    }

   public:
    Board() {
        // Shuffle board
        for (std::size_t shuffles{kNumShuffles}; shuffles > 0; shuffles--) {
            moveTile(Direction::getRandomDirection());
        }
        // reset moves after shuffle
        m_num_moves = 0;
    }
    bool playerWon() const {
        // iterate board to check order for winning
        int value{1};
        for (int y_axis{}; y_axis < kBoardWidth; ++y_axis) {
            for (int x_axis{}; x_axis < kBoardWidth; ++x_axis) {
                if (m_board[y_axis][x_axis].readVal() != value &&
                    value <=
                        kNumBoardTiles) {  // limit validation until last tile
                    return false;          // puzzle not solved, resume
                }
                value++;
            }
        }
        return true;  // debug
    }

    Point getEmptyTilePos() const {
        // iterate board searching for empty tile
        for (int y_axis{}; y_axis < kBoardWidth; ++y_axis) {
            for (int x_axis{}; x_axis < kBoardWidth; ++x_axis) {
                if (m_board[y_axis][x_axis].isEmpty()) {
                    return {
                        x_axis,
                        y_axis};  // implicit construction of Point type object
                }
            }
        }
        assert(!"Not able to find empty tile in board");
        // never reached
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

    void moveTile(Direction dir) {
        // identify point of
        auto empty_tile{getEmptyTilePos()};
        auto adj_tile{
            empty_tile.getAdjacentPoint(-dir)};  // oposite adjacent for move
        // check if adjacent tile is on the board
        if (adj_tile.isWithinBoard()) {
            // swap tiles
            std::swap(m_board[empty_tile.m_y][empty_tile.m_x],
                      m_board[adj_tile.m_y][adj_tile.m_x]);

            // track number of moves
            m_num_moves++;
        }  // else, ignore move
    }

    int getScore() const { return m_num_moves; }
};

int main() {
    Board board{};

    std::cout << board;

    // query_until_quit
    auto cmd{Player::Command::invalid};
    std::cout << "Enter a command: ";
    while (!board.playerWon()) {
        cmd = Player::getCommand();

        if (Player::isDirection(cmd)) {
            board.moveTile(Command2Direction(cmd));
        }

        // exit confirmation menu
        if (cmd == Player::Command::quit) {
            do {
                std::cout << "Confirm exit (y) or cancel (c):";
                cmd = Player::getCommand();

                if (cmd == Player::Command::confirm) {
                    std::cout << "\n\nBye!\n\n";
                    return 0;  // terminate game
                }
            } while (cmd != Player::Command::cancel);
        }  // resume puzzle game

        std::cout << board;  // print updated board
    }

    std::cout << "\n\nYou won!\n\n";
    std::cout << "You made " << board.getScore() << " moves.\n";
    return 0;  // program finish
}