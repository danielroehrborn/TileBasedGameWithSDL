#pragma once
#include <SDL.h>

class CollisionObject {
public:
	enum ObjectType { EventTrigger, Character, Warp, Obstacle, Accelerator };
	CollisionObject(ObjectType t, const SDL_Rect& gPos) {
		type = t;
		gridPos = gPos;
		vColObj.push_back(this);
	}
	/*~CollisionObject() {
		for (std::vector<CollisionObject*>::iterator it = vColObj.begin(); it != vColObj.end(); it++)
			if ((*it) == this)
				vColObj.erase(it);
	}*/
	ObjectType type;
	SDL_Rect gridPos;
	virtual void handleCollision(CollisionObject* other) = 0;
	static std::vector<CollisionObject*> vColObj;
	void checkForCollision();
};


class WarpData {
public:
	const SDL_Rect gridPos;
	const unsigned char targetMapID;
	const SDL_Rect targetPos;
};

/*class Warp :public CollisionObject {
	unsigned char targetMapID;
	SDL_Rect targetPos;
public:
	Warp(const SDL_Rect& gPos, unsigned char tMapID, const SDL_Rect& tPos) :CollisionObject(CollisionObject::Warp, gPos) {
		targetMapID = tMapID;
		targetPos = tPos;
	}
	void handleCollision(CollisionObject* other);
	void handleCollision(Warp* other);
	void handleCollision(Character* other);
};

class Character :public CollisionObject {
	void handleCollision(CollisionObject* other);
	void handleCollision(Warp* other);
	void handleCollision(Character* other);
};*/