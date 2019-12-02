#ifndef  BORDER_H_
#define BORDER_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>

#define SCREEN_X 700
#define SCREEN_Y 450
using namespace sf;

class Border
{
private:
	RectangleShape sprite;
public:
	void topBorder();
	void botBorder();
	RectangleShape getSprite() { return sprite; };
	void draw(RenderWindow& window);
};


#endif // ! BORDER_H_



