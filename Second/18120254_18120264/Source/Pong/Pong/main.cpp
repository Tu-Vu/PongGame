﻿#include "GameState.h"
#include "MainMenu.h"
#include <Windows.h> // de sau thi ko bi bug


GameState coreState; // các giai đoạn của game
bool quitGame = false; // check xem người chơi muốn thoát hay không
int Windows_Height = 600; // chiều rộng cửa sổ
int Windows_Weight = 800; // chiều ngang cửa sổ

int main(){

	RenderWindow window(VideoMode(Windows_Weight, Windows_Height), "Pong Game"); // tạo window
	coreState.SetWindow(&window); // truyền giá trị vào cho window
	coreState.SetState(new MainMenu()); // hiển thị menu. Initialize game

	while (window.isOpen()){							// chạy chương trình khi window đang mở
		Event event;									// kiểm tra sự kiện
		while (window.pollEvent(event))	{				
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear(Color::Black);  // tạo nền
		
		coreState.Update(); // update sự kiện
		coreState.Render(); // render đồ họa
		
		window.display(); // hiển thị window
	
		if (quitGame) { 
			window.close(); // thoát game
		}
		Sleep(5); // độ trễ của game
	}
	return 0;
}