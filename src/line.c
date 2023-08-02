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


void draw_line(line lin){
	int deltax, deltay, g, h, c;
	deltax = lin.x[1] - lin.x[0];
	if(deltax > 0)g = 1;else g = -1;
	deltax = abs(deltax);	
	deltay = lin.y[1] - lin.y[0];
	if(deltay > 0) h = 1;else h = -1;
	deltay = abs(deltay);
	if ( deltax > deltay ) {
    	c = -deltax;
    	while ( lin.x[0] != lin.x[1] ) {
      		set_pixel ( lin.x[0], lin.y[0] );
      		c += 2*deltay;
      		if ( c > 0 ) { lin.y[0] += h; c -= 2*deltax; }
      		lin.x[0] += g;
    		}
  	}else {
    		c = -deltay;
   		while ( lin.y[0] != lin.y[1] ) {
      		set_pixel ( lin.x[0], lin.y[0] );
      		c += 2*deltax;
      		if ( c > 0 ) { lin.x[0] += g; c -= 2*deltay; }
  	    	lin.y[0] += h;
    		}
  	}
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

