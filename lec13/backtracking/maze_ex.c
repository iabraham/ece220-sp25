#include <stdio.h>

int ExitMaze(char maze[MAZE_HEIGHT][MAZE_WIDTH], int xpos, int ypos){ 
  if (xpos < 0 || xpos >= MAZE_HEIGHT || ypos < 0 || ypos >= MAZE_WIDTH) 
    return 0; 

  if (maze[xpos][ypos] == 'E')        // Found the Exit!
    return 1; 

  if (maze[xpos][ypos] != ' ')        // Space is not empty (possibly X or V)
    return 0; 

  maze[xpos][ypos]='V';               // Mark this space as visited

  // Go Down 
  if (ExitMaze(maze, xpos + 1, ypos)) { 
    maze[xpos][ypos]='P';
    return 1; 
  } 

  // Go Right 
  if (ExitMaze(maze, xpos, ypos + 1)) { 
    maze[xpos][ypos]='P';
    return 1; 
  } 
  
  // Go Up 
  if (ExitMaze(maze, xpos - 1, ypos)) { 
    maze[xpos][ypos]='P';
    return 1; 
  } 

  // Go Left 
  if (ExitMaze(maze, xpos, ypos - 1)) { 
    maze[xpos][ypos]='P';
    return 1; 
  } 

  // No path to Exit 
  return 0; 
}

void print_maze(char maze[MAZE_HEIGHT][MAZE_WIDTH]){
  int i, j;
  printf("Maze is: \n");
  for (i=0; i<MAZE_HEIGHT; i++){
    for (j=0; j<MAZE_WIDTH; j++)
         printf("%c ", maze[i][j]);
    printf("\n");
  }
}

int main(){
  print_maze(maze);
  ExitMaze(maze, 0, 0);
  print_maze(maze);
  return 0;
}
