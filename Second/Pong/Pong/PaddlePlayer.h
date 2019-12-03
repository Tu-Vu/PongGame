#ifndef _PADDLEPLAYER_H_
#define _PADDLEPLAYER_H_
#include "Entity.h"
#include "GameState.h" // để lấy Windows_Height và Windows_Weight 

class PaddlePlayer: public Entity{
private:
	int playerNumber; // 1 = người chơi 1, else = người chơi 2
public:
	PaddlePlayer(int playerNumber); // tạo người chơi theo playerNumber
	virtual void Update(); // update sự kiện
};
#endif

