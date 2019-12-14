#include "Food.h"
#include <iostream>
using namespace std;
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
Food::Food(Score* Score1, Score* Score2, Ball* Ball, int type) { // dùng cho water map
	this->type = type;
	if (this->type == 1)
		this->Load("food2.png"); // load hình ảnh vô texture 
	else if (this->type == 2)
		this->Load("poison.png"); // load hình ảnh vô texture 

	this->Score1 = Score1;
	this->Score2 = Score2;
	this->BallObject = Ball;

	this->setOrigin(this->getGlobalBounds().width /2, this->getGlobalBounds().height / 2);
	this->buffer = new SoundBuffer();
	this->buffer->loadFromFile("Sounds/bounce.wav");
	this->sound = new Sound(*this->buffer);

	this->eaten = false;
}
void Food::RockReset(RenderWindow* window) {
	int x, y; // r = minN + rand() % (maxN + 1 - minN)
	x = 1 + rand() % (4 + 1 - 1);  // random só từ 1 đến 4
	y = 1 + rand() % (Windows_Height - 41 + 1 - 1);  // random só từ 1 đến window_height - 41
	if (x == 1)
		this->setPosition(window->getSize().x / 5 * x, y);
	else if (x == 2)
		this->setPosition(window->getSize().x / 5 * x, y);
	else if (x == 3)
		this->setPosition(window->getSize().x / 5 * x, y);
	else if (x == 4)
		this->setPosition(window->getSize().x / 5 * x, y);
}
void Food::WindReset(RenderWindow* window) {
	int x, y;
	x = 1 + rand() % (100 + 1 - 1);  // random só từ 1 đến 100
	y = 1 + rand() % (Windows_Height - 41 + 1 - 1);  // random só từ 1 đến window_height 41
	int randomside = 1 + rand() % (2 + 1 - 1);  // random só từ 1 đến 2
	if (randomside == 1)
		this->setPosition(window->getSize().x / 2 - 100 - 79 - x, y);
	else
		this->setPosition(window->getSize().x / 2 + 79 + x, y);
}
void Food::WaterReset(RenderWindow* window) {
	int x, y;
	x = 51 + rand() % (Windows_Weight - 51 - 41 + 1 - 51);  // random só từ 51 đến window_weight -51 -41
	y = 1 + rand() % (Windows_Height - 41 + 1 - 1);  // random só từ 51 đến window_height -41
	this->setPosition(x, y);
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
void Food::PoisonUpdate() {
	if (this->CheckCollision(this->BallObject)) {
		this->sound->play(); // chạm bóng thì play sound
		this->eaten = true;
		if (this->BallObject->owning == 1) {
			this->Score1->ScoreDown();
			this->Score1->ScoreDown();
		}
		else if (this->BallObject->owning == 2){
			this->Score2->ScoreDown();
			this->Score2->ScoreDown();
		}
	}
}
void Food::Food2Update() {
	if (this->CheckCollision(this->BallObject)) {
		this->sound->play(); // chạm bóng thì play sound
		this->eaten = true;
		if (this->BallObject->owning == 1) {
			this->Score1->ScoreUp();
			this->Score1->ScoreUp();
			this->Score1->ScoreUp();
		}
		else if (this->BallObject->owning == 2) {
			this->Score2->ScoreUp();
			this->Score2->ScoreUp();
			this->Score2->ScoreUp();
		}
	}
}
Food::~Food() {
	/*delete this->sound;
	delete this->buffer;*/
}
