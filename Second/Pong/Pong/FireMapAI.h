#ifndef _FIREMAPAI_H_
#define _FIREMAPAI_H_
#include "GameState.h"
#include "PaddlePlayer.h"
#include "PaddleAI.h"
#include "Ball.h"
#include "Score.h"
#include "MainMenu.h"
#include "Food.h"
class FireMapAI : public TinyState {
private:
	PaddlePlayer* Player1;  // người chơi 1
	PaddleAI* Player2; // người chơi 2 (là máy)
	Ball* BallObject; // bóng
	Score* Score1; // điểm người chơi 1
	Score* Score2; // điểm người chơi 2

	int prevalue1; // lưu lại điểm người chơi 1 từ element state
	int prevalue2;  // lưu lại điểm người chơi 2 từ element state
	PaddleAI* FireGate;
	PaddleAI* Fire[3];  // vật cản

	Font* font;  // font chữ

	Texture texture; // background
	Sprite background;
public:
	FireMapAI(int Score1, int Score2); // lấy giá trị điểm từ element state khi khởi tạo map
	virtual void Initialize(RenderWindow* window); // khởi tạo game
	virtual void Update(RenderWindow* window); // update sự kiện
	virtual void Render(RenderWindow* window); // render đồ họa
	virtual void Destroy(RenderWindow* window); // hàm hủy
};

#endif
