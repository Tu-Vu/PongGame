#include "DoHoa.h"
// Hàm thay đổi kích cỡ của khung cmd. Tham số truyền vào là chiều cao, chiều rộng.
void resizeConsole(int Width, int Height){
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle
	SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size
	SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size
}
// Hàm tô màu. Tham số truyền vào là mã màu
void textcolor(int color){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
// Hàm dịch chuyển con trỏ đến tọa độ x, y. Tham số truyền vào là tọa độ 
void gotoxy(int column, int line){
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
// Hàm xóa màn hình.
void clrscr(){
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0,0 };
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}
// Hiển thị Menu
void Menu(bool &play){
	textcolor(ColorCode_Yellow);
	cout << R"(
                                           ______                   
                                          / ________ _____ ___  ___ 
                                         / / __/ __ `/ __ `__ \/ _ \
                                        / /_/ / /_/ / / / / / /  __/
                                        \____/\__,_/_/ /_/ /_/\___/      
)";
	textcolor(ColorCode_Red);
	cout << R"(                 
                  __  ___         ___         ___                         __    ___         ___     
         _____   /_/ /  /\       /__/\       /  /\                 _____  \_\  /  /\       /__/\    
        /  /::\     /  /::\      \  \:\     /  /:/_               /  /::\     /  /::\      \  \:\   
       /  /:/\:\   /  /:/\:\      \  \:\   /  /:/ /\             /  /:/\:\   /  /:/\:\      \  \:\  
      /  /:/~/::\ /  /:/  \:\ _____\__\:\ /  /:/_/::\           /  /:/~/::\ /  /:/~/::\ _____\__\:\ 
     /__/:/ /:/\:/__/:/ \__\:/__/::::::::/__/:/__\/\:\         /__/:/ /:/\:/__/:/ /:/\:/__/::::::::\
     \  \:\/:/~/:\  \:\ /  /:\  \:\~~\~~\\  \:\ /~~/:/         \  \:\/:/~/:\  \:\/:/__\\  \:\~~\~~\/
      \  \::/ /:/ \  \:\  /:/ \  \:\  ~~~ \  \:\  /:/           \  \::/ /:/ \  \::/     \  \:\  ~~~ 
       \  \:\/:/   \  \:\/:/   \  \:\      \  \:\/:/             \  \:\/:/   \  \:\      \  \:\     
        \  \::/     \  \::/     \  \:\      \  \::/               \  \::/     \  \:\      \  \:\    
         \__\/       \__\/       \__\/       \__\/                 \__\/       \__\/       \__\/    
)" << endl;
	bool thoat = false;
	char c = '0';
	int luachon = 2;
	while ((play == false) && (thoat == false)){
		textcolor(ColorCode_Green);

		gotoxy(42, 35);
		cout << "Bam <W> hoac <S> de di chuyen";

		textcolor(ColorCode_White);
		gotoxy(52, 25); // 52 19
		cout << "BAT DAU";
		gotoxy(53, 27);  // 52 21
		cout << "THOAT";
		while (c != char(13)){ // ENTER
			textcolor(ColorCode_Green);
			gotoxy(49, 25 + luachon);
			cout << "->";  // mui ten lua chon
			gotoxy(60, 25 + luachon);
			cout << "<-";
			gotoxy(0, 0);
			c = _getch();
			gotoxy(49, 25 + luachon); // xoa mui ten
			cout << "  ";
			gotoxy(60, 25 + luachon); // xoa mui ten
			cout << "  ";
			if (c == 's' || c == 'S'){
				if (luachon < 2)
					luachon += 2;
			}
			if (c == 'w' || c == 'W'){
				if (luachon > 0)
					luachon -= 2;
			}
		}
		if (luachon == 0)
			play = true;
		if (luachon == 2){
			play = false;
			thoat = true;
		}
		luachon = 2;
		c = ' ';
		system("cls");
	}
}




