#include "Entity.h"

Entity::Entity(){
	this->texture = new Texture(); //tạo texture mới
}
Entity::~Entity(){
	delete this->texture; // hủy
}
void Entity::Load(string filename) {
	this->texture->loadFromFile("Graphics/Sprites/" + filename); // load hình ảnh
	this->setTexture(*this->texture);
}
void Entity::Update() {
	this->move(this->velocity); // di chuyển entity theo vector velocity
}
bool Entity::CheckCollision(Entity* entity) {
	return this->getGlobalBounds().intersects(entity->getGlobalBounds()); // có va chạm (intersects) không
}


bool Entity::CollisionSide(Entity* entity, COLLISION_DIRECTION side){
	float x = this->getPosition().x - 10; // lấy vị trí x của entity
	float y = this->getPosition().y + this->getGlobalBounds().height / 2; // lấy vị trí x của entity
	switch (side){ // xem coi entity đang va chạm mặt nào
	case COL_TOP: { // va chạm phía trên
		x = this->getPosition().x + this->getGlobalBounds().width / 2;
		y = this->getPosition().y - 10;
		break; }
	case COL_BOTTOM: { // va chạm phía dưới
		x = this->getPosition().x + this->getGlobalBounds().width / 2;
		y = this->getPosition().y + this->getGlobalBounds().height + 10;
		break; }
	case COL_LEFT: { // va trái
		break; }
	case COL_RIGHT: { // va phải
		x += this->getGlobalBounds().width + (10 * 2);
		break; }
	}
	return entity->getGlobalBounds().contains(sf::Vector2f(x, y)); //trả về xem x,y có trong entity không
}