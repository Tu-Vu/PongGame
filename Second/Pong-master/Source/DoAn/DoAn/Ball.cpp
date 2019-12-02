#include "Ball.h"


Ball::Ball()
{
	sprite.setRadius(BALL_RADIAN);
	sprite.setPointCount(20);
	sprite.setFillColor(Color::Red);
	sprite.setPosition(Vector2f(SCREEN_X / 2, SCREEN_Y / 2));
	sprite.setOrigin(Vector2f(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2));
	int angle;
	srand((int)time(0)); //random so khac nhau moi lan chay
	do
	{
		angle = 5 + rand() % (355 + 1 - 5);  // random so tu 5 den 355
	} while ((angle > 45 && angle < 135) || (angle > 225 && angle < 315) || (angle > 175 && angle < 185));	//gioi han goc ko qua thang dung, ko qua ngang

	xVelocity = BALL_SPEED * cos(angle * 3.14 / 180);	//van toc theo x <= van toc
	yVelocity = BALL_SPEED * sin(angle * 3.14 / 180);
}

Ball::~Ball()
{
}

void Ball::setXVelocity(float x)
{
	xVelocity = x;
}

void Ball::setyVelocity(float y)
{
	yVelocity = y;
}

void Ball::intersectBorder()
{
	yVelocity = -yVelocity;
}

void Ball::intersectPaddle()
{
	if (abs(xVelocity) < paddleSize.x * 2.5)	//gioi han toc do ball
	{
		xVelocity = -xVelocity * 1.1f;
		yVelocity = yVelocity * 1.1f;
	}
	else
	{
		xVelocity = -xVelocity;
	}
}

void Ball::draw(RenderWindow& window)
{
	window.draw(sprite);
}

void Ball::move()
{
	sprite.move(Vector2f(xVelocity, yVelocity));
}

void Ball::reset()
{
	*this = Ball();
}

