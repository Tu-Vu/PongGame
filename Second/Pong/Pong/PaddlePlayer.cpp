#include "PaddlePlayer.h"


PaddlePlayer::PaddlePlayer(int playerNumber) {
	this->playerNumber = playerNumber;
	switch (this->playerNumber) {
	case 0: { // nguoi choi 1
		this->Load("paddle1.png");
		break;
	}
	default: { // nguoi choi 2
		this->Load("paddle2.png");
		break;
	}
	}
}
void PaddlePlayer::Update() {
	switch (this->playerNumber) // moi nguoi choi co control khac nhau
	{
	case 0: {
		this->velocity.y = Keyboard::isKeyPressed(Keyboard::Key::S) - Keyboard::isKeyPressed(Keyboard::Key::W); 
		break;
	}
	default: {
		this->velocity.y = Keyboard::isKeyPressed(Keyboard::Key::Down) - Keyboard::isKeyPressed(Keyboard::Key::Up);
		break;
	}
	}
	Entity::Update(); // moving object
	if (this->getPosition().y < 0) { // paddle cham noc thi dung (lố nóc 1 pixel)
		this->move(0, 1); //+1 pixel y lại cho paddle
	}
	if (this->getPosition().y + this->getGlobalBounds().height > Windows_Height) { // paddle cham day thi dung (lỗ đáy 1 pixel)
		this->move(0, -1); //-1 pixel lại cho paddle
	}
}