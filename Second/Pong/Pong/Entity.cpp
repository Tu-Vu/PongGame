#include "Entity.h"



Entity::Entity()
{
	this->texture = new Texture();
}


Entity::~Entity()
{
	delete this->texture;
}
void Entity::Load(string filename) {
	this->texture->loadFromFile("Graphics/Sprites/" + filename);
	this->setTexture(*this->texture);
}
void Entity::Update() {
	this->move(this->velocity);
}
bool Entity::CheckCollision(Entity* entity) {
	return this->getGlobalBounds().intersects(entity->getGlobalBounds());
}