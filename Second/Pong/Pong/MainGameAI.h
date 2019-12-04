#ifndef _MAINGAMEAI_H_
#define _MAINGAMEAI_H_
#include "GameState.h"
#include "PaddlePlayer.h"
#include "PaddleAI.h"
#include "Ball.h"
#include "Score.h"
#include "MainMenu.h"
class MainGameAI : public TinyState {
private:
	PaddlePlayer* Player1;  // người chơi 1
	PaddleAI* Player2; // người chơi 2 (là máy)
	Ball* BallObject; // bóng
	Score* Score1; // điểm người chơi 1
	Score* Score2; // điểm người chơi 2

	Font* font;  // font chữ

	Texture texture; // background
	Sprite background;
public:
	virtual void Initialize(RenderWindow* window); // khởi tạo game
	virtual void Update(RenderWindow* window); // update sự kiện
	virtual void Render(RenderWindow* window); // render đồ họa
	virtual void Destroy(RenderWindow* window); // hàm hủy
};

#endif
