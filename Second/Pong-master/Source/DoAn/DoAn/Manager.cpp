#include "Manager.h"

int playWithPerson(RenderWindow& window)
{
	Ball ball;
	Border tBor, bBor;
	Paddle lPad, rPad;
	Score score1, score2;


	score1.player1Score();
	score2.player2Score();
	tBor.topBorder();
	bBor.botBorder();
	lPad.leftPaddle();
	rPad.rightPaddle();

	while (window.isOpen())
	{

		sf::Event event;

		window.pollEvent(event);

		if (event.type == sf::Event::EventType::Closed)
		{
			window.close();
			exit(0);
		}


		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			rPad.moveUp(tBor);
		}

		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			rPad.moveDown(bBor);
		}

		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			lPad.moveUp(tBor);
		}

		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			lPad.moveDown(bBor);
		}


		if (ball.getSprite().getGlobalBounds().intersects(tBor.getSprite().getGlobalBounds())
			|| ball.getSprite().getGlobalBounds().intersects(bBor.getSprite().getGlobalBounds()))
		{
			ball.intersectBorder();
		}

		if (ball.getSprite().getGlobalBounds().intersects(lPad.getSprite().getGlobalBounds())
			|| ball.getSprite().getGlobalBounds().intersects(rPad.getSprite().getGlobalBounds()))
		{
			ball.intersectPaddle();
		}

		if (ball.getSprite().getPosition().x < 0)
		{
			score2.increase();
			ball.reset();
		}

		if (ball.getSprite().getPosition().x > SCREEN_X)
		{
			score1.increase();
			ball.reset();
		}


		window.clear(Color(236, 135, 14));
		score1.draw(window);
		score2.draw(window);
		ball.draw(window);
		tBor.draw(window);
		bBor.draw(window);
		lPad.draw(window);
		rPad.draw(window);
		window.display();

		if (score1.getScore() == WIN_SCORE)
		{
			window.display();
			return 1;
		}
		if (score2.getScore() == WIN_SCORE)
		{
			window.display();
			return 2;
		}



		ball.move();

	}
}

int playWithComputer(RenderWindow& window)
{
	Ball ball;
	Border tBor, bBor;
	Paddle lPad, rPad;
	Score score1, score2;


	score1.player1Score();
	score2.player2Score();
	tBor.topBorder();
	bBor.botBorder();
	lPad.leftPaddle();
	rPad.rightPaddle();

	while (window.isOpen())
	{

		sf::Event event;

		window.pollEvent(event);

		if (event.type == sf::Event::EventType::Closed)
		{
			window.close();
			exit(0);
		}


		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			rPad.moveUp(tBor);
		}

		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			rPad.moveDown(bBor);
		}

		if (ball.getXVelocity() < 0 && ball.getSprite().getPosition().x < 3 * SCREEN_X / 4)
		{
			if (lPad.getSprite().getPosition().y < ball.getSprite().getPosition().y)
			{
				lPad.moveDown(bBor);
			}

			if (lPad.getSprite().getPosition().y > ball.getSprite().getPosition().y)
			{
				lPad.moveUp(tBor);
			}
		}


		if (ball.getSprite().getGlobalBounds().intersects(tBor.getSprite().getGlobalBounds())
			|| ball.getSprite().getGlobalBounds().intersects(bBor.getSprite().getGlobalBounds()))
		{
			ball.intersectBorder();
		}

		if (ball.getSprite().getGlobalBounds().intersects(lPad.getSprite().getGlobalBounds())
			|| ball.getSprite().getGlobalBounds().intersects(rPad.getSprite().getGlobalBounds()))
		{
			ball.intersectPaddle();
		}

		if (ball.getSprite().getPosition().x < 0)
		{
			score2.increase();
			ball.reset();
		}

		if (ball.getSprite().getPosition().x > SCREEN_X)
		{
			score1.increase();
			ball.reset();
		}


		window.clear(Color(236, 135, 14));
		score1.draw(window);
		score2.draw(window);
		ball.draw(window);
		tBor.draw(window);
		bBor.draw(window);
		lPad.draw(window);
		rPad.draw(window);
		window.display();

		if (score1.getScore() == WIN_SCORE)
		{
			window.display();
			return 1;
		}
		if (score2.getScore() == WIN_SCORE)
		{
			window.display();
			return 2;
		}



		ball.move();

	}
	
}


