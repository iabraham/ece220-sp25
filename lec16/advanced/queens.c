#include <stdio.h>
#include <stdlib.h>

int is_safe(int **board, int row, int col, int N){
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

int *place_queen(int **board, int rnum, int N){
  static int count=0;
  count++;
  if (rnum == N)  // Finished all rows
    return &count;     // Found a solution
  else{
    // Iterate over possible columns
    for(int cnum=0; cnum < N; cnum++)
      if (is_safe(board, rnum, cnum, N)==1){
        board[rnum][cnum] = 1; // Place a queen there
        // Update row number and recurse
        if (place_queen(board, rnum+1, N))
          return &count;
        else // Hit a road block down the line
          board[rnum][cnum]=0; // Remove queen
    } // Try next column along row
  }   // For loop finished without hitting a return 
  return NULL;   // Solution doesn't exist. 
}

// Helper function to print state of board
void print_board(int **board, int N){
  for (int i=0; i<N; i++){
    for (int j=0; j<N; j++)
      printf("%d ", board[i][j]);
    printf("\n");
  }
}

int main(int argc, char *argv[]){
  int *count;
  int N = strtol(argv[1], NULL, 10);
  if (N < 4){
    printf("No solution possible for N < 4\n");
    return 1;
  }
  int **board = (int **)malloc(N*sizeof(int *));
  for (int i=0; i<N; i++)
    board[i] = (int *)malloc(N*sizeof(int));

  //Initialize the board
  for (int i=0; i<N; i++)
    for (int j=0; j<N; j++)
      board[i][j]=0;

  count = place_queen(board, 0, N);
  print_board(board, N);
  FILE *fp = fopen("queens.txt", "a");
  fprintf(fp, "%d, %d\n", N, *count);
  fclose(fp);

  // Deallocate memory
  // Free each row
  for (int i=0; i<N; i++)
    free(board[i]);
  // Free the array of rows
  free(board);
}
