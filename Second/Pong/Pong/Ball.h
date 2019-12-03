#ifndef _BALL_H_
#define _BALL_H_
#include <SFML/Audio.hpp>
#include "PaddlePlayer.h"
#include "Score.h"
class Ball:public Entity
{
private:
	Score* Score1; // điểm người chơi 1 
	Score* Score2; // điểm người chơi 2
	Paddle* player1; // người chơi 1 
	Paddle* player2; // người chơi 2 
	SoundBuffer* buffer; // buffer cho âm thanh
	Sound* sound; // âm thanh
public:
	Ball(Score* Score1, Score* Score2,Paddle* player1, Paddle* player2); // khởi tạo bóng
	~Ball();
	virtual void Update(RenderWindow* window); // update sự kiện
	void Reset(RenderWindow* window); 
};
#endif

