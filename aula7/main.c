#define N 4
#include<stdio.h>

void printSolution(int chessboard[N][N])
{
    int i, j;
    for(i = 0; i < N; i++){
        for (j = 0; j < N; j++)
            printf(" %d ", chessboard[i][j]);
        printf("\n");
    }
    printf("\n\n");
}

int isPositionSafe(int chessboard[N][N], int line, int column)
{
    int i, j;

    for (i = 0; i < column; i++)
        if (chessboard[line][i])
            return 0;

    for (i=line, j=column; i>=0 && j>=0; i--, j--)
        if (chessboard[i][j])
            return 0;

    for (i=line, j=column; j>=0 && i<N; i++, j--)
        if (chessboard[i][j])
            return 0;

    return 1;
}

int solveWithRecursion(int chessboard[N][N], int column, int previousFirstQueen[N])
{
    int i = 0, j;

    if(column == N){
        return 1;
    }

    while(i<N){
        for(j=0; j<N; j++){
            if(i == previousFirstQueen[j]){
                i++;
            }
        }

        if(isPositionSafe(chessboard, i, column)){
            chessboard[i][column] = 1;

            if(solveWithRecursion(chessboard, column+1, previousFirstQueen)){
                return 1;
            }
        }

        chessboard[i][column] = 0;
        i++;
    }

    return 0;
}

int solveNQueensPuzzle(int index, int firstQueen[N], int chessboard[N][N])
{
    int i, j;
    if (solveWithRecursion(chessboard, 0, firstQueen)){
      printSolution(chessboard);

      for(i=0; i<N; i++){
        if(chessboard[i][0]){
            firstQueen[index] = i;
            index++;
        }
      }

      if(index == 4){
        printf("No more solutions were found");

        return 1;
      }

      solveNQueensPuzzle(index, firstQueen, chessboard);
    }
}

prepareChessboard()
{
    int chessboard[N][N], i, j;

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            chessboard[i][j] = 0;
        }
    }

    int firstQueen[N] = {-1,-1,-1,-1};
    solveNQueensPuzzle(0, firstQueen, chessboard);
}

int main()
{
    prepareChessboard();
    return 0;
}
