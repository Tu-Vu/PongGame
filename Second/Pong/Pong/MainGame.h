#ifndef _MAINGAME_H_
#define _MAINGAME_H_
#include "GameState.h"
#include "PaddlePlayer.h"
#include "Ball.h"
#include "Score.h"
#include "MainMenu.h"
#include "Element.h"
class MainGame : public TinyState {
private:
	PaddlePlayer* Player1;  // người chơi 1
	PaddlePlayer* Player2; // người chơi 2
	Ball* BallObject; // bóng
	Score* Score1; // điểm người chơi 1
	Score* Score2; // điểm người chơi 2

	Element* ElementObject[5];

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
