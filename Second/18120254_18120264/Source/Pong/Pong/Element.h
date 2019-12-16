#ifndef _ELEMENT_H_
#define _ELEMENT_H_
#include <SFML/Audio.hpp>
#include "Ball.h"
#include "Score.h"
class Element :public Entity {
private:
	Score* Score1; // điểm người chơi 1 
	Score* Score2; // điểm người chơi 2
	Ball* BallObject; // bóng
	SoundBuffer* buffer; // buffer cho âm thanh
	Sound* sound; // âm thanh
	int type; // loại nguyên tố (1= lửa, 2= nước, 3= đất, 4= gió)
public:
	Element(Score* Score1, Score* Score2,Ball* BallObject,int type); // khởi tạo element theo loại
	~Element(); // hàm hủy
	virtual void Update(); // update sự kiện
	void UpdateAI(); // update sự kiện
};
#endif

