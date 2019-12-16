#include "EndGame.h"


EndGame::EndGame(int _score1, int _score2)
{
	this->_score1 = _score1;
	this->_score2 = _score2;
	if (_score1 > _score2)
		score = _score1;
	else
		score = _score2;
}

void EndGame::SortScore()
{
	////Input charts
	//ifstream readFile;
	//readFile.open("Data/Charts.txt");
	//if (readFile.is_open())
	//{
	//	int dem = 0;
	//	while (!readFile.eof())
	//	{
	//		int temp;
	//		readFile >> temp;
	//		listscore.push_back(temp);
	//	}
	//}
	//readFile.close();
	////Sort
	//for (int i = 0; i < 5; i++)
	//	if (this->score > listscore[i])
	//		listscore.insert(listscore.begin() + i, score);
	//listscore.pop_back();
	////Output charts
	//ofstream writeFile;
	//writeFile.open("Data/Charts.txt");
	//if (writeFile.is_open())
	//{
	//	for (int i = 0; i < 5; i++)
	//		writeFile << listscore[i] << endl;
	//}
	//writeFile.close();

}

void EndGame::Initialize(RenderWindow* window)
{
	this->selected = 0;

	//Input charts
	ifstream readFile;
	readFile.open("Data/Charts.txt");
	if (readFile.is_open())
	{
		int dem = 0;
		while (!readFile.eof())
		{
			int temp;
			readFile >> temp;
			listscore.push_back(temp);
		}
	}
	readFile.close();
	//Sort
	bool check = true;
	for (int i = 0; i < 5; i++)
		if (this->score > listscore[i] && check == true)
		{
			listscore.insert(listscore.begin() + i, score);
			check = false;
		}
	listscore.pop_back();
	//Output charts
	ofstream writeFile;
	writeFile.open("Data/Charts.txt");
	if (writeFile.is_open())
	{
		for (int i = 0; i < 5; i++)
			writeFile << listscore[i] << endl;
	}
	writeFile.close();

	this->font = new Font(); // tạo font
	this->font->loadFromFile("Graphics/Nexa-Black.ttf");

	this->title = new Text("CHARTS", *this->font, 60U); // nội dung & size của font
	this->title->setOrigin(this->title->getGlobalBounds().width / 2, this->title->getGlobalBounds().height / 2); // set origin ở giữa vật (thay vì topleft)
	this->title->setPosition(window->getSize().x / 2, window->getSize().y / 2 - 180); // set vị trí

	this->score1 = new Text(to_string(listscore[0]), *this->font, 40U);
	this->score1->setOrigin(this->score1->getGlobalBounds().width / 2, this->score1->getGlobalBounds().height / 2);
	this->score1->setPosition(window->getSize().x / 2, window->getSize().y / 2 - 120);

	this->score2 = new Text(to_string(listscore[1]), *this->font, 40U);
	this->score2->setOrigin(this->score2->getGlobalBounds().width / 2, this->score2->getGlobalBounds().height / 2);
	this->score2->setPosition(window->getSize().x / 2, window->getSize().y / 2 - 80);

	this->score3 = new Text(to_string(listscore[2]), *this->font, 40U);
	this->score3->setOrigin(this->score3->getGlobalBounds().width / 2, this->score3->getGlobalBounds().height / 2);
	this->score3->setPosition(window->getSize().x / 2, window->getSize().y / 2 - 40);

	this->score4 = new Text(to_string(listscore[3]), *this->font, 40U);
	this->score4->setOrigin(this->score4->getGlobalBounds().width / 2, this->score4->getGlobalBounds().height / 2);
	this->score4->setPosition(window->getSize().x / 2, window->getSize().y / 2);

	this->score5 = new Text(to_string(listscore[4]), *this->font, 40U);
	this->score5->setOrigin(this->score5->getGlobalBounds().width / 2, this->score5->getGlobalBounds().height / 2);
	this->score5->setPosition(window->getSize().x / 2, window->getSize().y / 2 + 40);

	this->menu = new Text("MENU", *this->font, 55U);
	this->menu->setOrigin(this->menu->getGlobalBounds().width / 2, this->menu->getGlobalBounds().height / 2);
	this->menu->setPosition(window->getSize().x / 2, window->getSize().y / 2 + 100);

	this->quit = new Text("QUIT", *this->font, 55U);
	this->quit->setOrigin(this->quit->getGlobalBounds().width / 2, this->quit->getGlobalBounds().height / 2);
	this->quit->setPosition(window->getSize().x / 2, window->getSize().y / 2 + 160);

	if (_score1 > _score2)
	{
		this->win = new Text("PLAYER 1 WIN", *this->font, 60U); // nội dung & size của font
		this->win->setOrigin(this->win->getGlobalBounds().width / 2, this->win->getGlobalBounds().height / 2); // set origin ở giữa vật (thay vì topleft)
		this->win->setPosition(window->getSize().x / 2, window->getSize().y / 2 - 280); // set vị trí
	}
	else
	{
		this->win = new Text("PLAYER 2 WIN", *this->font, 60U); // nội dung & size của font
		this->win->setOrigin(this->win->getGlobalBounds().width / 2, this->win->getGlobalBounds().height / 2); // set origin ở giữa vật (thay vì topleft)
		this->win->setPosition(window->getSize().x / 2, window->getSize().y / 2 - 280); // set vị trí
	}
}

