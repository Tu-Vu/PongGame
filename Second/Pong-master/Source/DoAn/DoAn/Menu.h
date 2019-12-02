#ifndef MENU_H_

#include "Border.h"
#include<SFML/Graphics.hpp>
#include <SFML/Audio.hpp>




using namespace std;
using namespace sf;



class Menu
{
public:
	Text* menu;
	Font font;
	int sl;

public:
	Menu();
	~Menu();
	void startMenu();
	void resultMenu(int& winner);
	void draw(RenderWindow& window);
};

#endif // !MENU_H_

