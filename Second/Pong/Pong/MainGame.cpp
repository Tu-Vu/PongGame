#include "MainGame.h"

void MainGame::Initialize(RenderWindow* window) {
	this->font = new Font(); // setting font
	this->font->loadFromFile("Graphics/Nexa-Black.ttf");

	texture.loadFromFile("Graphics/Sprites/background.png"); // load background
	background.setTexture(texture);

	this->Score1 = new Score(*font, 64U); // tạo score người chơi 1
	this->Score1->setPosition(window->getSize().x / 4, 10);

	this->Score2 = new Score(*font, 64U); // tạo score người chơi 2
	this->Score2->setPosition(window->getSize().x / 1.4, 10);

	this->Player1 = new PaddlePlayer(0); // tạo người chơi 1

	this->Player2 = new PaddlePlayer(1); // tạo người chơi 2

	this->BallObject = new Ball(this->Score1, this->Score2, this->Player1, this->Player2); // tạo bóng
	this->BallObject->Reset(window); // reset (set) bóng ở chính giữa màn hình, paddle 1 ở bên trái giữa màn hình, paddle 2 ở bên phải giữa

	for (int i = 0; i < 6; i++) {
		int type;
		type = 1 + rand() % (4 + 1 - 1);  // random só từ 1 đến 4
		this->ElementObject[i] = new Element(this->Score1,this->Score2,this->BallObject, type);
		if (i == 0)
			this->ElementObject[i]->setPosition(window->getSize().x / 2 + 100, window->getSize().y / 2 + 200);
		else if (i == 1)
			this->ElementObject[i]->setPosition(window->getSize().x / 2, window->getSize().y / 2 + 200);
		else if (i == 2)
			this->ElementObject[i]->setPosition(window->getSize().x / 2 - 100, window->getSize().y / 2 + 200);
		else if (i == 3)
			this->ElementObject[i]->setPosition(window->getSize().x / 2, window->getSize().y / 2 - 200);
		else if (i == 4)
			this->ElementObject[i]->setPosition(window->getSize().x / 2 - 100, window->getSize().y / 2 - 200);
		else if (i == 5)
			this->ElementObject[i]->setPosition(window->getSize().x / 2 + 100, window->getSize().y / 2 - 200);
	}
}
void MainGame::Update(RenderWindow* window) {
	this->Player1->Update(); // update sự kiện người chơi 1
	this->Player2->Update(); // update sự kiện người chơi 2
	this->BallObject->Update(window); // update bóng
	this->Score1->Update(); // update điểm người chơi 1
	this->Score2->Update(); // update điểm người chơi 2

	for (int i = 0; i < 6; i++) {
		this->ElementObject[i]->Update();
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) {  // nếu ấn thoát thì quay về menu
		coreState.SetState(new MainMenu());
	}
}
void MainGame::Render(RenderWindow* window) { // vẽ các object có trong trò chơi
	window->draw(this->background);
	window->draw(*this->BallObject);
	window->draw(*this->Player1);
	window->draw(*this->Player2);
	window->draw(*this->Score1);
	window->draw(*this->Score2);
	for (int i = 0; i < 6; i++) {
		window->draw(*this->ElementObject[i]);
	}
}
void MainGame::Destroy(RenderWindow* window) {
	delete this->Player1;
	delete this->Player2;
	delete this->BallObject;
	delete this->Score1;
	delete this->Score2;
}