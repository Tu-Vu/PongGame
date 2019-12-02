#ifndef _ENTITY_H_
#define _ENTITY_H_
#include <SFML/Graphics.hpp>
using namespace sf;
#include <string>
using namespace std;
class Entity: public Sprite // class sprite cho phep ve va render cac object
{
protected:
	Vector2f velocity;
private:
	Texture* texture;
public:
	Entity();
	~Entity();
	void Load(string filename);
	virtual void Update();
	bool CheckCollision(Entity* entity);
};
#endif

