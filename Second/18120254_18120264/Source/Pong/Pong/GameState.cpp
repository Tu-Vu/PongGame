#include "GameState.h"
GameState::GameState() { // hàm tạo
	this->state = NULL;
}
GameState::~GameState() { // hàm hủy
	if (this->state != NULL)
		this->state->Destroy(this->window);
}
void GameState::SetWindow(RenderWindow* window) { // đặt window cho game
	this->window = window;
}
void GameState::SetState(TinyState* state) { // đặt giai đoạn cho game đang là giai đoạn nào
	if (this->state != NULL)
		this->state->Destroy(this->window);
	this->state = state;
	if (this->state != NULL)
		this->state->Initialize(this->window);
}
void GameState::Update() { // gọi đến hàm update sự kiện
	if (this->state != NULL)
		this->state->Update(this->window);
}
void GameState::Render() { // hàm render đồ họa
	if (this->state != NULL)
		this->state->Render(this->window);
}