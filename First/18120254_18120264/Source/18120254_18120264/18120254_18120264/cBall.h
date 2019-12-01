#ifndef _BALL_H_
#define _BALL_H_
#include <iostream>
#include <time.h>
#include <conio.h>
using namespace std;
enum eDir { STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6 };//Các di chuyển của bóng
class cBall
{
protected:
	int x, y; // Tọa độ bóng
	int prex, prey; // Tọa độ trước (dùng cho hiển thị)
	int originalX, originalY; //Vị trí gốc của bóng
	eDir direction; //Hướng di chuyển của bóng
	int velocity; //Vận tốc của bóng
public:
	cBall(int, int);//Constructor
	int getX(); // Lấy thuộc tính protected
	int getY();
	int getPreX();
	int getPreY();
	eDir getDirection();
	void Reset();//Đặt lại bóng
	void changeDirection(eDir);//Đổi hướng di chuyển của bóng
	void randomDirection();//Ngâu nhiên hướng di chuyển của bóng
	void Move();//Di chuyển bóng (thay đổi tọa độ)
};
#endif