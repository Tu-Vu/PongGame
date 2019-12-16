#ifndef _ENTITY_H_
#define _ENTITY_H_
#include <SFML/Graphics.hpp>
using namespace sf;
#include <string>
using namespace std;

typedef enum { COL_TOP = 0, COL_BOTTOM = 1, COL_LEFT = 2, COL_RIGHT = 3 } COLLISION_DIRECTION; // check va chạm phức tạp, dùng cho fire map


class Entity: public Sprite{ // class sprite cho phép vẽ và render các object
protected:
	Texture* texture; // texture cho 1 entity
	Vector2f velocity; // vận tốc của 1 entity
public:
	Entity(); // hàm tạo
	~Entity(); // hàm hủy
	void Load(string filename); // load hình cho texture
	virtual void Update(); // update chuyển động cho entity
	bool CheckCollision(Entity* entity); // kiểm tra va chạm của entity này với entity được truyền vào
	bool CollisionSide(Entity* entity, COLLISION_DIRECTION side); // check va chạm phức tạp, dùng cho fire map
};
#endif

