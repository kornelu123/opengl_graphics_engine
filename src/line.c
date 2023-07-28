#include "line.h"
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "vectors.h"

int buff[WIDTH][HEIGHT];
int z_buff[2][WIDTH][HEIGHT];
int end_x = WIDTH/2;
int end_y = HEIGHT/2;
int start_x = -WIDTH/2;
int start_y = -HEIGHT/2;


void draw_line(int x1, int y1, int x2, int y2){
	int deltax, deltay, g, h, c;
	deltax = x2 - x1;
	if(deltax > 0)g = 1;else g = -1;
	deltax = abs(deltax);	
	deltay = y2 - y1;
	if(deltay > 0) h = 1;else h = -1;
	deltay = abs(deltay);
	if ( deltax > deltay ) {
    	c = -deltax;
    	while ( x1 != x2 ) {
      		set_pixel ( x1, y1 );
      		c += 2*deltay;
      		if ( c > 0 ) { y1 += h; c -= 2*deltax; }
      		x1 += g;
    		}
  	}else {
    		c = -deltay;
   		while ( y1 != y2 ) {
      		set_pixel ( x1, y1 );
      		c += 2*deltax;
      		if ( c > 0 ) { x1 += g; c -= 2*deltay; }
  	    	y1 += h;
    		}
  	}
}

void draw_vec(vector start, vector end, vector offset){
	int x1, x2, y1, y2; x1 = (SCALE_RATIO*start.x + offset.x)/(start.z + offset.z);
	x2 = (SCALE_RATIO*end.x + offset.x)/(end.z + offset.z);
	y1 = (SCALE_RATIO*start.y + offset.y)/(start.z + offset.z);
	y2 = (SCALE_RATIO*end.y + offset.y)/(end.z + offset.z);
	draw_line(x1,y1,x2,y2);
}	

void set_pixel(int x, int y){
	buff[x + end_x][y + end_y] = 1;
}

void clear_buffer(){
	for(int x=0;x< WIDTH;x++){
		for(int y=0;y<HEIGHT;y++){
			buff[x][y] = 0;		
		}
	}
}

void dump_buffer(){
	float xf, yf;
	for(int x=start_x;x<end_x;x++){
		for(int y=start_y;y<end_y;y++){
			if(buff[x + end_x][y + end_y]){
			xf = (float)x/(float)(end_x);
			yf = (float)y/(float)(end_y);
			glVertex2f(xf,yf);
			}
		}
	}
	clear_buffer();
}

