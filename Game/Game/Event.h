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

class WarpEvent :public Event {
public:
	void handleCollision(Sprite* s) {
		//if s!=representationSprite: warpSprite(s)
	}
private:
	void warpSprite(Sprite* s) {
		//relocate s nach dest
	}
	unsigned char destMapID;
	SDL_Rect* destPos;
};

class ChangeAnimEvent :public Event {
public:
	void handleCollision(Sprite* s) {
		//if s!=representationSprite && representationSprite!=NULL: 
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
