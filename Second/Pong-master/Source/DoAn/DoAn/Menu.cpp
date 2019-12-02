#include "Menu.h"

Menu::Menu()
{
	if (!font.loadFromFile("pong.ttf"))
	{
		cout << "Font file not found!" << endl;
		exit(-1);
	}
	menu = NULL;
	sl = 0;
}

Menu::~Menu()
{
	if (menu != NULL)
		delete[] menu;
	sl = 0;
}

void Menu::startMenu()
{
	sl = 4;	//so luong Text có trong start menu
	menu = new Text[sl];

	//thiết lập các thuộc tính cho text
	//thiết lập font
	menu[0].setFont(font);
	//thiết lập nội dung của text
	menu[0].setString("PONG");
	//thiết lạp size chữ
	menu[0].setCharacterSize(125);
	//thiết lập màu chữ
	menu[0].setFillColor(Color::White);
	//thiết lập vị trí tâm của text.
	menu[0].setOrigin(Vector2f(menu[0].getGlobalBounds().width / 2, menu[0].getGlobalBounds().height / 2));
	//thiết lập vị trí của text trên cửa sổ.
	menu[0].setPosition(sf::Vector2f(SCREEN_X / 2, SCREEN_Y / (sl + 1) * 1.5));


	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("ONE PLAYER");
	menu[1].setOrigin(Vector2f(menu[1].getGlobalBounds().width / 2, menu[1].getGlobalBounds().height / 2));
	menu[1].setPosition(sf::Vector2f(SCREEN_X / 2, SCREEN_Y / (sl + 1) * 3.5));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("TWO PLAYERS");
	menu[2].setOrigin(Vector2f(menu[2].getGlobalBounds().width / 2, menu[2].getGlobalBounds().height / 2));
	menu[2].setPosition(sf::Vector2f(SCREEN_X / 2, SCREEN_Y / (sl + 1) * 4));

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("QUIT");
	menu[3].setOrigin(Vector2f(menu[3].getGlobalBounds().width / 2, menu[3].getGlobalBounds().height / 2));
	menu[3].setPosition(sf::Vector2f(SCREEN_X / 2, SCREEN_Y / (sl + 1) * 4.5));

}

void Menu::draw(RenderWindow& window)
{
	for (int i = 0; i < sl; i++)
	{
		window.draw(menu[i]);
	}
}



void Menu::resultMenu(int& winner)
//in kết quả thắng thua ra màn hình
{
	sl = 4;
	menu = new Text[sl];

	//nếu người chơi bên trái thắng
	if (winner == 1)
	{
		menu[0].setFont(font);
		menu[0].setString("WIN");
		menu[0].setFillColor(Color::White);
		menu[0].setCharacterSize(60);
		menu[0].setOrigin(Vector2f(menu[0].getGlobalBounds().width / 2, menu[0].getGlobalBounds().height / 2));
		menu[0].setPosition(Vector2f(SCREEN_X / 4, SCREEN_Y / 2));


		menu[1].setFont(font);
		menu[1].setFillColor(Color::White);
		menu[1].setString("LOSE");
		menu[1].setCharacterSize(60);
		menu[1].setOrigin(Vector2f(menu[1].getGlobalBounds().width / 2, menu[1].getGlobalBounds().height / 2));
		menu[1].setPosition(Vector2f(3 * SCREEN_X / 4, SCREEN_Y / 2));
	}
	//nếu người chơi bên trái thua
	else
	{
		menu[0].setFont(font);
		menu[0].setString("LOSE");
		menu[0].setFillColor(Color::White);
		menu[0].setCharacterSize(60);
		menu[0].setOrigin(Vector2f(menu[0].getGlobalBounds().width / 2, menu[0].getGlobalBounds().height / 2));
		menu[0].setPosition(Vector2f(SCREEN_X / 4, SCREEN_Y / 2));


		menu[1].setFont(font);
		menu[1].setFillColor(Color::White);
		menu[1].setString("WIN");
		menu[1].setCharacterSize(60);
		menu[1].setOrigin(Vector2f(menu[1].getGlobalBounds().width / 2, menu[1].getGlobalBounds().height / 2));
		menu[1].setPosition(Vector2f(3 * SCREEN_X / 4, SCREEN_Y / 2));
	}

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("REPLAY");
	menu[2].setOrigin(Vector2f(menu[2].getGlobalBounds().width / 2, menu[2].getGlobalBounds().height / 2));
	menu[2].setPosition(sf::Vector2f(SCREEN_X / 2, SCREEN_Y / sl * 3));

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("QUIT");
	menu[3].setOrigin(Vector2f(menu[3].getGlobalBounds().width / 2, menu[3].getGlobalBounds().height / 2));
	menu[3].setPosition(sf::Vector2f(SCREEN_X / 2, SCREEN_Y / sl * 3.5));


}



