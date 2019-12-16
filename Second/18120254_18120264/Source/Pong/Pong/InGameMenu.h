#pragma once
#include "GameState.h"
#include "MainGame.h"
#include "MainGameAI.h"
#include <iostream>
#include "EndGame.h"
#include "SaveGame.h"
using namespace std;
class InGameMenu : public TinyState
{
private:
	Font* font; // chọn font
	Text* savegame;// text save game
	Text* endgame; // text end game
	Text* quit; // text thoát

	int selected; // lựa chọn của người chơi, =0 là save game, =1 là endgame, =2 là quit

	bool upKey; // check người chơi nhấn nút lên
	bool downKey; // check người chơi nhấn nút xuống
	bool upKey1;
	bool downKey1;

public:
	int _score1;
	int _score2;
	InGameMenu(int _score1, int _score2);

	virtual void Initialize(RenderWindow* window); // khởi tạo menu
	virtual void Update(RenderWindow* window); // update các phím nhấn người dùng
	virtual void Render(RenderWindow* window); // render hình ảnh
	virtual void Destroy(RenderWindow* window); // hàm hủy
};

