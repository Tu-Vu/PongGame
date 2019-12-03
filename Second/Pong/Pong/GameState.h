#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_
#include <SFML/Graphics.hpp>
using namespace sf;
class TinyState{ // hàm ảo không làm gì cả
public:
	virtual void Initialize(RenderWindow* window) =0;
	virtual void Update(RenderWindow* window) =0;
	virtual void Render(RenderWindow* window) =0;
	virtual void Destroy(RenderWindow* window) =0;
};
class GameState {
private:
	RenderWindow* window; // windows
	TinyState* state; 
public:
	GameState();
	~GameState(); //hàm hủy
	void SetWindow(RenderWindow* window); // set window
	void SetState(TinyState* state); // set state
	void Update(); // update sự kiện
	void Render(); // render đồ họa
};
// biến global trong 1 file (.c/.cpp/.h) và truy cập biến này từ 1 file (.c/.cpp/.h) khác
extern GameState coreState; 
extern bool quitGame; // check xem người chơi quit 
extern int Windows_Height; // chiều rộng màn hình
extern int Windows_Weight; // chiều dài màn hình
#endif