#include <gl/glut.h>
#include <iostream>
#include "game.h"

#define COLUMNS 40
#define ROWS 40
#define FPS 10
#define ESC 27

extern short sDirection;

void keyboard_callback(unsigned char, int, int);
void special_callback(int, int, int);
void reshape_callback(int,int);
void timer_callback(int);
void display_callback();

void init();

int index;

int main(int argc, char **argv) {

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("SNAKEGAME");

	glutDisplayFunc(display_callback);
	glutReshapeFunc(reshape_callback);
	glutTimerFunc(0, timer_callback, 0);
	glutKeyboardFunc(keyboard_callback);
	glutSpecialFunc(special_callback);
	init();

	glutMainLoop();

	return 0;
}

void init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	initGrid(COLUMNS, ROWS);

}

void display_callback() {
	glClear(GL_COLOR_BUFFER_BIT);
	drawGrid();
	drawSnake();
	glutSwapBuffers();

}

void reshape_callback(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, COLUMNS, 0.0, ROWS, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

void timer_callback(int time) {


	glutPostRedisplay();
	glutTimerFunc(1000 / FPS, timer_callback, 0);
}

void special_callback(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		if (sDirection != DOWN)
			sDirection = UP;
		break;
	case GLUT_KEY_DOWN:
		if (sDirection != UP)
			sDirection = DOWN;
		break;
	case GLUT_KEY_RIGHT:
		if (sDirection != LEFT)
			sDirection = RIGHT;
		break;

	case GLUT_KEY_LEFT:
		if (sDirection != RIGHT)
			sDirection = LEFT;
		break;
	}
}

void keyboard_callback(unsigned char key,int x,int y) {
	
	switch (key) {
	case ESC:
		exit(0);	
	}
}