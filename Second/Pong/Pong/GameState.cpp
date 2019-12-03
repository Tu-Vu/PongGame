#include "GameState.h"
GameState::GameState() {
	this->state = NULL;
}
GameState::~GameState() {
	if (this->state != NULL)
		this->state->Destroy(this->window);
}
void GameState::SetWindow(RenderWindow* window) {
	this->window = window;
}
void GameState::SetState(TinyState* state) {
	if (this->state != NULL)
		this->state->Destroy(this->window);
	this->state = state;
	if (this->state != NULL)
		this->state->Initialize(this->window);
}
void GameState::Update() {
	if (this->state != NULL)
		this->state->Update(this->window);
}
void GameState::Render() {
	if (this->state != NULL)
		this->state->Render(this->window);
}