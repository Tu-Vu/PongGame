#include "Ball.h"

Ball::Ball(Score* Score1, Score* Score2,PaddlePlayer* player1, PaddlePlayer* player2) {
	this->Load("ball.png");
	this->Score1 = Score1;
	this->Score2 = Score2;
	this->player1 = player1;
	this->player2 = player2;

	this->velocity.x = 0.75f; // van toc ban dau
	this->velocity.y = 0.75f; 
}
void Ball::Update(RenderWindow* window) {
	if (this->CheckCollision(this->player1) || this->CheckCollision(this->player2)) {
		this->velocity.x *= -1; // neu co va cham thi doi huong x
	}
	if (this->getPosition().y<0||this->getPosition().y+this->getGlobalBounds().height>Windows_Height) {
		this->velocity.y *= -1;
	}
	if (this->getPosition().x<this->player1->getGlobalBounds().width) {
		this->Score2->ScoreUp();
		this->setPosition(window->getSize().x / 2, window->getSize().y / 2);
	}
	if (this->getPosition().x >window->getSize().x - this->player2->getGlobalBounds().width) {
		this->Score1->ScoreUp();
		this->setPosition(window->getSize().x / 2, window->getSize().y / 2);
	}
	Entity::Update(); //moving object
}
