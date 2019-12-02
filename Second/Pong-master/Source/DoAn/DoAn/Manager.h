#ifndef MANAGER_H_
#define MANAGER_H_

#include "Score.h"
#include "Menu.h"

#define WIN_SCORE 5

//tra ve 1 neu player1 thang, 2 neu player2 thang
int playWithPerson(RenderWindow& window);	

//tra ve 1 neu player1 thang, 2 neu player2 thang
//nguoi choi la player2
int playWithComputer(RenderWindow& window);

void runStartMenu(RenderWindow& window, int& mode);
void runResultMenu(RenderWindow& window, int& winner);




#endif // !MANAGER_H_




