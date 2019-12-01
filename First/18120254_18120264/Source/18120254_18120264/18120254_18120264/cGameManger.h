#ifndef _GAME_H_
#define _GAME_H_
#include "cBall.h"
#include "cPaddle.h"
#include "DoHoa.h"
class cGameManger{
protected:
	int width, height;//Chiều rộng, Chiều cao của game
	char up1, down1, up2, down2;//Các nút điều khiển
	bool quit;//Điều kiện để thoát game
	int score1, score2; // Điểm số
	cBall *ball; // Bóng
	cPaddle *player1; // Thanh điều khiển
	cPaddle *player2; 
public:
	cGameManger(int, int); // Hàm tạo
	~cGameManger(); // Hàm hủy
	void ScoreUp(cPaddle*); // Cộng điểm
	void DrawBorder(); // Vẽ khung xung quanh
	void Draw(); // Vẽ bóng và thanh điều khiển
	void Input(); // Nhận sự kiện từ bàn phím
	void Logic(); // Xử lý va chạm
	void Run(); // Chạy game
	void CleanPaddle(); // Xóa thanh điều khiển sau khi kết thúc game 
};
#endif
