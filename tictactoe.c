/* Bloomberg 12/Aug/2020 Ontario's projected deficit to nearly double to $29 billion */

#include <stdio.h>
#include <stdlib.h>

/* Declaration of relevant functions */
void occupySquare(int userRow, int userCol);
void computerPlays();
void renderCurrentBoard();
int checkWin();
int checkDraw();

/* Declaration of variables to be used */
int squares[3][3] = {0,1,2,3,4,5,6,7,8};
int i, j; 
int userRow;
int userCol;
int nrows = 3;
int ncols = 3;

int main() {

    /* This block of code accepts the player name and prints the initial prompt */
    char name[100];
    printf("Hello! Welcome to Tic Tac Toe!\n");
    printf("Please enter your name!\n");
    scanf("%s", name);
    printf("Hello, %s! Let's play! You = X | Computer = O", name);

    /* Initial board rendering */
    renderCurrentBoard();

    /* Below is the primary game logic that repeats until a win or tie condition is reached. At the beginning of each repeat cycle the game has a redundant check to see if an end condition is triggered. If not, the player is prompted to enter a move. */
    repeat:
    checkWin();
    checkDraw();
    fflush(stdin);
    printf("\n");

    /* Below we prompt the player for a row entry and a column entry via natural numbers. We use logic to check if the input is valid and that the square chosen is not occupied. We subtract 1 from both row and column input to convert natural numbers to numbers that correspond to array values. */
    printf("Enter in a number between 1 and 3 that corresponds to the ROW you want to occupy");
    scanf("%d",&userRow);
    if((userRow < 1) || (userRow > 3)) {
        printf("The coordinate you chose isn't valid! Try again!"); 
        renderCurrentBoard();
        goto repeat;
    } 
    printf("Enter in a number between 1 and 3 that corresponds to the COLUMN you want to occupy");
    scanf("%d",&userCol);
    if((userCol < 1) || (userCol > 3)) {
        printf("The coordinate you chose isn't valid! Try again!"); 
        renderCurrentBoard();
        goto repeat;
    } 
    if((squares[userRow-1][userCol-1] == 99) || (squares[userRow-1][userCol-1] == 100)) {
        printf("The square you chose is already occupied!");
        renderCurrentBoard();
        goto repeat; 
    }

    /* If the user input is valid we allow them to occupy the given square */
    occupySquare(userRow, userCol);

    /* The computer then executes its turn */
    computerPlays();

    /* The game re-renders the board */
    renderCurrentBoard();

    /* The primary game logic repeats */
    goto repeat;
    
    return 0;
}


void occupySquare(int userRow, int userChoice) {
    squares[userRow-1][userCol-1] = 99;
    checkWin();
    checkDraw();
    printf("\n");
};

/* Computer plays by randomly choosing coordinates to occupy. More sophisticated future revisions would include more competitive logic. The computer checks to see if the square is already occupied before assigning a new value. */
void computerPlays() {
    int z,w;
    repeat:
    z = rand() % 3;
    w = rand() % 3;
    if ((squares[w][z] == 99) || (squares[w][z] == 100)) {
        goto repeat;
    } else {
        printf("The computer has made a move!");
        squares[w][z] = 100;
        checkWin();
        checkDraw();
    } 
};

/* The board is rendered using nested for loops. The user does not see the numerical values underlying the board. */
void renderCurrentBoard() {
    printf("\n");
    printf("\n");
    int t,y;
    for (t = 0; t < nrows; t++) 
    {
        for (y = 0; y < ncols; y++) 
        {
            if(squares[t][y] == 99)
            {
                printf("X ");
            } else if (squares[t][y] == 100) 
            {
                printf("O ");
            } else {
                printf("_ ");
            }
        }
        printf("\n");
    }
};

/* The game assigns int 99 to squares occupied by the player and int 100 to squares occupied by the computer. The checkWin and checkDraw functions compare sums on the board to see if a win or tie condition is triggered.  */
int checkWin(){
    /* Win condition for player */
    if ((squares[0][0] + squares[0][1] + squares[0][2]) == 297) {
        renderCurrentBoard();
        printf("You won against the computer!");
        exit(0);
    }
    if ((squares[1][0] + squares[1][1] + squares[1][2]) == 297) {
        renderCurrentBoard();
        printf("You won against the computer!");
        exit(0);
    }
    if ((squares[2][0] + squares[2][1] + squares[2][2]) == 297) {
        renderCurrentBoard();
        printf("You won against the computer!");
        exit(0);
    }
    if ((squares[0][0] + squares[1][0] + squares[2][0]) == 297) {
        renderCurrentBoard();
        printf("You won against the computer!");
        exit(0);
    }
    if ((squares[0][1] + squares[1][1] + squares[2][1]) == 297) {
        renderCurrentBoard();
        printf("You won against the computer!");
        exit(0);
    }
    if ((squares[0][2] + squares[1][2] + squares[2][2]) == 297) {
        renderCurrentBoard();
        printf("You won against the computer!");
        exit(0);
    }
    if ((squares[0][0] + squares[1][1] + squares[2][2]) == 297) {
        renderCurrentBoard();
        printf("You won against the computer!");
        exit(0);
    }
    if ((squares[2][0] + squares[1][1] + squares[0][2]) == 297) {
        renderCurrentBoard();
        printf("You won against the computer!");
        exit(0);
    }

    /* Win condition for computer */
    if ((squares[0][0] + squares[0][1] + squares[0][2]) == 300) {
        renderCurrentBoard();
        printf("You lost against the computer!");
        exit(0);
    }
    if ((squares[1][0] + squares[1][1] + squares[1][2]) == 300) {
        renderCurrentBoard();
        printf("You lost against the computer!");
        exit(0);
    }
    if ((squares[2][0] + squares[2][1] + squares[2][2]) == 300) {
        renderCurrentBoard();
        printf("You lost against the computer!");
        exit(0);
    }
    if ((squares[0][0] + squares[1][0] + squares[2][0]) == 300) {
        renderCurrentBoard();
        printf("You lost against the computer!");
        exit(0);
    }
    if ((squares[0][1] + squares[1][1] + squares[2][1]) == 300) {
        renderCurrentBoard();
        printf("You lost against the computer!");
        exit(0);
    }
    if ((squares[0][2] + squares[1][2] + squares[2][2]) == 300) {
        renderCurrentBoard();
        printf("You lost against the computer!");
        exit(0);
    }
    if ((squares[0][0] + squares[1][1] + squares[2][2]) == 300) {
        renderCurrentBoard();
        printf("You lost against the computer!");
        exit(0);
    }
    if ((squares[2][0] + squares[1][1] + squares[0][2]) == 300) {
        renderCurrentBoard();
        printf("You lost against the computer!");
        exit(0);
    }

    return 0;
};

int checkDraw(){
    if ((squares[0][0] > 98) && (squares[0][1] > 98) && (squares[0][2] > 98) && (squares[1][0] > 98) && (squares[1][1] > 98) && (squares[1][2] > 98) && (squares[2][0] > 98) && (squares[2][1] > 98) && (squares[2][2] > 98)) {
        renderCurrentBoard();
        printf("The game is a tie!");
        exit(0);
    }
    return 0;
};