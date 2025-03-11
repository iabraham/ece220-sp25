#include <stdio.h>

int N=7;

int is_safe(int board[N][N], int row, int col){
  int i, j;
  for (i=row-1; i>=0; i--){ //Check along column
    if (board[i][col]==1)
      return 0;
  }
  // Check diagonal to upper left
  for (i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
    if (board[i][j] == 1)
      return 0;
  }
  // Check diagonal to upper right
  for (i=row-1, j=col+1; i>=0 && j<N; i--, j++){
    if (board[i][j]==1)
      return 0;
  }
  return 1;
}


/*Function places a queen in row rnum */
int place_queen(int board[N][N], int rnum){       
  if (rnum == N)  // Finished all rows
    return 1;     // Found a solution
  else{
    // Iterate over possible columns
    for(int cnum=0; cnum < N; cnum++)
      if (is_safe(board, rnum, cnum)==1){
        board[rnum][cnum] = 1; // Place a queen there
        // Update row number and recurse
        if (place_queen(board, rnum+1)==1)
          return 1;
        else // Hit a road block down the line
          board[rnum][cnum]=0; // Remove queen
    } // Try next column along row
  }   // For loop finished without hitting a return 
  return 0;   // Solution doesn't exist. 
}


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
