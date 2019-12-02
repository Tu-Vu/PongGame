#include "Score.h"



Score::Score()
{
	if (!font.loadFromFile("DigitalDismay.otf"))
	{
		std::cout << "Font file not found!";
		exit(-1);
	}
	
	intScore = 0;
	sprite.setFont(font);
	sprite.setString(std::to_string(intScore));
	sprite.setCharacterSize(50);
	sprite.setFillColor(Color::White);
	sprite.setOrigin(Vector2f(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2));
	
}

Score::~Score()
{
}

void Score::player1Score()
{
	sprite.setPosition(Vector2f(SCREEN_X / 4, 40));
}

void Score::player2Score()
{
	sprite.setPosition(Vector2f(3 * SCREEN_X / 4, 40));
}

void Score::increase()
{
	intScore++;
	sprite.setString(std::to_string(intScore));
}

void Score::draw(RenderWindow& window)
{
	window.draw(sprite);
}



