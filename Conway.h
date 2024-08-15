#ifndef __CONWAY__
#define __CONWAY__

#define ALIVE 1
#define DEAD 0

#define HEIGHT 50
#define WIDTH 98

int random_int(void);
void random_grid(void);
void display_grid(void);
void grid_manager(void);
void update_grid(void);
int position(size_t y, size_t x);
void rules(size_t y, size_t x, size_t alives);
#endif
