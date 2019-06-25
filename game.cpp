#include <ctime>
#include <gl\glut.h>
#include "game.h"

int posX = 20, posY = 20;
int gridX, gridY;
int foodX, foodY;

short sDirection = RIGHT;


extern bool gameOver;
bool food = true;

void initGrid(int x, int y) {
	gridX = x;
	gridY = y;
}

void drawGrid() {
	for (int x = 0; x < gridX; x++) {
		for (int y = 0; y < gridY; y++) {
			unit(x, y);
		}
	}
}

void unit(int x, int y) {

	if (x == 0 || y == 0 || x == gridX - 1 || y == gridY - 1) {
		glLineWidth(3.0);
		glColor3f(1.0, 0.0, 0.0);
	}
	else {
		glLineWidth(1.0);
		glColor3f(1.0, 1.0, 1.0);
	}

	glBegin(GL_LINE_LOOP);
	glVertex2f(x, y);
	glVertex2f(x + 1, y);
	glVertex2f(x + 1, y + 1);
	glVertex2f(x, y + 1);
	glEnd();
}

void drawSnake() {

	switch (sDirection) {
	case UP:
		posY++;
		break;
	case DOWN:
		posY--;
		break;
	case RIGHT:
		posX++;
		break;
	case LEFT:
		posX--;
		break;
	}
	glColor3f(0.0, 0.0, 1.0);
	glRectd(posX, posY, posX + 1, posY + 1);
	
	checkGameOver();
	checkSnakePosition();
}

void drawFood() {
	if (food)
		random(foodX, foodY);
	food = false;
	glColor3f(0.0, 1.0, 0.0);
	glRectd(foodX, foodY, foodX + 1, foodY + 1);
}

void random(int &x, int &y) {
	
	int _maxX = gridX - 2;
	int _maxY = gridY - 2;
	int _min = 1;

	srand(time(NULL));
	x = rand() % (_maxX - _min) + _min;
	y = rand() % (_maxY - _min) + _min;
}

void checkGameOver() {
	if (posX == 0 || posX == gridX - 1 || posY == 0 || posY == gridY - 1)
		gameOver = true;
}

void checkSnakePosition() {
	if (posX == foodX && posY == foodY)
		food = true;
}