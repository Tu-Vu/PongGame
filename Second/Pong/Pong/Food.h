#ifndef _FOOD_H_
#define _FOOD_H_
#include <SFML/Audio.hpp>
#include "Ball.h"
#include "Score.h"
class Food :public Entity{
private:
	Score* Score1; // điểm người chơi 1 
	Score* Score2; // điểm người chơi 2
	Ball* BallObject;
	SoundBuffer* buffer; // buffer cho âm thanh
	Sound* sound; // âm thanh

public:
	bool eaten;
	Food(Score* Score1, Score* Score2, Ball* BallObject);
	~Food();
	virtual void Update(); // update sự kiện
	void Reset(RenderWindow* window);
};
#endif

