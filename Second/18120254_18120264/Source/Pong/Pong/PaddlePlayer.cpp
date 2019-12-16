#include "PaddlePlayer.h"


PaddlePlayer::PaddlePlayer(int playerNumber) {
	this->playerNumber = playerNumber; // loại người chơi
	switch (this->playerNumber) {
	case 0: { // người chơi 1
		this->Load("paddle1.png"); // load hình cho paddle
		break;
	}
	case 1: { // người chơi 2
		this->Load("paddle2.png"); // load hình cho paddle
		break;
	}
	case 2: { // người chơi 1 dùng cho fire map
		this->Load("paddle1_fire.png"); // load hình cho paddle
		break;
	}
	case 3: { // người chơi 2 dùng cho fire map
		this->Load("paddle2_fire.png"); // load hình cho paddle
		break;
	}
	}
}
void PaddlePlayer::Update() {
	switch (this->playerNumber) { // mỗi người chơi có control khác nhau
	case 0: case 2: { // người chơi 1
		this->velocity.y = Keyboard::isKeyPressed(Keyboard::Key::S) - Keyboard::isKeyPressed(Keyboard::Key::W); 
		break;
	}
	case 1: case 3:{ // người chơi 2
		this->velocity.y = Keyboard::isKeyPressed(Keyboard::Key::Down) - Keyboard::isKeyPressed(Keyboard::Key::Up);
		break;
	}
	}
	Entity::Update(); // di chuyển entity theo vector velocity
	if (this->getPosition().y < 0) { // paddle chạm nóc thì dừng (lố nóc 1 pixel)
		this->move(0, 1); // +1 y lại cho paddle
	}
	if (this->getPosition().y + this->getGlobalBounds().height > Windows_Height) { // paddle chạm đáy thì dừng (lỗ đáy 1 pixel)
		this->move(0, -1); // -1 y lại cho paddle
	}
	
}