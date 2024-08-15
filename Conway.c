#include <stdio.h>
#include <stdlib.h>

#include "Conway.h"

int grid[HEIGHT][WIDTH];
int grid_diff[HEIGHT][WIDTH];
char const cells_level[] = {' ', '#'};
int const grid_pos[][7] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

int random_int(void){
  return (rand() % 2);
}

void random_grid(void){
  size_t h = HEIGHT/1.5;
  size_t w = WIDTH/2;
  for(size_t dy = 0; dy < h; dy++){
    for(size_t dx = 0; dx < w; dx++){
      size_t y = dy + HEIGHT/2 - h/2;
      size_t x = dx + WIDTH/2 - w/2;
      grid[y][x] = random_int();
    }
  }
}
void display_grid(void){
  for(size_t y = 0; y < HEIGHT; y++){
    for(size_t x = 0; x < WIDTH; x++){
      char c =  cells_level[grid[y][x]];
      printf("%c ", c);
    }
    printf("\n");
  }
}
int position(size_t y, size_t x){
  size_t n_alives = 0;
  size_t n_y = 0;
  size_t n_x = 0;
  
  for (size_t dy = 0; dy < 8 ; dy++){
    for(size_t dx = 0; dx < 2; dx++){
      n_y = y + grid_pos[dy][dx];
      dx++;
      n_x = x + grid_pos[dy][dx];
      if(n_y < HEIGHT && n_x < WIDTH){
	      if(grid[n_y][n_x] == ALIVE){
	        n_alives++;
	      }
      }
    }
  }
  return n_alives;
}

void rules(size_t y, size_t x, size_t alives){
  
  switch(grid[y][x]){
  case DEAD:
    if(alives == 3){
      grid_diff[y][x] = ALIVE;
    }
    break;
  case ALIVE:
    if(alives < 2){
      grid_diff[y][x] = DEAD;
    } else if(alives > 3) {
      grid_diff[y][x] = DEAD;
    }
    break;
  }
}

void grid_manager(void){
  for(size_t y = 0; y < HEIGHT; y++){
    for(size_t x = 0; x < WIDTH; x++){
      size_t alives = position(y, x);
      rules(y, x, alives);
    }
  }
}

void update_grid(void){
  for(int y = 0; y < HEIGHT; y++){
    for(int x = 0; x < WIDTH; x++){
      grid[y][x] = grid_diff[y][x];
    }
  }
}
