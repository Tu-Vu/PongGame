#include "Score.h"

Score::Score(Font& font,unsigned int size) :Text("0",font,size) {
	this->value = 0;
}

void Score::ScoreUp()
{
	this->value += 1;
}
void Score::Update() {
	this->setString(to_string(this->value));
}