#include <GL/glut.h>
#include "line.h"
#include <GLFW/glfw3.h>
#include "vectors.h"
#include <unistd.h>

vector gen    = {60,200, 40};
vector offset = {100,40,400};
int count=0;

void renderScene() {
	
	rectangle rect = create_rect(gen, offset);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	rect = rot_rect(rect,ROT_X | ROT_Z |ROT_Y, count);
	glBegin(GL_POINTS);
		draw_cuboid(rect);
		dump_buffer();	
	glEnd();
	count = (count +1)%3600;
        glutSwapBuffers();
}

int main(int argc, char **argv) {
	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(WIDTH,HEIGHT);
	glutCreateWindow("Lighthouse3D - GLUT Tutorial");	
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	// register callbacks
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);

	// enter GLUT event processing cycle
	glutMainLoop();
	
	return 1;
}
