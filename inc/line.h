#ifndef LINE_H_
#define LINE_H_

#define HEIGHT 768 
#define WIDTH 1366 

#include "vectors.h"
void draw_vec(vector start, vector end, vector offset);

void draw_vec(vector start, vector end, vector offset);

void draw_line(int x1, int y1, int x2, int y2);

void set_pixel(int x, int y);

void dump_buffer();

#endif
