#include "Ball.h"

Ball::Ball(Score* Score1, Score* Score2, Paddle* player1, Paddle* player2) {
	this->Load("ball.png"); // load hình ảnh vô texture 
	this->Score1 = Score1;
	this->Score2 = Score2;
	this->player1 = player1;
	this->player2 = player2;

	this->buffer = new SoundBuffer();
	this->buffer->loadFromFile("Sounds/bounce.wav");
	this->sound = new Sound(*this->buffer);

	this->owning = 0;
}
Ball::Ball(Score* Score1, Score* Score2, Paddle* player1, Paddle* player2, Paddle* rock1, Paddle* rock2, Paddle* rock3) {
	this->Load("ball.png"); // load hình ảnh vô texture 
	this->Score1 = Score1;
	this->Score2 = Score2;
	this->player1 = player1;
	this->player2 = player2;
	this->rock1 = rock1; // khởi tạo vật cản cho rock map
	this->rock2 = rock2;
	this->rock3 = rock3;

	this->buffer = new SoundBuffer();
	this->buffer->loadFromFile("Sounds/bounce.wav");
	this->sound = new Sound(*this->buffer);

	this->owning = 0;
}
Ball::Ball(Score* Score1, Score* Score2, Paddle* player1, Paddle* player2, Paddle* portal1, Paddle* portal2, Paddle* portal3, Paddle* portal4) {
	this->Load("ball.png"); // load hình ảnh vô texture 
	this->Score1 = Score1;
	this->Score2 = Score2;
	this->player1 = player1;
	this->player2 = player2;
	this->portal1 = portal1;
	this->portal2 = portal2;
	this->portal3 = portal3;
	this->portal4 = portal4;

	this->buffer = new SoundBuffer();
	this->buffer->loadFromFile("Sounds/bounce.wav");
	this->sound = new Sound(*this->buffer);

	this->owning = 0;
}
Ball::Ball(Score* Score1, Score* Score2, Paddle* player1, Paddle* player2, Paddle* fire1, Paddle* fire2, Paddle* fire3, Paddle* fire4, Paddle* FireGate) {
	this->Load("ball.png"); // load hình ảnh vô texture 
	this->Score1 = Score1;
	this->Score2 = Score2;
	this->player1 = player1;
	this->player2 = player2;

	this->FireGate = FireGate;
	this->fire1 = fire1;
	this->fire2 = fire2;
	this->fire3 = fire3;
	this->fire4 = fire4;

	this->buffer = new SoundBuffer();
	this->buffer->loadFromFile("Sounds/bounce.wav");
	this->sound = new Sound(*this->buffer);

	this->owning = 0;
}
void Ball::Reset(RenderWindow* window) {
	int angle;
	srand((int)time(0)); // random số khác nhau mỗi lần chạy
	do {
		angle = 5 + rand() % (355 + 1 - 5);  // random só từ 5 đến 355
	} while ((angle > 45 && angle < 135) || (angle > 225 && angle < 315) || (angle > 175 && angle < 185));	// giới hạn góc không quá thẳng đứng, không quá ngang
	this->velocity.x = 1.f* cos(angle * 3.14 / 180); // entity sẽ move theo velocity này
	this->velocity.y = 1.f* sin(angle * 3.14 / 180);

	this->owning = 0;

	this->setPosition(window->getSize().x / 2, window->getSize().y / 2); // đặt lại vị trí  trung tâm
	this->player1->setPosition(0, window->getSize().y / 2 - this->player1->getGlobalBounds().height / 2); // paddle 1 ở bên trái giữa màn hình
	this->player2->setPosition(window->getSize().x - this->player2->getGlobalBounds().width, window->getSize().y / 2 - this->player2->getGlobalBounds().height / 2); // paddle 2 ở bên phải giữa
}
void Ball::RockReset(RenderWindow* window) {
	int angle;
	do {
		angle = 5 + rand() % (355 + 1 - 5);  // random só từ 5 đến 355
	} while ((angle > 45 && angle < 135) || (angle > 225 && angle < 315) || (angle > 175 && angle < 185));	// giới hạn góc không quá thẳng đứng, không quá ngang
	this->velocity.x = 1.f* cos(angle * 3.14 / 180); // entity sẽ move theo velocity này
	this->velocity.y = 1.f* sin(angle * 3.14 / 180);

	this->owning = 0;

	this->setPosition(window->getSize().x / 2, window->getSize().y / 2); // đặt lại vị trí  trung tâm
	this->player1->setPosition(0, window->getSize().y / 2 - this->player1->getGlobalBounds().height / 2); // paddle 1 ở bên trái giữa màn hình
	this->player2->setPosition(window->getSize().x - this->player2->getGlobalBounds().width, window->getSize().y / 2 - this->player2->getGlobalBounds().height / 2); // paddle 2 ở bên phải giữa
	this->rock1->setPosition(window->getSize().x / 2 - 200, window->getSize().y / 2 - 200); // vật cản cho rock map ở phía trên bên phải
	this->rock2->setPosition(window->getSize().x / 2, window->getSize().y / 2 + 200); // vật cản cho rock map ở chính giữa bên dưới
	this->rock3->setPosition(window->getSize().x / 2 + 200, window->getSize().y / 2 - 200); //// vật cản cho rock map ở phía trên bên trái
}
void Ball::WindReset(RenderWindow* window) {
	int random;
	random = 1 + rand() % (4 + 1 - 1);  // random só từ 1 đến 4
	if (random == 1) {
		this->velocity.x = 1.f; // entity sẽ move theo velocity này
		this->velocity.y = 0.3f;
	}
	else if (random == 2) {
		this->velocity.x = -1.f; // entity sẽ move theo velocity này
		this->velocity.y = -0.3f;
	}
	else if (random == 3) {
		this->velocity.x = -1.f; // entity sẽ move theo velocity này
		this->velocity.y = 0.3f;
	}
	else {
		this->velocity.x = 1.f; // entity sẽ move theo velocity này
		this->velocity.y = -0.3f;
	}

	this->owning = 0;

	this->setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2);
	this->setPosition(window->getSize().x / 2, window->getSize().y / 2); // đặt lại vị trí  trung tâm
	this->player1->setPosition(0, window->getSize().y / 2 - this->player1->getGlobalBounds().height / 2); // paddle 1 ở bên trái giữa màn hình
	this->player2->setPosition(window->getSize().x - this->player2->getGlobalBounds().width, window->getSize().y / 2 - this->player2->getGlobalBounds().height / 2); // paddle 2 ở bên phải giữa
	this->portal1->setOrigin(this->portal1->getGlobalBounds().width / 2, this->portal1->getGlobalBounds().height / 2);
	this->portal2->setOrigin(this->portal2->getGlobalBounds().width / 2, this->portal2->getGlobalBounds().height / 2);
	this->portal3->setOrigin(this->portal3->getGlobalBounds().width / 2, this->portal3->getGlobalBounds().height / 2);
	this->portal4->setOrigin(this->portal4->getGlobalBounds().width / 2, this->portal4->getGlobalBounds().height / 2);
	this->portal1->setPosition(window->getSize().x / 2, 63);
	this->portal2->setPosition(window->getSize().x / 2, 190);
	this->portal3->setPosition(window->getSize().x / 2, 390);
	this->portal4->setPosition(window->getSize().x / 2, window->getSize().y - 63);
}
void Ball::FireReset(RenderWindow* window) {
	int angle;
	do {
		angle = 5 + rand() % (355 + 1 - 5);  // random só từ 5 đến 355
	} while ((angle > 45 && angle < 135) || (angle > 225 && angle < 315) || (angle > 175 && angle < 185));	// giới hạn góc không quá thẳng đứng, không quá ngang
	this->velocity.x = 1.f* cos(angle * 3.14 / 180); // entity sẽ move theo velocity này
	this->velocity.y = abs(1.f* sin(angle * 3.14 / 180));

	this->owning = 0;

	this->setPosition(window->getSize().x / 2 + 25, window->getSize().y / 2 + 25); // đặt lại vị trí  trung tâm
	this->player1->setPosition(199, window->getSize().y / 2 - this->player1->getGlobalBounds().height/2);
	this->player2->setPosition(574, window->getSize().y / 2  -this->player1->getGlobalBounds().height/2);

	this->fire1->setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2);
	this->fire2->setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2);
	this->fire3->setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2);
	this->fire4->setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2);
	this->FireGate->setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2);
	this->fire2->setRotation(90.f);
	this->fire2->rotate(0.f);
	this->fire3->setRotation(90.f);
	this->fire3->rotate(0.f);
	this->fire1->setPosition(100, 150);
	this->fire2->setPosition(100, 400);
	this->fire3->setPosition(700, 200);
	this->fire4->setPosition(700, 450);
	this->FireGate->setPosition(400, 200);
}
void Ball::Update(RenderWindow* window) {
	if (this->CheckCollision(this->player1)) {
		this->velocity.x *= 1.1f; // tăng tốc 10%
		this->velocity.y *= 1.1f;
		this->velocity.x *= -1; // nếu có va chạm với player 1  thì đổi hướng x
		this->sound->play(); // chạm bóng thì play sound
		this->owning = 1;
	}
	if (this->CheckCollision(this->player2)) {
		this->velocity.x *= 1.1f; // tăng tốc 10%
		this->velocity.y *= 1.1f;
		this->velocity.x *= -1; // nếu có va chạm với player 2 thì đổi hướng x
		this->sound->play(); // chạm bóng thì play sound
		this->owning = 2;
	}
	if (this->getPosition().y < 0 || this->getPosition().y + this->getGlobalBounds().height>Windows_Height) {
		this->velocity.y *= -1; // nếu chạm nóc hoắc đáy thì đổi hướng y
		this->sound->play(); // chạm bóng thì play sound
	}
	if (this->getPosition().x <= 0) { // chạm tường trái
		this->Score2->ScoreUp();
		this->Reset(window); // đặt lại vị trí trung tâm
	}
	if (this->getPosition().x > window->getSize().x) { // chạm tường phải
		this->Score1->ScoreUp();
		this->Reset(window); // đặt lại vị trí trung tâm
	}
	Entity::Update(); //move entity theo velocity
}
void Ball::RockUpdate(RenderWindow* window) {
	if (this->CheckCollision(this->player1)) { // nếu có va chạm với player 1  
		this->velocity.x *= 1.1f; // tăng tốc 10%
		this->velocity.y *= 1.1f;
		this->velocity.x *= -1; // đổi hướng x
		this->sound->play(); // chạm bóng thì play sound
		this->owning = 1;
	}
	if (this->CheckCollision(this->player2)) { // nếu có va chạm với player 2 
		this->velocity.x *= 1.1f; // tăng tốc 10%
		this->velocity.y *= 1.1f;
		this->velocity.x *= -1; // đổi hướng x
		this->sound->play(); // chạm bóng thì play sound
		this->owning = 2;
	}
	if (this->CheckCollision(this->rock1) || this->CheckCollision(this->rock2) || this->CheckCollision(this->rock3)) { // chạm phải vật cản rock
		this->velocity.x *= -1; // đổi hướng x
		this->sound->play(); // chạm bóng thì play sound
	}
	if (this->getPosition().y < 0 || this->getPosition().y + this->getGlobalBounds().height>Windows_Height) {
		this->velocity.y *= -1; // nếu chạm nóc hoắc đáy thì đổi hướng y
		this->sound->play(); // chạm bóng thì play sound
	}
	if (this->getPosition().x <= 0) { // chạm tường trái
		this->Score2->ScoreUp();
		this->RockReset(window); // đặt lại vị trí trung tâm
	}
	if (this->getPosition().x > window->getSize().x) { // chạm tường phải
		this->Score1->ScoreUp();
		this->RockReset(window); // đặt lại vị trí trung tâm
	}

	Entity::Update(); //move entity theo velocity
}
void Ball::WindUpdate(RenderWindow* window) {
	if (this->CheckCollision(this->player1)) {
		this->velocity.x *= 1.148f; // tăng tốc 14,8%
		this->velocity.x *= -1; // nếu có va chạm với player 1  thì đổi hướng x
		this->sound->play(); // chạm bóng thì play sound
		this->owning = 1;
	}
	if (this->CheckCollision(this->player2)) {
		this->velocity.x *= 1.148f; // tăng tốc 14,8%
		this->velocity.x *= -1; // nếu có va chạm với player 2 thì đổi hướng x
		this->sound->play(); // chạm bóng thì play sound
		this->owning = 2;
	}
	if (this->CheckCollision(this->portal1)) { // chạm phải portal 1 thì đi ra từ portal 3
		if (this->owning == 1) {
			this->setPosition(window->getSize().x / 2 + 80, 390);
		}
		else {
			this->setPosition(window->getSize().x / 2 - 80, 390);
		}
		this->sound->play(); // chạm bóng thì play sound
	}
	if (this->CheckCollision(this->portal2)) { // chạm phải portal 2 thì đi ra từ portal 4
		if (this->owning == 1) {
			this->setPosition(window->getSize().x / 2 + 80, window->getSize().y - 63);
		}
		else {
			this->setPosition(window->getSize().x / 2 - 80, window->getSize().y - 63);
		}
		this->sound->play(); // chạm bóng thì play sound
	}
	if (this->CheckCollision(this->portal3)) { // chạm phải portal 3 thì đi ra từ portal 1
		if (this->owning == 1) {
			this->setPosition(window->getSize().x / 2 - 80, 63);
		}
		else {
			this->setPosition(window->getSize().x / 2 - 80, 63);
		}

		this->sound->play(); // chạm bóng thì play sound
	}
	if (this->CheckCollision(this->portal4)) { // chạm phải portal 4 thì đi ra từ portal 2
		if (this->owning == 1) {
			this->setPosition(window->getSize().x / 2 + 80, 190);
		}
		else {
			this->setPosition(window->getSize().x / 2 - 80, 190);
		}

		this->sound->play(); // chạm bóng thì play sound
	}
	if (this->getPosition().y < 0 || this->getPosition().y + this->getGlobalBounds().height>Windows_Height) {
		this->velocity.y *= -1; // nếu chạm nóc hoắc đáy thì đổi hướng y
		this->sound->play(); // chạm bóng thì play sound
	}
	if (this->getPosition().x <= 0) { // chạm tường trái
		this->Score2->ScoreUp();
		this->WindReset(window); // đặt lại vị trí trung tâm
	}
	if (this->getPosition().x > window->getSize().x) { // chạm tường phải
		this->Score1->ScoreUp();
		this->WindReset(window); // đặt lại vị trí trung tâm
	}
	Entity::Update(); //move entity theo velocity
}
void Ball::Bounce(float x, float y){  // dùng cho map fire
	if (x > 0)
		this->velocity.x *= -x;
	if (y > 0)
		this->velocity.y *= -y;
	this->sound->play();
}
void Ball::FireUpdate(RenderWindow* window) {
	if (this->CollisionSide(this->fire1, COL_LEFT) || this->CollisionSide(this->fire1, COL_RIGHT) || this->CollisionSide(this->fire2, COL_LEFT) || this->CollisionSide(this->fire2, COL_RIGHT) || this->CollisionSide(this->fire3, COL_LEFT) || this->CollisionSide(this->fire3, COL_RIGHT) || this->CollisionSide(this->fire4, COL_LEFT) || this->CollisionSide(this->fire4, COL_RIGHT)) {
		if (this->CollisionSide(this->fire1, COL_TOP) || this->CollisionSide(this->fire1, COL_BOTTOM) || this->CollisionSide(this->fire2, COL_TOP) || this->CollisionSide(this->fire2, COL_BOTTOM) || this->CollisionSide(this->fire3, COL_TOP) || this->CollisionSide(this->fire3, COL_BOTTOM) || this->CollisionSide(this->fire4, COL_TOP) || this->CollisionSide(this->fire4, COL_BOTTOM)) 
			this->Bounce(1, 1);
		else 
			this->Bounce(1, 0);
	}
	else if (this->CollisionSide(this->fire1, COL_TOP) || this->CollisionSide(this->fire1, COL_BOTTOM) || this->CollisionSide(this->fire2, COL_TOP) || this->CollisionSide(this->fire2, COL_BOTTOM) || this->CollisionSide(this->fire3, COL_TOP) || this->CollisionSide(this->fire3, COL_BOTTOM) || this->CollisionSide(this->fire4, COL_TOP) || this->CollisionSide(this->fire4, COL_BOTTOM)) 
		this->Bounce(0, 1);


	if (this->CollisionSide(this->player1, COL_LEFT) || this->CollisionSide(this->player1, COL_RIGHT)){
		this->velocity.x *= 1.1f; // tăng tốc 10%
		this->velocity.y *= 1.1f;
		this->owning = 1;
		if (this->CollisionSide(this->player1, COL_TOP) || this->CollisionSide(this->player1, COL_BOTTOM))
			this->Bounce(1, 1);
		else
			this->Bounce(1, 0);
	}
	else if (this->CollisionSide(this->player1, COL_TOP) || this->CollisionSide(this->player1, COL_BOTTOM)){
		this->Bounce(0, 1);
		this->owning = 1;
	}

	if (this->CollisionSide(this->player2, COL_LEFT) || this->CollisionSide(this->player2, COL_RIGHT)) {
		this->velocity.x *= 1.1f; // tăng tốc 10%
		this->velocity.y *= 1.1f;
		this->owning = 2;
		if (this->CollisionSide(this->player2, COL_TOP) || this->CollisionSide(this->player2, COL_BOTTOM))
			this->Bounce(1, 1);
		else
			this->Bounce(1, 0);
	}
	else if (this->CollisionSide(this->player2, COL_TOP) || this->CollisionSide(this->player2, COL_BOTTOM)) {
		this->Bounce(0, 1);
		this->owning = 2;
	}


	if (this->getPosition().y < 0 || this->getPosition().y + this->getGlobalBounds().height>Windows_Height) {
		this->velocity.y *= -1; // nếu chạm nóc hoắc đáy thì đổi hướng y
		this->sound->play(); // chạm bóng thì play sound
	}
	if (this->getPosition().x <= 0|| this->getPosition().x >= window->getSize().x - 40) { // chạm tường trái hoặc phải
		this->velocity.x *= -1; 
		this->sound->play(); // chạm bóng thì play sound
	}
	if (this->CheckCollision(this->FireGate)) { 
		if (this->owning == 1) {
			this->Score1->ScoreUp();
			this->FireReset(window);
		}
		else if (this->owning == 2) {
			this->Score2->ScoreUp();
			this->FireReset(window); 
		}
	}
	Entity::Update(); //move entity theo velocity
}
Ball::~Ball() {
	delete this->sound;
	delete this->buffer;
}
