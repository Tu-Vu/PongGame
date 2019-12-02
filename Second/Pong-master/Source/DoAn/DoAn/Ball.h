#ifndef BALL_H_
#define BALL_H_

#define BALL_RADIAN 10
#define BALL_SPEED 4  //toc do ban dau
#include "Pandle.h"
#include <cmath>



class Ball
{
private:
	CircleShape sprite;
	float xVelocity; //van toc theo x
	float yVelocity;
public:
	Ball();
	~Ball();
	void setXVelocity(float x);
	void setyVelocity(float y);
	float getXVelocity() { return xVelocity; };
	float getYVelocity() { return yVelocity; };
	CircleShape getSprite() { return sprite; };
	void intersectBorder();
	void intersectPaddle();
	void draw(RenderWindow& window);
	void move();
	void reset();




};


#endif // !BALL_H_


