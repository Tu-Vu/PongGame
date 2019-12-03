#ifndef _PADDLEAI_H_
#define _PADDLEAI_H_
#include "Paddle.h"
#include "GameState.h" // để lấy Windows_Height và Windows_Weight 
#include "Ball.h"

class PaddleAI : public Paddle {
private:
	Ball* BallObject; // track xem ball đang ở đâu
	int playerNumber; // 1 = người chơi 1, else = người chơi 2
public:
	PaddleAI(int playerNumber); // tạo người chơi theo playerNumber
	void SetBall(Ball* BallObject);  // set ball cho máy
	virtual void Update(); // update sự kiện
};
#endif

