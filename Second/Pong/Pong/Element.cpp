#include "Element.h"
#include "FireMap.h" // chỉ được để ở đây (?)
#include "WindMap.h"
#include "WaterMap.h"
#include "RockMap.h"

#include "FireMapAI.h"
#include "RockMapAI.h"
#include "WaterMapAI.h"
#include "WindMapAI.h"

Element::Element(Score* Score1, Score* Score2,Ball* Ball, int type) {
	this->Score1 = Score1;
	this->Score2 = Score2;
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
			coreState.SetState(new FireMap(this->Score1->value,this->Score2->value));
		else if (this->type == 2)
			coreState.SetState(new WaterMap(this->Score1->value, this->Score2->value));
		else if (this->type == 3)
			coreState.SetState(new RockMap(this->Score1->value, this->Score2->value));
		else if (this->type == 4)
			coreState.SetState(new WindMap(this->Score1->value, this->Score2->value));
	}
}
void Element::UpdateAI() {
	if (this->CheckCollision(this->BallObject)) {
		this->sound->play(); // chạm bóng thì play sound
		if (this->type == 1)
			coreState.SetState(new FireMapAI(this->Score1->value, this->Score2->value));
		else if (this->type == 2)
			coreState.SetState(new WaterMapAI(this->Score1->value, this->Score2->value));
		else if (this->type == 3)
			coreState.SetState(new RockMapAI(this->Score1->value, this->Score2->value));
		else if (this->type == 4)
			coreState.SetState(new WindMapAI(this->Score1->value, this->Score2->value));
	}
}
Element::~Element() {
	delete this->sound;
	delete this->buffer;
}
