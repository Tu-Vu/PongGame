#include "GameState.h"
#include "MainMenu.h"
#include <Windows.h> // de sau thi ko bi bug


GameState coreState;
bool quitGame = false;
int Windows_Height = 600;
int Windows_Weight = 800;

int main(){

	RenderWindow window(VideoMode(Windows_Weight, Windows_Height), "Pong Game"); // tạo window
	coreState.SetWindow(&window); // truyền giá trị vào cho window
	coreState.SetState(new MainMenu()); // hiển thị menu

	while (window.isOpen()){							// chạy chương trình khi window đang mở
		Event event;									 // kiểm tra sự kiện
		while (window.pollEvent(event))	{				// nếu đóng window
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear(Color::Blue);
		coreState.Update();
		coreState.Render();
		window.display();
		if (quitGame) {
			window.close();
		}
		Sleep(5);
	}

	return 0;
}