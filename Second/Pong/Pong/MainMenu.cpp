#include "MainMenu.h"
#include "MainGame.h"


void MainMenu::Initialize(RenderWindow* window) {
	this->selected = 0;

	this->font = new Font(); // setting font
	this->font->loadFromFile("Graphics/Nexa-Black.ttf");

	this->title = new Text("Ping Pong", *this->font, 99U); //size cua font
	this->title->setOrigin(this->title->getGlobalBounds().width / 2, this->title->getGlobalBounds().height / 2);
	this->title->setPosition(window->getSize().x / 2, window->getSize().y / 10); // dieu chinh position cua title

	this->subtitle = new Text("VNU-HCMUS", *this->font, 23U);
	this->subtitle->setOrigin(this->title->getGlobalBounds().width / 2, this->title->getGlobalBounds().height / 2);
	this->subtitle->setPosition(window->getSize().x / 2 + 5, window->getSize().y / 4 + 20);

	this->mssv = new Text("18120254              18120254", *this->font, 13U);
	this->mssv->setOrigin(this->title->getGlobalBounds().width / 2, this->title->getGlobalBounds().height / 2);
	this->mssv->setPosition(window->getSize().x / 2 + 250, window->getSize().y / 4 + 20);

	this->play = new Text("PLAY", *this->font, 55U);
	this->play->setOrigin(this->title->getGlobalBounds().width / 2, this->title->getGlobalBounds().height / 2);
	this->play->setPosition(window->getSize().x / 2 + 169, window->getSize().y / 2);

	this->quit = new Text("QUIT", *this->font, 55U);
	this->quit->setOrigin(this->title->getGlobalBounds().width / 2, this->title->getGlobalBounds().height / 2);
	this->quit->setPosition(window->getSize().x / 2 + 169, window->getSize().y / 1.5);
}
void MainMenu::Update(RenderWindow* window) {
	if (Keyboard::isKeyPressed(Keyboard::Key::Up) && !this->upKey) { // upkey dang dc an
		this->selected -= 1;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Down) && !this->downKey) { // downkey dang dc an
		this->selected += 1;
	}
	if (selected > 1) {
		this->selected = 0;
	}
	if (selected < 0) {
		this->selected = 1;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Return)) { // enter dc an
		switch (this->selected)
		{
		case 0: {
			coreState.SetState(new MainGame()); // quay lai man hinh chinh
			break;
		}
		case 1: {
			quitGame = true;
			break;
		}
		}
	}
	this->upKey = Keyboard::isKeyPressed(Keyboard::Key::Up);
	this->downKey = Keyboard::isKeyPressed(Keyboard::Key::Down);
}
void MainMenu::Render(RenderWindow* window) {
	this->play->setFillColor(Color::White); // default color la white, khi dc selected chuyen sang red;
	this->quit->setFillColor(Color::White);
	switch (this->selected)
	{
	case 0: {
		this->play->setFillColor(Color::Green);
		break;
	}
	case 1: {
		this->quit->setFillColor(Color::Green);
		break;
	}
	}
	window->draw(*this->title);
	window->draw(*this->subtitle);
	window->draw(*this->mssv);
	window->draw(*this->play);
	window->draw(*this->quit);
}
void MainMenu::Destroy(RenderWindow* window) {
	delete this->font;
	delete this->title;
	delete this->subtitle;
	delete this->mssv;
	delete this->play;
	delete this->quit;
}