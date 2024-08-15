#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "Conway.h"

int main(){
  srand(time(0));

  size_t gen = 0;

  random_grid();
  for(;;){
    display_grid();
    grid_manager();
    update_grid();
    usleep(800 * 800);
    printf("Generation: %zu", gen);
    gen++;
  }
  
  return 0;
}
