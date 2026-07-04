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

 ######################################################################################################
 > Step #1

Because this is going to be a bigger program, let’s start with a design
exercise.

Author’s note

If you don’t have much experience designing programs up-front, you may find this
a bit difficult. That’s expected. It’s less important that you get it right, and
more important that you participate and learn.

We will go into more detail on all of these items in subsequent steps, so if you
are feeling completely lost, feel free to skip this step.

Goal: Document the key requirements for this program, and plan how your program
will be structured at a high level. We will do this in three parts.

A) What are the top-level things that your program needs to do? Here are a few
to get you started:

Board things:

    Display the game board
    …

User things:

    Get commands from user
    …

 Awnser:

 # Top level requirements: #

 Puzzle game:
    Game state machine (main menu, ongoing game, win with score, quit game
confirmation) Randomize board at start Check for puzzle solving state

 Board:
    Display game board
    Update board on valid updated states
        - Includes shifting all pieces correctly
    (optional) background highlight on pieces in correct spot

 User:
    Get and validate user input (valid inputs: w,a,s,d,q)
    Request board update
    Number of moves tracker for final score
    Main menu:
        Start button (via s)
        quit program button (via q) - this button does not trigger confirmation,
just triggers gracefull C runtime exit Quit game menu (via q): Board must be
preserved until game is confirmed to exit Confirmation prompt state machine
handling according to confirmation (y-> exit to start menu; n-> restore game)

    #
--------------------------------------------------------------------------- #

B)  What primary classes or namespaces will you use to implement the items
outlined in Step 1? Also, what will your main() function do?

    Class: Board
            object: includes 4x4 array with board
            enum: 1...15,empty
            constructor with random initializer
            non-member function to print board (overload >operator)
            win condition checker
            slide operation handling (up, down, right left)


    Class: User
            object: number of moves tracker

    Main loop:
            Main loop to handle state machine transition and menus (main, game,
win, quit confirmation)




  # ---------------------------------------------------------------------------
#

*/
