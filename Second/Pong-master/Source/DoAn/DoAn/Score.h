#ifndef SCORE_H_
#define SCORE_H_


#include "Ball.h"

class Score
{
private:
	Font font;
	int intScore;
	Text sprite;
public:
	Score();
	~Score();
	void player1Score();
	void player2Score();
	void increase();
	void draw(RenderWindow& window);
	int getScore() { return intScore; };
};



#endif // !SCORE_H_

