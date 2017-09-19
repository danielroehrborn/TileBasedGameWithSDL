#pragma once
#include <SDL.h>
#include "Sprite.h"
unsigned char bgTiles[];
class Event {
public:
	Event(char x, char y, unsigned char w, unsigned char h, char wBefore = 0, char wAfter = 0) {
		uniquePos = { x,y,w,h };
		gridPos = &uniquePos;
		assignedSprite = NULL;
		vEvents.push_back(this);
		waitBefore = wBefore;
		waitAfter = wAfter;
		bgTiles[gridPos->x + 8 + (gridPos->y + 8) * 100] = 0;
	}
	Event(Sprite* s, char wBefore = 0, char wAfter = 0) {
		gridPos = &s->gridPos;
		assignedSprite = s;
		vEvents.push_back(this);
		waitBefore = wBefore;
		waitAfter = wAfter;
		bgTiles[gridPos->x + 8 + (gridPos->y + 8) * 100] = 0;
	}
	virtual void handleCollision(Sprite* s) = 0;
	static void checkCollision(Sprite* s);
	static void clearEventList();
	//private:
	SDL_Rect* gridPos;
	SDL_Rect uniquePos;
	Sprite* assignedSprite;
	char waitBefore, waitAfter;
	static std::vector<Event*> vEvents;
};

class ActiveEvent {
public:
	ActiveEvent(Event* ev, Sprite* s, unsigned char wBefore, unsigned char wAft) {
		e = ev;
		param = s;
		waitBefore = wBefore;
		waitAfter = wAft;
		vEventActivationQueue.push(*this);
	}
	Event* e;
	char waitBefore, waitAfter;
	Sprite* param;

	static std::queue<ActiveEvent> vEventActivationQueue;
	static void RunNextEvent() {
		if (vEventActivationQueue.size() == 0) return;
		ActiveEvent* curActEv = &vEventActivationQueue.front();
		if (curActEv->waitBefore) --curActEv->waitBefore;
		else if (curActEv->e != NULL) {
			curActEv->e->handleCollision(curActEv->param);
			curActEv->e = NULL;
		}
		else if (curActEv->waitAfter) --curActEv->waitAfter;
		else vEventActivationQueue.pop();
	}
};


extern void WarpSprite(Sprite* s, unsigned char destMapID, char destX, char destY);
class WarpEvent :public Event {
public:
	WarpEvent(char x, char y, unsigned char w, unsigned char h,
		unsigned char destMapID, char destX, char destY) :Event(x, y, w, h) {
		this->destMapID = destMapID;
		destPos = { destX,destY,0,0 };
	}
	WarpEvent(Sprite* s, unsigned char destMapID, char destX, char destY) :Event(s) {
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

class ChangeMapEvent :public Event {

};

class ChangeAnimEvent :public Event {
public:
	ChangeAnimEvent(char x, char y, unsigned char numAnims, const unsigned char* const * anims, char wBefore, char wAfter) :Event(x, y, 0, 0, wBefore, wAfter) {
		this->numAnims = numAnims;
		this->anims = anims;
	}
	ChangeAnimEvent(Sprite* s, unsigned char numAnims, const unsigned char* const * anims, char wBefore, char wAfter) :Event(s, wBefore, wAfter) {
		this->numAnims = numAnims;
		this->anims = anims;
	}
	void handleCollision(Sprite* s) {
		if (assignedSprite != NULL) s = assignedSprite;
		if (numAnims == 1)
			s->pushAnim(*anims[0]);
		else
			s->pushAnim(numAnims, *anims);
	}
private:
	unsigned char numAnims;
	const unsigned char* const * anims;
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