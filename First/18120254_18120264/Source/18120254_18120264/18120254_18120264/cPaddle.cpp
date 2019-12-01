#include "cPaddle.h"
cPaddle::cPaddle(int posX, int posY) {
	originalX = posX;
	originalY = posY;
	x = posX;
	y = posY;
	prex = posX;
	prey = posY;
}
int cPaddle::getX() {
	return x;
}
int cPaddle::getY() {
	return y;
}
int cPaddle::getPreX() {
	return prex;
}
int cPaddle::getPreY() {
	return prey;
}
void cPaddle::Reset() {
	prex = x;
	prey = y;
	x = originalX;
	y = originalY;
}
void cPaddle::moveUp() {
	prey = y;
	y -= 1;
}
void cPaddle::moveDown() {
	prey = y;
	y += 1;
}


