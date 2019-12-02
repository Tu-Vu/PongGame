#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_
#include <SFML/Graphics.hpp>
using namespace sf;
class TinyState{
public:
	virtual void Initialize(RenderWindow* window) {};
	virtual void Update(RenderWindow* window) {};
	virtual void Render(RenderWindow* window) {};
	virtual void Destroy(RenderWindow* window) {};
};
class GameState {
private:
	RenderWindow* window;
	TinyState* state;
public:
	GameState()	{
		this->state = NULL;
	}
	~GameState() {
		if (this->state != NULL)
			this->state->Destroy(this->window);
	}
	void SetWindow(RenderWindow* window){
		this->window = window;
	}
	void SetState(TinyState* state){
		if (this->state != NULL)
			this->state->Destroy(this->window);
		this->state = state;
		if (this->state != NULL)
			this->state->Initialize(this->window);
	}
	void Update(){
		if (this->state != NULL)
			this->state->Update(this->window);
	}
	void Render(){
		if (this->state != NULL)
			this->state->Render(this->window);
	}
};
// biến global trong 1 file (.c/.cpp/.h) và truy cập biến này từ 1 file (.c/.cpp/.h) khác
extern GameState coreState;
extern bool quitGame;
#endif