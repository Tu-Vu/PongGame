#include "WaterMap.h"



WaterMap::WaterMap(int Score1, int Score2) {
	this->prevalue1 = Score1;  // lưu lại điểm người chơi 1 từ element state
	this->prevalue2 = Score2; // lưu lại điểm người chơi 2 từ element state
}
void WaterMap::Initialize(RenderWindow* window) {
	this->Player1 = new PaddlePlayer(0); // tạo người chơi 1

	this->Player2 = new PaddlePlayer(1); // tạo người chơi 2

	this->font = new Font(); // setting font
	this->font->loadFromFile("Graphics/Nexa-Black.ttf");

	texture.loadFromFile("Graphics/Sprites/backgroundwater.png"); // load background
	background.setTexture(texture);

	this->Score1 = new Score(*font, 64U); // tạo score người chơi 1
	this->Score1->setPosition(window->getSize().x / 4, 10); // đặt vị trí
	this->Score1->value = this->prevalue1; // lấy lại điểm cũ

	this->Score2 = new Score(*font, 64U); // tạo score người chơi 2
	this->Score2->setPosition(window->getSize().x / 1.4, 10); // đặt vị trí
	this->Score2->value = this->prevalue2; // lấy lại điểm cũ


	this->BallObject = new Ball(this->Score1, this->Score2, this->Player1, this->Player2); // tạo bóng
	this->BallObject->Reset(window); // reset (set) bóng ở chính giữa màn hình, paddle 1 ở bên trái giữa màn hình, paddle 2 ở bên phải giữa

	for (int i = 0; i < 5; i++) { // tạo ngẫu nhiên các vật phẩm cộng 1 điểm
		this->FoodObject[i] = new Food(this->Score1, this->Score2, this->BallObject);
		this->FoodObject[i]->WaterReset(window); // đặt vị trí
	}
	for (int i = 0; i < 7; i++) { // tạo ngẫu nhiên các vật phẩm cộng 2 điểm
		this->Food2Object[i] = new Food(this->Score1, this->Score2, this->BallObject,1);
		this->Food2Object[i]->WaterReset(window); // đặt vị trí
	}
	for (int i = 0; i < 4; i++) { // tạo ngẫu nhiên các vật phẩm trừ 2 điểm
		this->PoisonObject[i] = new Food(this->Score1, this->Score2, this->BallObject,2);
		this->PoisonObject[i]->WaterReset(window); // đặt vị trí
	}
}
void WaterMap::Update(RenderWindow* window) {
	this->Player1->Update(); // update sự kiện người chơi 1
	this->Player2->Update(); // update sự kiện người chơi 2
	this->BallObject->Update(window); // update bóng
	this->Score1->Update(); // update điểm người chơi 1
	this->Score2->Update(); // update điểm người chơi 2
	for (int i = 0; i < 5; i++) { // update vật phẩm cộng 1 điểm
		if (this->FoodObject[i]->eaten == false) { // nếu vật phẩm chưa bị ăn
			this->FoodObject[i]->Update(); // update sự kiện vật phẩm
		}
		else if (this->FoodObject[i]->eaten == true) { // nếu vật phẩm đã bị ăn
			delete this->FoodObject[i]; // xóa vật phẩm
			this->FoodObject[i] = new Food(this->Score1, this->Score2, this->BallObject); // tạo lại vật phẩm ở 1 vị trí random mới
			this->FoodObject[i]->WaterReset(window); // đặt vị trí
		}
	}
	for (int i = 0; i < 7; i++) { // update vật phẩm cộng 2 điểm
		if (Food2Object[i]->eaten == false) { // nếu vật phẩm chưa bị ăn
			this->Food2Object[i]->Food2Update(); // update sự kiện vật phẩm
		}
		else if (Food2Object[i]->eaten == true) { // nếu vật phẩm đã được ăn
			delete this->Food2Object[i];  // xóa vật phẩm
			this->Food2Object[i] = new Food(this->Score1, this->Score2, this->BallObject,1); // tạo lại vật phẩm ở 1 vị trí random mới
			this->Food2Object[i]->WaterReset(window);  // đặt vị trí
		}
	}
	for (int i = 0; i < 4; i++) { // update vật phẩm trừ 2 điểm
		if (PoisonObject[i]->eaten == false) { // nếu vật phẩm chưa bị ăn
			this->PoisonObject[i]->PoisonUpdate();  // update sự kiện vật phẩm
		}
		else if (PoisonObject[i]->eaten == true) { // nếu vật phẩm đã được ăn
			delete this->PoisonObject[i]; // xóa vật phẩm
			this->PoisonObject[i] = new Food(this->Score1, this->Score2, this->BallObject,2); // tạo lại vật phẩm ở 1 vị trí random mới
			this->PoisonObject[i]->WaterReset(window);  // đặt vị trí
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) {  // nếu ấn thoát thì quay về menu
		this->SaveGame(); // lưu game
		coreState.SetState(new InGameMenu(Score1->value, Score2->value));
	}
}
void WaterMap::Render(RenderWindow* window) { // vẽ các object có trong trò chơi
	window->draw(this->background);
	window->draw(*this->BallObject);
	for (int i = 0; i < 5; i++) {
		if (this->FoodObject[i]->eaten == false) {
			window->draw(*this->FoodObject[i]);
		}
	}
	for (int i = 0; i < 7; i++) {
		if (Food2Object[i]->eaten == false) {
			window->draw(*this->Food2Object[i]);
		}
	}
	for (int i = 0; i < 4; i++) {
		if (PoisonObject[i]->eaten == false) {
			window->draw(*this->PoisonObject[i]);
		}
	}
	window->draw(*this->Player1);
	window->draw(*this->Player2);
	window->draw(*this->Score1);
	window->draw(*this->Score2);

}
void WaterMap::Destroy(RenderWindow* window) { // hàm hủy
	delete this->Player1;
	delete this->Player2;
	delete this->BallObject;
	delete this->Score1;
	delete this->Score2;
}

void WaterMap::SaveGame()
{
	ofstream writeFile;
	writeFile.open("Data/SaveGame.txt");
	if (writeFile.is_open())
	{
		writeFile << "1Player" << endl;
		writeFile << 2 << endl;
		writeFile << Score1->value << endl;
		writeFile << Score2->value << endl;
	}
	writeFile.close();
}
