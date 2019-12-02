#ifndef PADDLE_H_
#define PADDLE_H_
#include "Border.h"


const Vector2f paddleSize(10, 70);

class Paddle
{
private:
	RectangleShape paddle;
public:
	void leftPaddle();
	void rightPaddle();
	RectangleShape getSprite() { return paddle; };
	void draw(RenderWindow& window);
	void moveUp(Border& topBorder);
	void moveDown(Border& botBorder);
	
};

#endif // !PADDLE_H_

