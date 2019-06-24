#include <gl/glut.h>
#include <iostream>

int main(int argc, char **argv) {

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB);
	
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("SNAKEGAME");

	return 0;
}