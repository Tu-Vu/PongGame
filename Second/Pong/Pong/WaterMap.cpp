﻿#include "WaterMap.h"

WaterMap::WaterMap(int Score1, int Score2) {
	this->prevalue1 = Score1;
	this->prevalue2 = Score2;
}
void WaterMap::Initialize(RenderWindow* window) {
	this->Player1 = new PaddlePlayer(0); // tạo người chơi 1

	this->Player2 = new PaddlePlayer(1); // tạo người chơi 2

	this->font = new Font(); // setting font
	this->font->loadFromFile("Graphics/Nexa-Black.ttf");

	texture.loadFromFile("Graphics/Sprites/backgroundwater.png"); // load background
	background.setTexture(texture);

	this->Score1 = new Score(*font, 64U); // tạo score người chơi 1
	this->Score1->setPosition(window->getSize().x / 4, 10);

	this->Score2 = new Score(*font, 64U); // tạo score người chơi 2
	this->Score2->setPosition(window->getSize().x / 1.4, 10);

	this->BallObject = new Ball(this->Score1, this->Score2, this->Player1, this->Player2); // tạo bóng
	this->BallObject->Reset(window); // reset (set) bóng ở chính giữa màn hình, paddle 1 ở bên trái giữa màn hình, paddle 2 ở bên phải giữa




}
void WaterMap::Update(RenderWindow* window) {
	this->Player1->Update(); // update sự kiện người chơi 1
	this->Player2->Update(); // update sự kiện người chơi 2
	this->BallObject->Update(window); // update bóng
	this->Score1->Update(); // update điểm người chơi 1
	this->Score2->Update(); // update điểm người chơi 2



	if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) {  // nếu ấn thoát thì quay về menu
		coreState.SetState(new MainMenu());
	}
}
void WaterMap::Render(RenderWindow* window) { // vẽ các object có trong trò chơi
	window->draw(this->background);
	window->draw(*this->BallObject);
	window->draw(*this->Player1);
	window->draw(*this->Player2);
	window->draw(*this->Score1);
	window->draw(*this->Score2);

}
void WaterMap::Destroy(RenderWindow* window) {
	delete this->Player1;
	delete this->Player2;
	delete this->BallObject;
	delete this->Score1;
	delete this->Score2;
	delete this->font;

}