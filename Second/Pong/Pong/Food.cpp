#include "Food.h"

Food::Food(Score* Score1, Score* Score2, Ball* Ball) {
	this->Load("food.png"); // load hình ảnh vô texture 
	this->Score1 = Score1;
	this->Score2 = Score2;
	this->BallObject = Ball;

	this->buffer = new SoundBuffer();
	this->buffer->loadFromFile("Sounds/bounce.wav");
	this->sound = new Sound(*this->buffer);
	 
	this->eaten = false;
}
void Food::Reset(RenderWindow* window) {
	//int x,y;
	//srand((int)time(0)); // random số khác nhau mỗi lần chạy
	//do {
	//	x = 50 + rand() % (355 + 1 - 5);  // random só từ 50 đến 355
	//	y = 50 + rand() % (355 + 1 - 5);  // random só từ 50 đến 355
	//} while (x>80 && y >80);
	this->setPosition(window->getSize().x / 2 + 100, window->getSize().y / 2 + 200); 
}
void Food::Update() {
	if (this->CheckCollision(this->BallObject)) {
		this->sound->play(); // chạm bóng thì play sound
		this->eaten = true;
		if(this->BallObject->owning == 1)
			this->Score1->ScoreUp();
		else if (this->BallObject->owning == 2)
			this->Score2->ScoreUp();
	}
}
Food::~Food() {
	delete this->sound;
	delete this->buffer;
}
