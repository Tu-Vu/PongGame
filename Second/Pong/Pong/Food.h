#ifndef _FOOD_H_
#define _FOOD_H_
#include <SFML/Audio.hpp>
#include "Ball.h"
#include "Score.h"
#include <vector>
using namespace std;
class Food :public Entity{
private:
	Score* Score1; // điểm người chơi 1 
	Score* Score2; // điểm người chơi 2
	Ball* BallObject; // bóng
	SoundBuffer* buffer; // buffer cho âm thanh
	Sound* sound; // âm thanh
	int type;
public:
	bool eaten; // cho biết food đã bị ăn chưa
	bool reborn; // dùng cho water map
	Food(Score* Score1, Score* Score2, Ball* BallObject); // khởi tạo food
	Food(Score* Score1, Score* Score2, Ball* BallObject, int type); 
	~Food();
	virtual void Update(); // update sự kiện
	void PoisonUpdate();
	void Food2Update();
	void RockReset(RenderWindow* window);
	void WindReset(RenderWindow* window);
	void WaterReset(RenderWindow* window);
};
#endif

