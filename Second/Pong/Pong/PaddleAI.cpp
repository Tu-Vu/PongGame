#include "PaddleAI.h"


PaddleAI::PaddleAI(int playerNumber) {
	this->playerNumber = playerNumber;
	switch (this->playerNumber) {
	case 0: { // người chơi 1
		this->Load("paddle1.png"); // load hình cho paddle
		break;
	}
	default: { // người chơi 2
		this->Load("paddle2.png"); // load hình cho paddle
		break;
	}
	}
}
void PaddleAI::SetBall(Ball* BallObject) {
	this->BallObject = BallObject; // set ball cho máy
}
void PaddleAI::Update() {
	// 2 vòng if giúp position của paddle không chênh lệch vs ball
	if (this->getPosition().y + this->getGlobalBounds().height / 2 < this->BallObject->getPosition().y) { // height/2  để hứng bóng ở trung tâm
		this->move(0, 1);
	}
	if (this->getPosition().y + this->getGlobalBounds().height / 2 > this->BallObject->getPosition().y) {
		this->move(0, -1);
	}

	Entity::Update(); // di chuyển entity theo vector velocity
	if (this->getPosition().y < 0) { // paddle chạm nóc thì dừng (lố nóc 1 pixel)
		this->move(0, 1); // +1 y lại cho paddle
	}
	if (this->getPosition().y + this->getGlobalBounds().height > Windows_Height) { // paddle chạm đáy thì dừng (lỗ đáy 1 pixel)
		this->move(0, -1); // -1 y lại cho paddle
	}

}