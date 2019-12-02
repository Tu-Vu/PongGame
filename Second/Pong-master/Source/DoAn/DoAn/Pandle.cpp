#include "Pandle.h"

void Paddle::leftPaddle()
//tạo thanh trượt cho người choi bên trái
{
	paddle.setSize(paddleSize);// thiết lập kích thước cho thanh trượt
	paddle.setFillColor(Color::White);//thiết lập màu 
	paddle.setPosition(paddleSize.x + 10, SCREEN_Y / 2);//thiết lập vị trí xuất ra cửa sổ
	paddle.setOrigin(Vector2f(paddle.getGlobalBounds().width / 2, paddle.getGlobalBounds().height / 2));
}

void Paddle::rightPaddle()
//tạo thnah trượt cho người chơi bên phải
{
	paddle.setSize(paddleSize);// thiết lập kích thước cho thanh trượt
	paddle.setFillColor(Color::White);//thiết lập màu 
	paddle.setPosition(SCREEN_X - (paddleSize.x + 10), SCREEN_Y / 2);//thiết lập vị trí xuất ra cửa sổ
	paddle.setOrigin(Vector2f(paddle.getGlobalBounds().width / 2, paddle.getGlobalBounds().height / 2));
}

void Paddle::draw(RenderWindow& window)
{
	window.draw(paddle);
}

void Paddle::moveUp(Border& topBorder)
{
	if (!paddle.getGlobalBounds().intersects(topBorder.getSprite().getGlobalBounds()))  //thanh truot ko cham topBorder
	{
		paddle.move(Vector2f(0, -paddleSize.x / 2));
	}
}

void Paddle::moveDown(Border& botBorder)
{
	if (!paddle.getGlobalBounds().intersects(botBorder.getSprite().getGlobalBounds()))  //thanh truot ko cham botBorder
	{
		paddle.move(Vector2f(0, paddleSize.x / 2));
	}
}



