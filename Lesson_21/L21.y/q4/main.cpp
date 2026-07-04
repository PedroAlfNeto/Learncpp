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
 > Step #4

 Goal: In this step, we’ll allow the user to repeatedly input game commands,
handle invalid input, and implement the quit game command.

 These are the 5 commands our game will support (each of which will be input as
a single character):

    ‘w’ - slide tile up
    ‘a’ - slide tile left
    ‘s’ - slide tile down
    ‘d’ - slide tile right
    ‘q’ - quit game

 When the user runs the game, the following should occur:

    The (solved) board should be printed to the console.
    The program should repeatedly get valid game commands from the user. If the
user enters an invalid command or extraneous input, ignore it.

 For each valid game command:

    Print "Valid command: " and the character the user input.
    If the command is the quit command, also print "\n\nBye!\n\n" and then quit
the app.

 Because our user input routines do not need to maintain any state, implement
them inside a namespace named UserInput.

The output of the program should match the following:

  1   2   3   4
  5   6   7   8
  9  10  11  12
 13  14  15
w
Valid command: w
a
Valid command: a
s
Valid command: s
d
Valid command: d
f
g
h
Valid command: q


Bye!




*/

#include <cassert>
#include <iostream>
#include <limits>

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
    // Player() default constructor is ok

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

    static Command validate_cmd(char cmd) {
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
            std::cout << "Insert command (w,a,s,d,q): ";
            std::cin >> input;
            cmd = validate_cmd(input);
        } while (std::cin.fail() || cmd == Command::invalid);

        std::cout << "Valid command: " << input << '\n';

        return cmd;
    }
};

int main() {
    Board board{};
    std::cout << board;

    // query_until_quit
    Player::Command cmd{Player::Command::invalid};
    while (cmd != Player::Command::quit) {
        cmd = Player::getCommand();
    }
    std::cout << "\n\nBye!\n\n";

    return 0;
}