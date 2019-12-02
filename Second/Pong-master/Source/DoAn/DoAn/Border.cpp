#include "Border.h"

void Border::topBorder()
//tạo lề trên
{
	sprite.setSize(Vector2f(SCREEN_X, 15));//thiết lập kích thước cho lề trên	//(chieu dai, chieu rong)
	sprite.setPosition(0, 10);//thiết lập vị trí
	
}

void Border::botBorder()
//tạo lề dưới
{
	sprite.setSize(Vector2f(SCREEN_X, 15));//thiết lập kích thước cho lề dưới
	sprite.setPosition(0, SCREEN_Y - 15 - 10);//thiết lập vị trí
	
}

void Border::draw(RenderWindow& window)
{
	window.draw(sprite);
}

