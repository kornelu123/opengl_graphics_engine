#ifndef LINE_H_
#define LINE_H_

#define HEIGHT 768 
#define WIDTH 1366 

typedef struct{
	int x[2];
	int y[2];
}line;

void draw_line(line lin);

void set_pixel(int x, int y);

void dump_buffer();

#endif
