#pragma once
#include "GameState.h"
#include "MainGame.h"
#include "MainGameAI.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class EndGame : public TinyState
{
private:
	Font* font;
	Text* title;
	Text* score1;
	Text* score2;
	Text* score3;
	Text* score4;
	Text* score5;
	Text* quit;
	Text* menu;
	Text* win;
	int selected;

	bool upKey;
	bool downKey;
public:
	int _score1;//Diem cua player 1
	int _score2;//Diem cua player 2
	int score;
	vector<int> listscore;

	EndGame(int _score1, int _score2);
	void SortScore();

	virtual void Initialize(RenderWindow* window); // khởi tạo menu
	virtual void Update(RenderWindow* window); // update các phím nhấn người dùng
	virtual void Render(RenderWindow* window); // render hình ảnh
	virtual void Destroy(RenderWindow* window); // hàm hủy
};

