#ifndef VECTORS_H_
#define VECTORS_H_
#include <stdint.h>
#include <xcb/xcb.h>
#include "line.h"

#define SCALE_RATIO 500
#define ROT_X 1
#define ROT_Y 2
#define ROT_Z 4

typedef struct {
	int32_t x;
       	int32_t y;
	int32_t z;	
}vector;

typedef struct{
	vector vec[4];
}triangle;

typedef struct {
	triangle tri[12];
	vector   pos;
}rectangle;

rectangle rot_rect(rectangle rect, uint8_t rot_dir, uint32_t deg);

vector rotate(vector vec, uint32_t deg, uint8_t rot_dir);


void draw_cuboid(rectangle rect);

void draw_triangle(triangle tri,vector offset);

vector rotate_x(int deg, vector vec,double rad);

vector rotate_y(int deg, vector vec,double rad);

vector rotate_z(int deg, vector vec,double rad);

rectangle create_rect(vector gen, vector pos);

#endif
