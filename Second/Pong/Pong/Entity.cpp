#include "Entity.h"

Entity::Entity(){
	this->texture = new Texture();
}
Entity::~Entity(){
	delete this->texture;
}
void Entity::Load(string filename) {
	this->texture->loadFromFile("Graphics/Sprites/" + filename);
	this->setTexture(*this->texture);
}
void Entity::Update() {
	this->move(this->velocity); // di chuyển entity theo vector velocity
}
bool Entity::CheckCollision(Entity* entity) {
	return this->getGlobalBounds().intersects(entity->getGlobalBounds()); // có va chạm (intersects) không
}


bool Entity::CollisionSide(Entity* entity, COLLISION_DIRECTION side){
	float x = this->getPosition().x - 10;
	float y = this->getPosition().y + this->getGlobalBounds().height / 2;
	switch (side){
	case COL_TOP: {
		x = this->getPosition().x + this->getGlobalBounds().width / 2;
		y = this->getPosition().y - 10;
		break; }
	case COL_BOTTOM: {
		x = this->getPosition().x + this->getGlobalBounds().width / 2;
		y = this->getPosition().y + this->getGlobalBounds().height + 10;
		break; }
	case COL_LEFT: {
		break; }
	case COL_RIGHT: {
		x += this->getGlobalBounds().width + (10 * 2);
		break; }
	}
	return entity->getGlobalBounds().contains(sf::Vector2f(x, y));
}