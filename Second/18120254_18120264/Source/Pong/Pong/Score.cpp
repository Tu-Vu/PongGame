#include "Score.h"

Score::Score(Font& font,unsigned int size) :Text("",font,size) { // kế thừa từ class Text, với text ban đầu là 0
	this->value = 0;
}
void Score::ScoreUp(){
	this->value +=1; // tăng điểm +1
}
void Score::ScoreDown() {
	this->value -= 1; // giảm điểm +1
}
void Score::Update() {
	this->setString(to_string(this->value)); // convert int value thành string để update hình vẽ
}