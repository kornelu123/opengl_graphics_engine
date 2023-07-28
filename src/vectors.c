#include "vectors.h"
#include <xcb/xcb.h>
#include <math.h>
#include "line.h"

#define INT_MAX 0x7FFFFFFF
#define INT_MIN 0x80000000



vector rotate(vector vec, uint32_t deg, uint8_t rot_dir){
	double rad = (deg/1800.0)*M_PI;
	vector new_vec = vec;
	if(!rot_dir) return new_vec;
	if(rot_dir & ROT_X){
		new_vec = rotate_x(deg,new_vec,rad);
	}
	if(rot_dir & ROT_Y){
		new_vec = rotate_y(deg,new_vec,rad);
	}
	if(rot_dir & ROT_Z){
		new_vec = rotate_z(deg,new_vec,rad);
	}
	return new_vec;	
}

rectangle rot_rect(rectangle rect, uint8_t rot_dir, uint32_t deg){
	for(int i=0;i<12;i++){
		for(int j=0;j<4;j++){
			rect.tri[i].vec[j] = rotate(rect.tri[i].vec[j], deg, rot_dir);
		}
	}
	return rect;
}

rectangle create_rect(vector gen , vector pos ){
	rectangle new_rect ;
	vector points[8] = {{-gen.x,-gen.y, gen.z},{-gen.x,gen.y,gen.z},{gen.x,-gen.y,gen.z},{gen.x,gen.y,gen.z},{gen.x,-gen.y,-gen.z},{gen.x,gen.y,-gen.z},{-gen.x,-gen.y,-gen.z},{-gen.x,gen.y,-gen.z}};
	for(int i=0;i<8;i++){
		new_rect.tri[i].vec[0] = points[i];
		new_rect.tri[i].vec[1] = points[(i+1) % 8];
		new_rect.tri[i].vec[2] = points[(i+2) % 8];
		new_rect.tri[i].vec[3] = points[i];
	}
	new_rect.tri[10].vec[0] = points[6];
	new_rect.tri[10].vec[1] = points[2];
	new_rect.tri[10].vec[2] = points[4];
	new_rect.tri[10].vec[3] = points[6];
	new_rect.tri[11].vec[0] = points[6];
	new_rect.tri[11].vec[1] = points[2];
	new_rect.tri[11].vec[2] = points[0];
	new_rect.tri[11].vec[3] = points[6];
	new_rect.tri[9].vec[0] = points[7];
	new_rect.tri[9].vec[1] = points[3];
	new_rect.tri[9].vec[2] = points[5];
	new_rect.tri[9].vec[3] = points[7];
	new_rect.tri[8].vec[0] = points[7];
	new_rect.tri[8].vec[1] = points[3];
	new_rect.tri[8].vec[2] = points[1];
	new_rect.tri[8].vec[3] = points[7];
	new_rect.pos = pos;
	return new_rect;
}

void draw_cuboid(rectangle rect){
	for(int i=0;i<12;i++){
			draw_triangle(rect.tri[i], rect.pos);
	}
}

void draw_triangle(triangle tri, vector offset){
	for(int i=0;i<3;i++){
		draw_vec(tri.vec[i],tri.vec[i+1],offset);
	}
}

vector rotate_x(int deg, vector vec, double rad){
	vector new_vec ;
	double cos_t = cos(rad);
	double sin_t = sin(rad);
	double new_y = cos_t*vec.y - sin_t*vec.z; 
	double new_z = sin_t*vec.y + cos_t*vec.z;
	new_vec.x = vec.x;
	new_vec.y = (int) new_y;
	new_vec.z = (int) new_z;
	return new_vec;	
}

vector rotate_y(int deg, vector vec, double rad){
	vector new_vec ;
	double cos_t = cos(rad);
	double sin_t = sin(rad);
	double new_x = cos_t*vec.x + sin_t*vec.z; 
	double new_z = cos_t*vec.z - sin_t*vec.x;
	new_vec.x = (int) new_x;
	new_vec.y = vec.y;
	new_vec.z = (int) new_z;
	return new_vec;
}

vector rotate_z(int deg, vector vec,double rad){
	vector new_vec ;
	double cos_t = cos(rad);
	double sin_t = sin(rad);
	double new_x = cos_t*vec.x - sin_t*vec.y; 
	double new_y = sin_t*vec.x + cos_t*vec.y;
	new_vec.x = (int) new_x;
	new_vec.y = (int) new_y;
	new_vec.z = vec.z;
	return new_vec;
}
