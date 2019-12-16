#include "InGameMenu.h"



InGameMenu::InGameMenu(int _score1, int _score2)
{
	this->_score1 = _score1;
	this->_score2 = _score2;
}

void InGameMenu::Initialize(RenderWindow* window)
{
	this->selected = 0;  // lựa chọn ban đầu sẽ là 0

	this->font = new Font(); // tạo font
	this->font->loadFromFile("Graphics/Nexa-Black.ttf");

	this->savegame = new Text("SAVE GAME", *this->font, 55U);
	this->savegame->setOrigin(this->savegame->getGlobalBounds().width / 2, this->savegame->getGlobalBounds().height / 2);
	this->savegame->setPosition(window->getSize().x / 2, window->getSize().y / 2 - 16);

	this->endgame = new Text("END GAME", *this->font, 55U);
	this->endgame->setOrigin(this->endgame->getGlobalBounds().width / 2, this->endgame->getGlobalBounds().height / 2);
	this->endgame->setPosition(window->getSize().x / 2, window->getSize().y / 2 + 60);

	this->quit = new Text("QUIT", *this->font, 55U);
	this->quit->setOrigin(this->quit->getGlobalBounds().width / 2, this->quit->getGlobalBounds().height / 2);
	this->quit->setPosition(window->getSize().x / 2, window->getSize().y / 2 + 136);
}

void InGameMenu::Update(RenderWindow* window)
{
	if ((Keyboard::isKeyPressed(Keyboard::Key::Up) || Keyboard::isKeyPressed(Keyboard::Key::W)) && !this->upKey && !this->upKey1) // phím lên đang được nhấn, upkey = false
		this->selected -= 1;
	if ((Keyboard::isKeyPressed(Keyboard::Key::Down) || Keyboard::isKeyPressed(Keyboard::Key::S)) && !this->downKey && !this->downKey1) // phím xuống đang được nhấn, downkey = false
		this->selected += 1;
	if (selected > 2) // lựa chọn quá 2 thì quay về là 0
		this->selected = 0;
	if (selected < 0) // lựa chọn quá 0 thì quay về là 2
		this->selected = 2;

	if (Keyboard::isKeyPressed(Keyboard::Key::Return)) { // enter được nhấn
		switch (this->selected) {
		case 0: {
			coreState.SetState(new SaveGame());
			break;
		}
		case 1: {
			coreState.SetState(new EndGame(_score1, _score2));
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
	this->upKey1 = Keyboard::isKeyPressed(Keyboard::Key::W); // cập nhật phím upkey1
	this->downKey1 = Keyboard::isKeyPressed(Keyboard::Key::S); // // cập nhật phím downkey1
}

void InGameMenu::Render(RenderWindow* window)
{
	this->savegame->setFillColor(Color::White); // default color là white
	this->endgame->setFillColor(Color::White);
	this->quit->setFillColor(Color::White);
	switch (this->selected)
	{ // xem mục nào đang được chọn
	case 0:
	{
		this->savegame->setFillColor(Color::Green); // khi được chọn chuyển sang green
		break;
	}
	case 1:
	{
		this->endgame->setFillColor(Color::Green);
		break;
	}
	case 2:
	{
		this->quit->setFillColor(Color::Green);
		break;
	}
	}
	// vẽ các text
	window->draw(*this->savegame);
	window->draw(*this->endgame);
	window->draw(*this->quit);
}

void InGameMenu::Destroy(RenderWindow* window)
{
	delete this->font;
	delete this->savegame;
	delete this->endgame;
	delete this->quit;
}
