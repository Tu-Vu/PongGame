#ifndef _ELEMENT_H_
#define _ELEMENT_H_
#include <SFML/Audio.hpp>
#include "Ball.h"
class Element :public Entity {
private:
	Ball* BallObject;
	SoundBuffer* buffer; // buffer cho âm thanh
	Sound* sound; // âm thanh

public:
	int type;
	Element(Ball* BallObject,int type);
	~Element();
	virtual void Update(); // update sự kiện
};
#endif

