#include <gl/glut.h>
#include <iostream>

void display_callback();
void init();

int main(int argc, char **argv) {

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("SNAKEGAME");

	glutDisplayFunc(display_callback);

	init();

	glutMainLoop();

	return 0;
}

void init() {
	glClearColor(1.0, 0.0, 0.0, 1.0);


}

void display_callback() {
	glClear(GL_COLOR_BUFFER_BIT);

	glutSwapBuffers();
}