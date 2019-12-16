#ifndef _MAINMENU_H_
#define _MAINMENU_H_
#include "GameState.h"
#include "MainGame.h"
#include "MainGameAI.h"
#include <iostream>
using namespace std;
class MainMenu: public TinyState{
private:
	Font* font; // chọn font
	Text* play1; // text chế độ 1 người chơi
	Text* play2; // text chế độ 2 người chơi
	Text* quit; // text thoát

	int selected; // lựa chọn của người chơi, =0 là 1 player, =1 là 2 playes, =2 là quit

	bool upKey; // check người chơi nhấn nút lên
	bool downKey; // check người chơi nhấn nút xuống

	Texture texture; // background
	Sprite background;
public:
	virtual void Initialize(RenderWindow* window); // khởi tạo menu
	virtual void Update(RenderWindow* window); // update các phím nhấn người dùng
	virtual void Render(RenderWindow* window); // render hình ảnh
	virtual void Destroy(RenderWindow* window); // hàm hủy
};
#endif