void EndGame::Update(RenderWindow* window)
{
	if ((Keyboard::isKeyPressed(Keyboard::Key::Up) || Keyboard::isKeyPressed(Keyboard::Key::W)) && !this->upKey) // phím lên đang được nhấn, upkey = false
		this->selected -= 1;
	if ((Keyboard::isKeyPressed(Keyboard::Key::Down) || Keyboard::isKeyPressed(Keyboard::Key::S)) && !this->downKey) // phím xuống đang được nhấn, downkey = false
		this->selected += 1;
	if (selected > 1) // lựa chọn quá 1 thì quay về là 0
		this->selected = 0;
	if (selected < 0) // lựa chọn quá 0 thì quay về là 1
		this->selected = 1;

	if (Keyboard::isKeyPressed(Keyboard::Key::Space)) { // enter được nhấn
		switch (this->selected) {
		case 0: {
			coreState.SetState(new MainMenu());
			break;
		}
		case 1: {
			quitGame = true;  // thoát game
			break;
		}
		}
	}
	this->upKey = (Keyboard::isKeyPressed(Keyboard::Key::Up)||Keyboard::isKeyPressed(Keyboard::Key::W)); // cập nhật phím upkey
	this->downKey = (Keyboard::isKeyPressed(Keyboard::Key::Down)||Keyboard::isKeyPressed(Keyboard::Key::S)); // // cập nhật phím downkey

}

void EndGame::Render(RenderWindow* window)
{
	this->title->setFillColor(Color::White); // default color là white
	this->score1->setFillColor(Color::White);
	this->score2->setFillColor(Color::White);
	this->score3->setFillColor(Color::White);
	this->score4->setFillColor(Color::White);
	this->score5->setFillColor(Color::White);
	this->menu->setFillColor(Color::White);
	this->quit->setFillColor(Color::White);
	this->win->setFillColor(Color::White);

	switch (this->selected)
	{ // xem mục nào đang được chọn
	case 0:
	{
		this->menu->setFillColor(Color::Green); // khi được chọn chuyển sang green
		break;
	}
	case 1:
	{
		this->quit->setFillColor(Color::Green);
		break;
	}
	}

	window->draw(*this->title);
	window->draw(*this->score1);
	window->draw(*this->score2);
	window->draw(*this->score3);
	window->draw(*this->score4);
	window->draw(*this->score5);
	window->draw(*this->menu);
	window->draw(*this->quit);
	window->draw(*this->win);

}

void EndGame::Destroy(RenderWindow* window)
{
	delete this->title;
	delete this->score1;
	delete this->score2;
	delete this->score3;
	delete this->score4;
	delete this->score5;
	delete this->menu;
	delete this->quit;
	delete this->win;
}

