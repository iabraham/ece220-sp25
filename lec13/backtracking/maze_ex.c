#include <stdio.h>

#define MAZE_HEIGHT 8
#define MAZE_WIDTH  8


int ExitMaze(char maze[MAZE_HEIGHT][MAZE_WIDTH], int xpos, int ypos){ 

  // Delineate/handle all the basic cases 
  
  if (xpos < 0 || xpos >= MAZE_HEIGHT || ypos < 0 || ypos >= MAZE_WIDTH) 
    return 0; 

  if (maze[xpos][ypos] == 'E')        // Found the Exit!
    return 1; 

  if (maze[xpos][ypos] != ' ')        // Space is not empty (possibly X or V)
    return 0; 

  // Take an action 
  maze[xpos][ypos]='V';               // Mark this space as visited

  // Explore choices 
  
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
  char maze[MAZE_HEIGHT][MAZE_WIDTH]={{" X  X X"},
                                      {" X  X  "},
                                      {"    XXX"},
                                      {" X     "},
                                      {" XXXX  "},
                                      {"X  EX  "},
                                      {"XX XX X"},
                                      {"      X"}};
  print_maze(maze);
  if (ExitMaze(maze, 1, 7)){
  print_maze(maze);
  }
  else{
    printf("No path to exit!\n");
  }
  return 0;
}
