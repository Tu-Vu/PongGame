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
	int type;  // cho biết loại food này là loại gì
public:
	bool eaten; // cho biết food đã bị ăn chưa
	Food(Score* Score1, Score* Score2, Ball* BallObject); // khởi tạo food
	Food(Score* Score1, Score* Score2, Ball* BallObject, int type);  // khởi tạo food theo loại
	~Food(); // hàm hủy
	virtual void Update(); // update sự kiện
	void PoisonUpdate(); // update sự kiện cho poison
	void Food2Update(); // update sự kiện cho food2
	void RockReset(RenderWindow* window); // reset lại cho map rock
	void WindReset(RenderWindow* window); // reset lại cho map wind
	void WaterReset(RenderWindow* window); // reset lại cho map water
};
#endif

