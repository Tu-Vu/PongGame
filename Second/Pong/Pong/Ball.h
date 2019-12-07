#ifndef _BALL_H_
#define _BALL_H_
#include <SFML/Audio.hpp>
#include "PaddlePlayer.h"
#include "Score.h"
class Ball:public Entity{
private:
	Score* Score1; // điểm người chơi 1 
	Score* Score2; // điểm người chơi 2
	Paddle* player1; // người chơi 1 
	Paddle* player2; // người chơi 2 

	Paddle* rock1; // vật cản dùng cho rockmap
	Paddle* rock2; // vật cản dùng cho rockmap
	Paddle* rock3; // vật cản dùng cho rockmap


	Paddle* portal1; // portal dùng cho windmap
	Paddle* portal2; // portal dùng cho windmap
	Paddle* portal3; // portal dùng cho windmap
	Paddle* portal4; // portal dùng cho windmap

	SoundBuffer* buffer; // buffer cho âm thanh
	Sound* sound; // âm thanh
public:
	int owning; // cho biết bóng đang được sở hữu bởi paddle nào (1 = người chơi 1, 2 = người chơi 2)
	Ball(Score* Score1, Score* Score2,Paddle* player1, Paddle* player2); // khởi tạo bóng
	Ball(Score* Score1, Score* Score2, Paddle* player1, Paddle* player2, Paddle* rock1, Paddle* rock2, Paddle* rock3); // khởi tạo bóng cho rock map
	Ball(Score* Score1, Score* Score2, Paddle* player1, Paddle* player2, Paddle* portal1, Paddle* portal2, Paddle* portal3, Paddle* portal4); // khởi tạo bóng cho wind map
	~Ball();
	virtual void Update(RenderWindow* window); // update sự kiện
	void RockUpdate(RenderWindow* window); // update sự kiện cho map rock
	void WindUpdate(RenderWindow* window); // update sự kiện cho map wind
	void Reset(RenderWindow* window);  // reset (set) lại bóng, paddle
	void RockReset(RenderWindow* window); // reset (set) lại bóng, paddle, vật cản
	void WindReset(RenderWindow* window); // reset (set) lại bóng, paddle, portal
};
#endif

