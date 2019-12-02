#ifndef _MAINGAME_H_
#define _MAINGAME_H_
#include "GameState.h"
#include "PaddlePlayer.h"
#include "Ball.h"
#include "Score.h"
class MainGame : public TinyState {
private:
	PaddlePlayer* Player1;
	PaddlePlayer* Player2;
	Ball* BallObject;
	Score* Score1;
	Score* Score2;

	Font* font;
public:
	virtual void Initialize(RenderWindow* window);
	virtual void Update(RenderWindow* window);
	virtual void Render(RenderWindow* window);
	virtual void Destroy(RenderWindow* window);
};

#endif
