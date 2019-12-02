#include "MainGame.h"
#include "MainMenu.h"

void MainGame::Initialize(RenderWindow* window) {
	this->Player1 = new PaddlePlayer(0);
	this->Player1->setPosition(0, window->getSize().y / 2 + this->Player1->getGlobalBounds().height / 4);

	this->Player2 = new PaddlePlayer(1);
	this->Player2->setPosition(window->getSize().x - this->Player2->getGlobalBounds().width, window->getSize().y/2+this->Player2->getGlobalBounds().height/4); // set up cho player 2 o ben phai

	this->BallObject = new Ball(this->Score1,this->Score2,this->Player1, this->Player2);
	this->BallObject->setPosition(window->getSize().x/2,window->getSize().y/2);


	this->font = new Font(); // setting font
	this->font->loadFromFile("Graphics/Nexa-Black.ttf");
	this->Score1 = new Score(*font,64U);
	this->Score2 = new Score(*font, 64U);

	this->Score2->setPosition(window->getSize().x - this->Score2->getGlobalBounds().width, 0);
}
void MainGame::Update(RenderWindow* window) {
	this->Player1->Update();
	this->Player2->Update();
	this->BallObject->Update(window);
	this->Score1->Update();
	this->Score2->Update();

	if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) { 
		coreState.SetState(new MainMenu());
	}
}
void MainGame::Render(RenderWindow* window) {
	window->draw(*this->Player1);
	window->draw(*this->Player2);
	window->draw(*this->BallObject);
	window->draw(*this->Score1);
	window->draw(*this->Score2);
}
void MainGame::Destroy(RenderWindow* window) {
	delete Player1;
	delete Player2;
	delete BallObject;
	delete Score1;
	delete Score2;
}