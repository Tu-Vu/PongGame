﻿#include "WindMapAI.h"

WindMapAI::WindMapAI(int Score1, int Score2) {
	this->prevalue1 = Score1; // lưu lại điểm người chơi từ element state
	this->prevalue2 = Score2;
}
void WindMapAI::Initialize(RenderWindow* window) {
	this->font = new Font(); // setting font
	this->font->loadFromFile("Graphics/Nexa-Black.ttf");

	texture.loadFromFile("Graphics/Sprites/backgroundwind.png"); // load background
	background.setTexture(texture);

	this->Player1 = new PaddlePlayer(0); // tạo người chơi 1

	this->Player2 = new PaddleAI(1); // tạo người chơi 2

	this->Portal1 = new PaddleAI(3);

	this->Portal2 = new PaddleAI(3);

	this->Portal3 = new PaddleAI(3);

	this->Portal4 = new PaddleAI(3);

	this->Score1 = new Score(*font, 64U); // tạo score người chơi 1
	this->Score1->setPosition(window->getSize().x / 4, 10);
	this->Score1->value = this->prevalue1;

	this->Score2 = new Score(*font, 64U); // tạo score người chơi 2
	this->Score2->setPosition(window->getSize().x / 1.4, 10);
	this->Score2->value = this->prevalue2;

	this->BallObject = new Ball(this->Score1, this->Score2, this->Player1, this->Player2, this->Portal1, this->Portal2, this->Portal3, this->Portal4); // tạo bóng
	this->BallObject->WindReset(window); // reset (set) bóng ở chính giữa màn hình, paddle 1 ở bên trái giữa màn hình, paddle 2 ở bên phải giữa, các portal ở vị trí ban đầu
	this->Player2->SetBall(this->BallObject);

	for (int i = 0; i < 9; i++) { // tạo ngẫu nhiên các vật phẩm cộng điểm
		this->FoodObject[i] = new Food(this->Score1, this->Score2, this->BallObject);
		this->FoodObject[i]->WindReset(window);
	}
}
void WindMapAI::Update(RenderWindow* window) {
	this->Player1->Update(); // update sự kiện người chơi 1
	this->Player2->Update(); // update sự kiện người chơi 2
	this->BallObject->WindUpdate(window); // update bóng
	this->Score1->Update(); // update điểm người chơi 1
	this->Score2->Update(); // update điểm người chơi 2
	for (int i = 0; i < 9; i++) { // update vật phẩm cộng điểm
		if (this->FoodObject[i]->eaten == false) {
			this->FoodObject[i]->Update();
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) {// nếu ấn thoát thì quay về menu
		this->SaveGame();
		coreState.SetState(new InGameMenu(Score1->value, Score2->value));
	}
}
void WindMapAI::Render(RenderWindow* window) { // vẽ các object có trong trò chơi
	window->draw(this->background);
	window->draw(*this->BallObject);
	window->draw(*this->Player1);
	window->draw(*this->Player2);
	window->draw(*this->Portal1);
	window->draw(*this->Portal2);
	window->draw(*this->Portal3);
	window->draw(*this->Portal4);
	for (int i = 0; i < 9; i++) {
		if (this->FoodObject[i]->eaten == false) {
			window->draw(*this->FoodObject[i]);
		}
	}
	window->draw(*this->Score1);
	window->draw(*this->Score2);
}
void WindMapAI::Destroy(RenderWindow* window) {
	delete this->Player1;
	delete this->Player2;
	delete this->BallObject;
	delete this->Score1;
	delete this->Score2;
	delete this->Portal1;
	delete this->Portal2;
	delete this->Portal3;
	delete this->Portal4;
	for (int i = 0; i < 9; i++) {
		delete this->FoodObject[i];
	}
}

void WindMapAI::SaveGame()
{
	ofstream writeFile;
	writeFile.open("Data/SaveGame.txt");
	if (writeFile.is_open())
	{
		writeFile << "2Player" << endl;
		writeFile << 4 << endl;
		writeFile << Score1->value << endl;
		writeFile << Score2->value << endl;
	}
	writeFile.close();
}
