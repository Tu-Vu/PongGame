#include "PaddleAI.h"


PaddleAI::PaddleAI(int playerNumber) {
	this->playerNumber = playerNumber;
	this->checkrock = 0; // sử dụng cho rock map
	switch (this->playerNumber) {
	case 0: { // người chơi 1
		this->Load("paddle1.png"); // load hình cho paddle
		break;
	}
	case 2: { // người chơi 1
		this->Load("rock.png"); // load hình cho paddle
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
void PaddleAI::UpdateRock(int type) {
	if(type == 0 && checkrock==0) // đi xuống, mới khởi tạo
		this->move(0, 0.48f);
	if (type == 1 && checkrock ==0) // đi lên, mới khởi tạo
		this->move(0, -0.48f);
	if(this->checkrock==1) // chạm đáy
		this->move(0, -0.48f);
	if(this->checkrock==2) // chạm nóc
		this->move(0, 0.48f);
	Entity::Update(); // di chuyển entity theo vector velocity

	if (this->getPosition().y < 0) { // paddle chạm nóc thì dừng (lố nóc 1 pixel)
		this->move(0, 1); // +1 y lại cho paddle
		this->checkrock = 2;
	}
	if (this->getPosition().y + this->getGlobalBounds().height > Windows_Height) { // paddle chạm đáy thì dừng (lỗ đáy 1 pixel)
		this->move(0, -1); // -1 y lại cho paddle
		this->checkrock = 1;
	}
}