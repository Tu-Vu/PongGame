#ifndef _ROCKMAP_H_
#define _ROCKMAP_H_
#include "GameState.h"
#include "PaddlePlayer.h"
#include "Ball.h"
#include "Score.h"
#include "MainMenu.h"
#include "Food.h"
#include "InGameMenu.h"
class RockMap : public TinyState {
private:
	PaddlePlayer* Player1;  // người chơi 1
	PaddlePlayer* Player2; // người chơi 2
	Ball* BallObject; // bóng
	Score* Score1; // điểm người chơi 1
	Score* Score2; // điểm người chơi 2
	
	int prevalue1; // lưu lại điểm người chơi 1 từ element state
	int prevalue2;  // lưu lại điểm người chơi 2 từ element state
	PaddleAI* Rock1;  // vật cản
	PaddleAI* Rock2;  // vật cản
	PaddleAI* Rock3;  // vật cản
	Food* FoodObject[8]; // vật phẩm cộng điểm
	Font* font;  // font chữ

	Texture texture; // background
	Sprite background;
public:
	RockMap(int Score1, int Score2); // lấy giá trị điểm từ element state khi khởi tạo map
	virtual void Initialize(RenderWindow* window); // khởi tạo game
	virtual void Update(RenderWindow* window); // update sự kiện
	virtual void Render(RenderWindow* window); // render đồ họa
	virtual void Destroy(RenderWindow* window); // hàm hủy

	void SaveGame(); // hàm lưu game
};

#endif
