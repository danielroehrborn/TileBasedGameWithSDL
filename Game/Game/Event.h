#pragma once
#include <SDL.h>
#include "Sprite.h"

class Event {
public:
	Event(unsigned char x, unsigned char y, unsigned char w, unsigned char h) {
		uniquePos = { x,y,w,h };
		gridPos = &uniquePos;
		immuneSprite = NULL;
		vEvents.push_back(this);
	}
	Event(Sprite* s) {
		gridPos = &s->gridPos;
		immuneSprite = s;
		vEvents.push_back(this);
	}
	virtual void handleCollision(Sprite* s) = 0;
	static void checkCollision(Sprite* s);
	static void clearEventList();
private:
	SDL_Rect* gridPos;
	SDL_Rect uniquePos;
	Sprite* immuneSprite;
	static std::vector<Event*> vEvents;
};

extern void WarpSprite(Sprite* s, unsigned char destMapID, unsigned char destX, unsigned char destY);
class WarpEvent :public Event {
public:
	WarpEvent(unsigned char x, unsigned char y, unsigned char w, unsigned char h,
		unsigned char destMapID, unsigned char destX, unsigned char destY) :Event(x, y, w, h) {
		this->destMapID = destMapID;
		destPos = { destX,destY,0,0 };
	}
	WarpEvent(Sprite* s, unsigned char destMapID, unsigned char destX, unsigned char destY) :Event(s) {
		this->destMapID = destMapID;
		destPos = { destX,destY,0,0 };
	}
	void handleCollision(Sprite* s) {
		printf("WarpEvent collision: Map%d, x%d, y%d\n", destMapID, destPos.x, destPos.y);
		WarpSprite(s, destMapID, destPos.x, destPos.y);
	}
private:
	unsigned char destMapID;
	SDL_Rect destPos;
};

class ChangeAnimEvent :public Event {
public:
	void handleCollision(Sprite* s) {
		//if representationSprite!=NULL: 
		//representationSprite add anims
	}
private:
	unsigned char numAnims;
	unsigned char* anims;
};

class ChangeBGTileEvent :public Event {
public:
	void handleCollision(Sprite* s) {
		//if s!=representationSprite: 
		//set bg data
	}
private:
	unsigned char bgTileIndex;
	unsigned char bgTileData;
	unsigned char bgWalkData;
};

class ChangeTimeEvent :public Event {
public:

private:
	void changeLight();
};
