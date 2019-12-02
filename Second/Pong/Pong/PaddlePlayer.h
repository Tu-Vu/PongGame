#ifndef _PADDLEPLAYER_H_
#define _PADDLEPLAYER_H_
#include "Entity.h"
#define Windows_Height 600
#define Windows_Weight 800
class PaddlePlayer: public Entity
{
private:
	int playerNumber;
public:
	PaddlePlayer(int playerNumber);
	virtual void Update();
};
#endif

