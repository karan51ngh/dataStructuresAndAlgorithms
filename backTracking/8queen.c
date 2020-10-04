#include <stdio.h>
#include <stdlib.h>
//functions
int placequeen(int, int **, int); //placing the queen
int fre(int, int, int **);        //checks if the board is free
void update(int, int, int **);    //updates the board
void undo(int **);                //undoes the last move
void attack(int **);              //keeps track of the attack grid
//program
void main()
{
    int i, j, n;
    int **board;
    printf("enter the number of queens\n");
    scanf("%d", &n);
    board = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        board[i] = (int *)malloc(n * sizeof(int));
    }
    if (placequeen(0, board, n))
    {
        print(board);
    }
}
int placequeen(int i, int **board, int n)
{
    int c;
    int extendsoln;
    for (c = 0; c < n; c++)
    {
        if (fre(i, c, board)) //check weather i,c is free to place the queen
        {
            update(i, c, board); //update the board by placing the queen
            if (i == n - 1)      //base case: the last queen is placed
            {
                return (1);
            }
            extendsoln = placequeen(i + 1, board, n);
            if (extendsoln)
            {
                return (1);
            }
            else
            {
                undo(i, c, board);
            }
        }
    }
}

void update(int i, int c, int **board)
{
}
void undo(int **board)
{
}
int fre(int i, int c, int **board)
{
}
void attack(int **)
{
}