#ifndef _WATERMAPAI_H_
#define _WATERMAPAI_H_
#include "GameState.h"
#include "PaddlePlayer.h"
#include "PaddleAI.h"
#include "Ball.h"
#include "Score.h"
#include "MainMenu.h"
#include "Food.h"
class WaterMapAI : public TinyState {
private:
	PaddlePlayer* Player1;  // người chơi 1
	PaddleAI* Player2; // người chơi 2
	Ball* BallObject; // bóng
	Score* Score1; // điểm người chơi 1
	Score* Score2; // điểm người chơi 2

	int prevalue1; // lưu lại điểm người chơi 1 từ element state
	int prevalue2;  // lưu lại điểm người chơi 2 từ element state
	Food* FoodObject[4]; // vật phẩm cộng 1 điểm
	Food* Food2Object[6]; // vật phẩm cộng 2 điểm
	Food* PoisonObject[3]; // vật phẩm trừ 2 điểm

	Font* font;  // font chữ

	Texture texture; // background
	Sprite background;
public:
	WaterMapAI(int Score1, int Score2); // lấy giá trị điểm từ element state khi khởi tạo map
	virtual void Initialize(RenderWindow* window); // khởi tạo game
	virtual void Update(RenderWindow* window); // update sự kiện
	virtual void Render(RenderWindow* window); // render đồ họa
	virtual void Destroy(RenderWindow* window); // hàm hủy
};

#endif
