#include "cBall.h"
cBall::cBall(int posX, int posY)//Constructor{
	originalX = posX;
	originalY = posY;
	x = posX; y = posY;
	direction = STOP;
	velocity = 1;
}
void cBall::Reset(){
	x = originalX; y = originalY;//x, y được gán bằng giá trị ban đầu
	direction = STOP;//Ball không di chuyển
}
void cBall::changeDirection(eDir d){
	direction = d;
}
void cBall::randomDirection(){
	direction = (eDir)((rand() % 6) + 1);
}
int cBall::getX(){
	return x;
}
int cBall::getY(){
	return y;
}
int cBall::getPreX(){
	return prex;
}
int cBall::getPreY(){
	return prey;
}
eDir cBall::getDirection(){
	return direction;
}
void cBall::Move(){
	prex = x;
	prey = y;
	switch (direction){
	case STOP:
		break;
	case LEFT:
		x-=velocity;
		break;
	case RIGHT:
		x+=velocity;
		break;
	case UPLEFT:
		x-=velocity; y-=velocity;
		break;
	case DOWNLEFT:
		x-=velocity; y+=velocity;
		break;
	case UPRIGHT:
		x+=velocity; y-=velocity;
		break;
	case DOWNRIGHT:
		x+=velocity; y+=velocity;
		break;
	default:
		break;
	}
}