#ifndef _MAINMENU_H_
#define _MAINMENU_H_
#include "GameState.h"
#include <iostream>
using namespace std;
class MainMenu: public TinyState{
private:
	Font* font;
	Text* title;
	Text* subtitle;
	Text* mssv;
	Text* play;
	Text* quit;

	int selected;

	bool upKey; 
	bool downKey;
public:
	virtual void Initialize(RenderWindow* window);
	virtual void Update(RenderWindow* window);
	virtual void Render(RenderWindow* window);
	virtual void Destroy(RenderWindow* window);
};
#endif
