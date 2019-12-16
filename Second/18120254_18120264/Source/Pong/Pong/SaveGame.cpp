#include "SaveGame.h"

void SaveGame::Initialize(RenderWindow* window) 
{
	this->selected = 0;  // lựa chọn ban đầu sẽ là 0

	this->font = new Font(); // tạo font
	this->font->loadFromFile("Graphics/Nexa-Black.ttf");

	this->texture.loadFromFile("Graphics/Sprites/menu.png"); // load background
	this->background.setTexture(texture);

	this->next = new Text("CONTINUE", *this->font, 55U);
	this->next->setOrigin(this->next->getGlobalBounds().width / 2, this->next->getGlobalBounds().height / 2);
	this->next->setPosition(window->getSize().x / 2, window->getSize().y / 2 - 42);

	this->play1 = new Text("1 PLAYER", *this->font, 55U);  // nội dung & size của font
	this->play1->setOrigin(this->play1->getGlobalBounds().width / 2, this->play1->getGlobalBounds().height / 2); // set origin ở giữa vật (thay vì topleft)
	this->play1->setPosition(window->getSize().x / 2, window->getSize().y / 2 + 34); // set vị trí

	this->play2 = new Text("2 PLAYERS", *this->font, 55U);
	this->play2->setOrigin(this->play2->getGlobalBounds().width / 2, this->play2->getGlobalBounds().height / 2);
	this->play2->setPosition(window->getSize().x / 2, window->getSize().y / 2 + 110);

	this->quit = new Text("QUIT", *this->font, 55U);
	this->quit->setOrigin(this->quit->getGlobalBounds().width / 2, this->quit->getGlobalBounds().height / 2);
	this->quit->setPosition(window->getSize().x / 2, window->getSize().y / 2 + 186);
}

void SaveGame::Update(RenderWindow* window)
{

	if ((Keyboard::isKeyPressed(Keyboard::Key::Up) || Keyboard::isKeyPressed(Keyboard::Key::W)) && !this->upKey) { // phím lên đang được nhấn, upkey = false
		this->selected -= 1;
	}
	if ((Keyboard::isKeyPressed(Keyboard::Key::Down) || Keyboard::isKeyPressed(Keyboard::Key::S)) && !this->downKey) { // phím xuống đang được nhấn, downkey = false
		this->selected += 1;
	}
	if (selected > 3) { // lựa chọn quá 3 thì quay về là 0
		this->selected = 0;
	}
	if (selected < 0) { // lựa chọn quá 0 thì quay về là 3
		this->selected = 3;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Space)) { // enter được nhấn
		switch (this->selected) {
		case 0: {
			CreateMap();
			break;
		}
		case 1: {
			coreState.SetState(new MainGameAI()); // vào game 1 người chơi
			break;
		}
		case 2: {
			coreState.SetState(new MainGame()); // vào game 2 người chơi
			break;
		}
		case 3: {
			quitGame = true;  // thoát game
			break;
		}
		}
	}
	this->upKey = (Keyboard::isKeyPressed(Keyboard::Key::Up)||Keyboard::isKeyPressed(Keyboard::Key::W)); // cập nhật phím upkey
	this->downKey = (Keyboard::isKeyPressed(Keyboard::Key::Down)||Keyboard::isKeyPressed(Keyboard::Key::S)); // // cập nhật phím downkey
}

void SaveGame::Render(RenderWindow* window)
{
	window->draw(this->background);
	this->play1->setFillColor(Color::White); // default color là white
	this->play1->setOutlineThickness(4);
	this->play1->setOutlineColor(Color::Black);
	this->play2->setFillColor(Color::White);
	this->play2->setOutlineThickness(4);
	this->play2->setOutlineColor(Color::Black);
	this->quit->setFillColor(Color::White);
	this->quit->setOutlineThickness(4);
	this->quit->setOutlineColor(Color::Black);
	this->next->setFillColor(Color::White);
	this->next->setOutlineThickness(4);
	this->next->setOutlineColor(Color::Black);
	switch (this->selected) { // xem mục nào đang được chọn
	case 0: {
		this->next->setOutlineColor(Color::Transparent);
		this->next->setFillColor(Color::Yellow); // khi được chọn chuyển sang yellow
		break;
	}
	case 1: {
		this->play1->setOutlineColor(Color::Transparent);
		this->play1->setFillColor(Color::Yellow); 
		break;
	}
	case 2: {
		this->play2->setOutlineColor(Color::Transparent);
		this->play2->setFillColor(Color::Yellow);
		break;
	}
	case 3: {
		this->quit->setOutlineColor(Color::Transparent);
		this->quit->setFillColor(Color::Yellow);
		break;
	}
	}
	// vẽ các text
	window->draw(*this->next);
	window->draw(*this->play1);
	window->draw(*this->play2);
	window->draw(*this->quit);
}

void SaveGame::Destroy(RenderWindow* window)
{
	delete this->font;
	delete this->play1;
	delete this->play2;
	delete this->quit;
	delete this->next;
}

void SaveGame::UpdateSaveGame()
{
	ifstream readfile;
	readfile.open("Data/SaveGame.txt");
	if (readfile.is_open())
	{
		readfile >> player;
		readfile >> type;
		readfile >> _score1;
		readfile >> _score2;
	}
	readfile.close();
}

void SaveGame::CreateMap()
{
	UpdateSaveGame();
	if (player == "1Player")
	{
		if (this->type == 1)
			coreState.SetState(new FireMap(_score1, _score2));
		else if (this->type == 2)
			coreState.SetState(new WaterMap(_score1, _score2));
		else if (this->type == 3)
			coreState.SetState(new RockMap(_score1, _score2));
		else if (this->type == 4)
			coreState.SetState(new WindMap(_score1, _score2));
	}
	else
	{
		if (this->type == 1)
			coreState.SetState(new FireMapAI(_score1, _score2));
		else if (this->type == 2)
			coreState.SetState(new WaterMapAI(_score1, _score2));
		else if (this->type == 3)
			coreState.SetState(new RockMapAI(_score1, _score2));
		else if (this->type == 4)
			coreState.SetState(new WindMapAI(_score1, _score2));
	}
}
