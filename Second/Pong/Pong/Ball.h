#ifndef _BALL_H_
#define _BALL_H_
#include "PaddlePlayer.h"
#include "Score.h"
class Ball:public Entity
{
private:
	Score* Score1;
	Score* Score2;
	PaddlePlayer* player1;
	PaddlePlayer* player2;
public:
	Ball(Score* Score1, Score* Score2,PaddlePlayer* player1, PaddlePlayer* player2);
	virtual void Update(RenderWindow* window);
};
#endif