void runStartMenu(RenderWindow& window, int& mode)
{
	
	Menu start;
	window.clear(Color(0, 178, 191));
	start.startMenu();
	start.draw(window);
	window.display();

	Event event;
	//lấy sự kiện
	while (window.isOpen())
	{
		
		window.pollEvent(event);
		switch (event.type)
		{
		case sf::Event::Closed:
			//nếu nhấn vào nút CLOSE thì đóng cửa sổ và kết thúc game
			window.close();
			exit(0);

		case Event::MouseButtonPressed:
			//bắt sự kiện từ con chuột
			if (Mouse::isButtonPressed(Mouse::Left))
				//phát hiện ra tín hiệu từ chuột trái
			{
				//kiểm tra xem có phải con chuột nhấn vào nút ONE PLAYER hay không
				if (event.mouseButton.x <= (start.menu[1].getGlobalBounds().left + start.menu[1].getGlobalBounds().width) && event.mouseButton.x >= start.menu[1].getGlobalBounds().left
					&& event.mouseButton.y <= (start.menu[1].getGlobalBounds().top + start.menu[1].getGlobalBounds().height) && event.mouseButton.y >= start.menu[1].getGlobalBounds().top)
				{

					
					//Sau khi click ONE PLAYER
					//Bắt đầu chạy code chơi game
					mode = 1;
					return;


				}

				//kiểm tra xem có phải con chuột nhấn vào nút TWO PLAYERS hay không
				if (event.mouseButton.x <= (start.menu[2].getGlobalBounds().left + start.menu[2].getGlobalBounds().width) && event.mouseButton.x >= start.menu[2].getGlobalBounds().left
					&& event.mouseButton.y <= (start.menu[2].getGlobalBounds().top + start.menu[2].getGlobalBounds().height) && event.mouseButton.y >= start.menu[2].getGlobalBounds().top)
				{


					//Sau khi click TWO PLAYERS
					//Bắt đầu chạy code chơi game
					mode = 2;
					return;


				}

				//kiểm tra xem người chơi có click vào nút QUIT hay không.
				if (event.mouseButton.x <= (start.menu[3].getGlobalBounds().left + start.menu[3].getGlobalBounds().width) && event.mouseButton.x >= start.menu[3].getGlobalBounds().left
					&& event.mouseButton.y <= (start.menu[3].getGlobalBounds().top + start.menu[3].getGlobalBounds().height) && event.mouseButton.y >= start.menu[3].getGlobalBounds().top)
				{
					//nếu người chơi click vào QUIT thì đóng cửa sổ, kết thúc game
					window.close();
					exit(0);
				}
			}
		default:
			break;
		}
	}
}


void runResultMenu(RenderWindow& window, int& winner)
{
	Menu result;
	result.resultMenu(winner);
	result.draw(window);
	window.display();

	Event event;
	//lấy sự kiện
	while (window.isOpen())
	{
	
		window.pollEvent(event);
		switch (event.type)
		{
		case sf::Event::Closed:
			//nếu nhấn vào nút CLOSE thì đóng cửa sổ và kết thúc game
			window.close();
			exit(0);

		case Event::MouseButtonPressed:
			//bắt sự kiện từ con chuột
			if (Mouse::isButtonPressed(Mouse::Left))
				//phát hiện ra tín hiệu từ chuột trái
			{
				//kiểm tra xem có phải con chuột nhấn vào nút REPLAY hay không
				if (event.mouseButton.x <= (result.menu[2].getGlobalBounds().left + result.menu[2].getGlobalBounds().width) && event.mouseButton.x >= result.menu[2].getGlobalBounds().left
					&& event.mouseButton.y <= (result.menu[2].getGlobalBounds().top + result.menu[2].getGlobalBounds().height) && event.mouseButton.y >= result.menu[2].getGlobalBounds().top)

				{

					//Sau khi click REPLAY
					//return để chơi lại game
					
					return;

				}

				//kiểm tra xem người chơi có click vào nút QUIT hay không.
				if (event.mouseButton.x <= (result.menu[3].getGlobalBounds().left + result.menu[3].getGlobalBounds().width) && event.mouseButton.x >= result.menu[3].getGlobalBounds().left
					&& event.mouseButton.y <= (result.menu[3].getGlobalBounds().top + result.menu[3].getGlobalBounds().height) && event.mouseButton.y >= result.menu[3].getGlobalBounds().top)
				{
					//nếu người chơi click vào QUIT thì đóng cửa sổ, kết thúc game
					window.close();
					exit(0);
				}

			}
		default:
			break;
		}
	}
}
