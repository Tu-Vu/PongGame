#include "cGameManger.h"
int main()
{
	bool play = false;
	resizeConsole(800, 600);//Vẽ màn hình trước khi vào game // windows width 105, height 50
	cGameManger gameplay(80, 40);//Set dài rộng cho khung
	Menu(play);
	if (play == true)
		gameplay.Run();
	else
		return 0;
}