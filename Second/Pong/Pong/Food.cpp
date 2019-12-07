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
	int x, y;
	bool check = false;
	x = 1 + rand() % (4 + 1 - 1);  // random só từ 1 đến 4
	y = 1 + rand() % (Windows_Height - 41 + 1 - 1);  // random só từ 1 đến window_height 41
	if (x == 1)
		this->setPosition(window->getSize().x / 5 * x, y);
	else if (x == 2)
		this->setPosition(window->getSize().x / 5 * x, y);
	else if (x == 3)
		this->setPosition(window->getSize().x / 5 * x, y);
	else if (x == 4)
		this->setPosition(window->getSize().x / 5 * x, y);
}
void Food::Update() {
	if (this->CheckCollision(this->BallObject)) {
		this->sound->play(); // chạm bóng thì play sound
		this->eaten = true;
		if (this->BallObject->owning == 1)
			this->Score1->ScoreUp();
		else if (this->BallObject->owning == 2)
			this->Score2->ScoreUp();
	}
}
Food::~Food() {
	delete this->sound;
	delete this->buffer;
}
