#include "MainMenu.h"
void MainMenu::Initialize(RenderWindow* window) {
	this->selected = 0;  // lựa chọn ban đầu sẽ là 0

	this->font = new Font(); // tạo font
	this->font->loadFromFile("Graphics/Nexa-Black.ttf");

	this->title = new Text("Ping Pong", *this->font, 99U); // nội dung & size của font
	this->title->setOrigin(this->title->getGlobalBounds().width / 2, this->title->getGlobalBounds().height / 2); // set origin ở giữa vật (thay vì topleft)
	this->title->setPosition(window->getSize().x / 2, window->getSize().y / 10); // set vị trí

	this->play1 = new Text("1 PLAYER", *this->font, 55U);
	this->play1->setOrigin(this->play1->getGlobalBounds().width / 2, this->play1->getGlobalBounds().height / 2);
	this->play1->setPosition(window->getSize().x / 2, window->getSize().y / 2 -16);


	this->play2 = new Text("2 PLAYERS", *this->font, 55U);
	this->play2->setOrigin(this->play2->getGlobalBounds().width / 2, this->play2->getGlobalBounds().height / 2);
	this->play2->setPosition(window->getSize().x / 2, window->getSize().y / 2 +60);

	this->quit = new Text("QUIT", *this->font, 55U);
	this->quit->setOrigin(this->quit->getGlobalBounds().width / 2, this->quit->getGlobalBounds().height / 2);
	this->quit->setPosition(window->getSize().x / 2, window->getSize().y / 2 + 136);
}
void MainMenu::Update(RenderWindow* window) {
	if ((Keyboard::isKeyPressed(Keyboard::Key::Up) || Keyboard::isKeyPressed(Keyboard::Key::W)) && !this->upKey) { // phím lên đang được nhấn, upkey = false
		this->selected -= 1;
	}
	if ((Keyboard::isKeyPressed(Keyboard::Key::Down) || Keyboard::isKeyPressed(Keyboard::Key::S)) && !this->downKey) { // phím xuống đang được nhấn, downkey = false
		this->selected += 1;
	}
	if (selected > 2) { // lựa chọn quá 2 thì quay về là 0
		this->selected = 0;
	}
	if (selected < 0) { // lựa chọn quá 0 thì quay về là 2
		this->selected = 2;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Return)) { // enter được nhấn
		switch (this->selected){
		case 0: {
			coreState.SetState(new MainGameAI()); // vào game 1 người chơi
			break;
		}
		case 1: {
			coreState.SetState(new MainGame()); // vào game 2 người chơi
			break;
		}
		case 2: {
			quitGame = true;  // thoát game
			break;
		}
		}
	}
	this->upKey = Keyboard::isKeyPressed(Keyboard::Key::Up); // cập nhật phím upkey
	this->downKey = Keyboard::isKeyPressed(Keyboard::Key::Down); // // cập nhật phím downkey
}
void MainMenu::Render(RenderWindow* window) {
	this->play1->setFillColor(Color::White); // default color là white
	this->play2->setFillColor(Color::White);
	this->quit->setFillColor(Color::White);
	switch (this->selected){ // xem mục nào đang được chọn
	case 0: {
		this->play1->setFillColor(Color::Green); // khi được chọn chuyển sang green
		break;
	}
	case 1: {
		this->play2->setFillColor(Color::Green);
		break;
	}
	case 2: {
		this->quit->setFillColor(Color::Green);
		break;
	}
	}
	// vẽ các text
	window->draw(*this->title);
	window->draw(*this->play1);
	window->draw(*this->play2);
	window->draw(*this->quit);
}
void MainMenu::Destroy(RenderWindow* window) {
	delete this->font;
	delete this->title;
	delete this->play1;
	delete this->play2;
	delete this->quit;
}