#include <stdio.h>

int N=4;


// Helper function to print state of board
void print_board(int board[N][N]){
  for (int i=0; i<N; i++){
    for (int j=0; j<N; j++)
      printf("%d ", board[i][j]);
    printf("\n");
  }
}

int main(void){
  int board[N][N];
  
  //Initialize the board
  for (int i=0; i<N; i++)
    for (int j=0; j<N; j++)
      board[i][j]=0;

  place_queen(board, 0);
  print_board(board);
}
