#include "Element.h"
#include "FireMap.h" // chỉ được để ở đây (?)
Element::Element(Ball* Ball, int type) {
	this->type = type;
	if (this->type == 1)
		this->Load("elementfire.png"); // load hình ảnh vô texture 
	else if (this->type == 2)
		this->Load("elementwater.png"); // load hình ảnh vô texture 
	else if (this->type == 3)
		this->Load("elementrock.png"); // load hình ảnh vô texture 
	else if (this->type == 4)
		this->Load("elementwind.png"); // load hình ảnh vô texture 
	this->BallObject = Ball;

	this->buffer = new SoundBuffer();
	this->buffer->loadFromFile("Sounds/bounce.wav");
	this->sound = new Sound(*this->buffer);

}
void Element::Update() {
	if (this->CheckCollision(this->BallObject)) {
		this->sound->play(); // chạm bóng thì play sound
		if (this->type == 1)
			coreState.SetState(new FireMap());
		else if (this->type == 2)
			coreState.SetState(new FireMap());
		else if (this->type == 3)
			coreState.SetState(new FireMap());
		else if (this->type == 4)
			coreState.SetState(new FireMap());
	}
}
Element::~Element() {
	delete this->sound;
	delete this->buffer;
}
