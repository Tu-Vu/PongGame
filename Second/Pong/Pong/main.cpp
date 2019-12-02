#include "GameState.h"
#include "MainMenu.h"

#include <Windows.h> // de sau thi ko bi bug

#define Windows_Height 600
#define Windows_Weight 800
GameState coreState;
bool quitGame = false;
int main(){
	RenderWindow window(VideoMode(Windows_Weight, Windows_Height), "Pong Game");
	coreState.SetWindow(&window);
	coreState.SetState(new MainMenu());

	while (window.isOpen()){							// run the program as long as the window is open
		Event event;									 // check all the window's events that were triggered since the last iteration of the loop
		while (window.pollEvent(event))	{				// "close requested" event: we close the window
			if (event.type == Event::Closed)
				window.close();
		}
	
		window.clear(Color::Black);

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