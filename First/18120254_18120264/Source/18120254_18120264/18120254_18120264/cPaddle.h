#ifndef _PADDLE_H_
#define _PADDLE_H_
class cPaddle{
protected:
	int x, y;  // Tọa độ thanh
	int prex, prey;// Tọa độ trước (dùng cho hiển thị)
	int originalX, originalY;//Vị trí gốc của thanh
public:
	cPaddle(int posX, int posY);// Hàm tạo
	int getX(); // Lấy các thuộc tính protected
	int getY();
	int getPreX();
	int getPreY();
	void Reset(); // Đặt lại thanh
	void moveUp();//Di chuyển thanh lên (thay đổi tọa độ) 
	void moveDown();//Di chuyển thanh xuống (thay đổi tọa độ)
};
#endif
