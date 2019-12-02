#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )


#include "Manager.h"




int main()
{
	int winner;
	int mode;

	RenderWindow window(VideoMode(SCREEN_X, SCREEN_Y), "PONG Game <3", Style::Close);

	Image icon;
	if (!icon.loadFromFile("pong.png"))
	{
		window.close();
		exit(-1);
	}

	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	window.setFramerateLimit(60);
	Music music;
	if (!music.openFromFile("PongMusic.ogg"))
	{
		window.close();
		return -1; // error
	}
	music.setLoop(true);


	while (true)
	{
		
		runStartMenu(window, mode);
		music.play();
		
		if (mode == 1)
			winner = playWithComputer(window);
		if (mode == 2)
			winner = playWithPerson(window);
		music.stop();
		runResultMenu(window, winner);
	}
	
	return 0;
}