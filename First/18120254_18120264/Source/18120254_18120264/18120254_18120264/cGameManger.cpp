#include "cGameManger.h"
cGameManger::cGameManger(int w, int h) {
	srand(time(NULL));//Khởi tạo cho các giá trị random
	quit = false;
	up1 = 'w'; up2 = 72;//72 là nút lên
	down1 = 's'; down2 = 80;//80 làn út xuống trong bảng mã ASCII
	width = w; height = h;
	score1 = score2 = 0;
	ball = new cBall(w / 2, h / 2);
	player1 = new cPaddle(2, h / 2);
	player2 = new cPaddle(w - 2, h / 2);
}
cGameManger::~cGameManger() {
	delete ball, player1, player2;
}
void cGameManger::ScoreUp(cPaddle* player) {
	if (player == player1)
		score1++;
	else if (player == player2)
		score2++;
	ball->Reset();
	player1->Reset();
	player2->Reset();
}
void cGameManger::DrawBorder() {
	// ve thanh ngang ben tren
	for (int i = 0; i <= width; i++) {
		gotoxy(i, 0); textcolor(ColorCode_Green); cout << "\xB2";
	}
	// ve thanh doc trai
	for (int i = 1; i < height; i++) {
		gotoxy(0, i); textcolor(ColorCode_Green); cout << "\xB2";
	}
	// ve thanh doc phai
	for (int i = 1; i < height; i++) {
		gotoxy(width, i); textcolor(ColorCode_Green); cout << "\xB2";
	}
	// ve thanh ngang duoi
	for (int i = 0; i <= width; i++) {
		gotoxy(i, height); textcolor(ColorCode_Green); cout << "\xB2";
	}
}
void cGameManger::Draw() {
	int ballx = ball->getX();
	int bally = ball->getY();
	int prex = ball->getPreX();
	int prey = ball->getPreY();
	gotoxy(prex, prey); textcolor(ColorCode_Yellow); cout << " ";
	gotoxy(ballx, bally); textcolor(ColorCode_Yellow); cout << "O";

	int player1x = player1->getX();
	int player1y = player1->getY();
	int p1prex = player1->getPreX();
	int p1prey = player1->getPreY();
	int checkup1;
	if (p1prey > player1y) 
		checkup1 = 1;
	else if (p1prey < player1y) 
		checkup1 = 0;
	else
		checkup1 = 2;
	for (int i = -4; i <=4; i++) {
		gotoxy(player1x, player1y + i); textcolor(ColorCode_Green); cout << "\xDB";
	}
	if (checkup1 == 1) { // di len
		gotoxy(p1prex, p1prey + 4); textcolor(ColorCode_Green); cout << " ";
	}
	else if (checkup1 == 0) { // di xuong
		gotoxy(p1prex, p1prey - 4); textcolor(ColorCode_Green); cout << " ";
	}
	
	int player2x = player2->getX();
	int player2y = player2->getY();
	int p2prex = player2->getPreX();
	int p2prey = player2->getPreY();
	int checkup2;
	if (p2prey > player2y)
		checkup2 = 1;
	else if (p2prey < player2y)
		checkup2 = 0;
	else
		checkup2 = 2;
	for (int i = -4; i <= 4; i++) {
		gotoxy(player2x, player2y + i); textcolor(ColorCode_Green); cout << "\xDB";
	}
	if (checkup2 == 1) { // di len
		gotoxy(p2prex, p2prey + 4); textcolor(ColorCode_Green); cout << " ";
	}
	else if (checkup2 == 0) { // di xuong
		gotoxy(p2prex, p2prey - 4); textcolor(ColorCode_Green); cout << " ";
	}

	gotoxy(3, 43); textcolor(ColorCode_Yellow); cout << "SCORE 1: " << score1 << endl;
	gotoxy(67, 43); textcolor(ColorCode_Yellow); cout << "SCORE 2: " << score2 << endl;
	gotoxy(3, 45); textcolor(ColorCode_DarkYellow); cout << "                        ";
	gotoxy(3, 47); textcolor(ColorCode_DarkGreen); cout << "                                            ";
}
void cGameManger::Input() {
	// goi den direction cua ball
	ball->Move();

	int player1x = player1->getX();
	int player1y = player1->getY();
	int player2x = player2->getX();
	int player2y = player2->getY();

	//Lấy các sự kiện điều khiển
	if (_kbhit()){
		char current = _getch(); // phim nhan cua nguoi choi
		if (current == up1) {
			if (player1y - 4 > 1)
				player1->moveUp();
		}
		if (current == up2) {
			if (player2y - 4 > 1)
				player2->moveUp();
		}
		if (current == down1) {
			if (player1y + 4 < height - 1) 
				player1->moveDown();
		}
		if (current == down2) {
			if (player2y + 4 < height - 1)
				player2->moveDown();
		}
		// luc bat dau thi cho random huong
		if (ball->getDirection() == STOP)
			ball->randomDirection();
		// thoat game
		if (current == 'q' || current == 'Q')
			quit = true;
	}
}
void cGameManger::CleanPaddle() {
	for (int i=1;i<height;i++) {
		gotoxy(2,i); cout << " ";
	}
	for (int i = 1; i < height; i++) {
		gotoxy(width-2, i); cout << " ";
	}
}
void cGameManger::Logic() {
	int ballx = ball->getX();
	int bally = ball->getY();

	int player1x = player1->getX();
	int player1y = player1->getY();
	int player2x = player2->getX();
	int player2y = player2->getY();

	//left paddle
	for (int i = -4; i <= 4; i++) {
		if (ballx == player1x + 1) {
			if (bally == player1y + i) {
				if (bally < player1y) {
					ball->changeDirection((eDir)(5)); // upright
				}
				else if (bally > player1y) {
					ball->changeDirection((eDir)(6)); //downright
				}
				else if (bally == player1y) {
					ball->changeDirection((eDir)(4)); //right
				}
			}
		}
	}
	//right paddle
	for (int i = -4; i <= 4; i++) {
		if (ballx == player2x - 1) {
			if (bally == player2y + i) {
				if (bally > player2y) {
					ball->changeDirection((eDir)(3));  //downleft
				}
				else if (bally < player2y) {
					ball->changeDirection((eDir)(2)); //upleft
				}
				else if (bally == player2y) {
					ball->changeDirection((eDir)(1));  //left
				}
			}
		}
	}
	//bottom wall
	if (bally == height - 1)
		ball->changeDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);//Chạm tường trên thì đổi chiều
	//top wall
	if (bally == 1)
		ball->changeDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);
	//right wall
	if (ballx == width - 1) {
		ScoreUp(player1);
		CleanPaddle();
		gotoxy(3, 45); textcolor(ColorCode_DarkYellow); cout << "Nguoi choi 1 chien thang";
		gotoxy(3, 47); textcolor(ColorCode_DarkGreen); cout << "Bam <Q> de thoat. Bam <ENTER> de choi tiep";
		char c = _getch();
		if (c == 'Q' || c == 'q')
			quit = true;
	}
	//left wall
	if (ballx == 1) {
		ScoreUp(player2);
		CleanPaddle();
		gotoxy(3, 45); textcolor(ColorCode_DarkYellow); cout << "Nguoi choi 2 chien thang";
		gotoxy(3, 47); textcolor(ColorCode_DarkGreen); cout << "Bam <Q> de thoat. Bam <ENTER> de choi tiep";
		char c = _getch();
		if (c == 'Q' || c == 'q')
			quit = true;
	}
}
void cGameManger::Run() {
	DrawBorder(); // Vẽ khung
	while (!quit){
		Draw(); //Vẽ đồ họa
		Input();//Các kí tự nhập khi chơi game
		Logic();//Xử lý chuyển động của bóng
		Sleep(50);
	}
}