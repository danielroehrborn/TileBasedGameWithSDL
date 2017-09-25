#pragma once
#include <list>
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
	//static void checkCollision(Sprite* s);
	static void clearEventList();
	virtual Event* clone() const = 0;
	//private:
	SDL_Rect* gridPos;
	SDL_Rect uniquePos;
	Sprite* assignedSprite;
	char waitBefore, waitAfter;
	static std::vector<Event*> vEvents;
};

class EventManagement {
public:
	class ActivatedEvent {
	public:
		ActivatedEvent(Event* event, Sprite* param) {
			this->event = event->clone();
			this->param = param;
		}
		~ActivatedEvent() {
			delete event;
		}
		Event* event;
		Sprite* param;
		bool executed = false;
	};
	static Event* addEvent(Event* newEvent, bool runNow = true, Sprite* param = NULL) {
		lEvents.push_back(newEvent);
		if (runNow) {
			activateEvent(newEvent, param);
		}
		return newEvent;
	}
	static void checkCollision(Sprite* s) {
		Sprite* sTmp;
		for (std::list<Event*>::iterator it = lEvents.begin(); it != lEvents.end(); ++it) {
			sTmp = (*it)->assignedSprite;
			if ((sTmp != NULL && sTmp != s && s->gridPos.x == sTmp->gridPos.x && s->gridPos.y == sTmp->gridPos.y) ||
				(sTmp == NULL && s->gridPos.x == (*it)->uniquePos.x && s->gridPos.y == (*it)->uniquePos.y))
				activateEvent(*it, s);
		}
	}
	static void activateEvent(Event* e, Sprite* s, unsigned char queueID = 0) {
		lEventActivationQueues[queueID].push(new ActivatedEvent(e, s));
	}
	static void delEvent(Event* e) {
		lEvents.erase(std::find(lEvents.begin(), lEvents.end(), e));
		delete e;
	}
	static void delAllEvents() {
		for (std::list<Event*>::iterator it = lEvents.begin(); it != lEvents.end(); ++it)
			delete *it;
		lEvents.clear();
	}
	static std::list<Event*> lEvents;
	static std::queue<ActivatedEvent*> lEventActivationQueues[4];
	static void RunNextEvent() {
		for (unsigned char i = 0; i < 4; ++i) {
			if (lEventActivationQueues[i].size() > 0) {
				ActivatedEvent* curEv = lEventActivationQueues[i].front();
				if (curEv->event->waitBefore) --curEv->event->waitBefore;
				else if (!curEv->executed++)
					curEv->event->handleCollision(curEv->param);
				else if (curEv->event->waitAfter) --curEv->event->waitAfter;
				else {
					lEventActivationQueues[i].pop();
					delete curEv;
				}
			}
		}
	}
private:
	EventManagement() {};
};
/*class ActiveEvent {
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
};*/

extern void WarpSprite(Sprite* s, unsigned char destMapID, char destX, char destY);
class WarpEvent :public Event {
public:
	WarpEvent(char x, char y, unsigned char w, unsigned char h,
		unsigned char destMapID, char destX, char destY, char wBefore = 0, char wAfter = 0) :Event(x, y, w, h, wBefore, wAfter) {
		this->destMapID = destMapID;
		destPos = { destX,destY,0,0 };
	}
	WarpEvent(Sprite* s, unsigned char destMapID, char destX, char destY, char wBefore = 0, char wAfter = 0) :Event(s, wBefore, wAfter) {
		this->destMapID = destMapID;
		destPos = { destX,destY,0,0 };
	}
	void handleCollision(Sprite* s) {
		if (s == NULL) {
			printf("Warpevent ohne Sprite gestartet\n"); return;
		}
		printf("WarpEvent collision: Map%d, x%d, y%d\n", destMapID, destPos.x, destPos.y);
		WarpSprite(s, destMapID, destPos.x, destPos.y);
	}
	WarpEvent* clone() const {
		if (assignedSprite != NULL)
			return new WarpEvent(assignedSprite, destMapID, destPos.x, destPos.y, waitBefore, waitAfter);
		return new WarpEvent(uniquePos.x, uniquePos.y, uniquePos.w, uniquePos.h, destMapID, destPos.x, destPos.y, waitBefore, waitAfter);
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

class StateMachineTriggerEvent :public Event {
public:
	class MapScriptState {
	public:
		virtual void init() = 0;
		virtual void exit() = 0;
		virtual void handleEvents() = 0;
		static void changeState(unsigned char mapID, MapScriptState* newState) {
			if (mapScriptStates[mapID] != NULL) {
				mapScriptStates[mapID]->exit();
				delete mapScriptStates[mapID];
			}
			mapScriptStates[mapID] = newState;
			newState->init();
		}
		static MapScriptState* mapScriptStates[];
	};
	StateMachineTriggerEvent(char x, char y, unsigned char mapID, unsigned char eventFlagBitIndex) :Event(x, y, 0, 0, 0, 0) {
		this->eventFlagBitIndex = eventFlagBitIndex;
		this->mapID = mapID;
	}
	StateMachineTriggerEvent(Sprite* s, unsigned char mapID, unsigned char eventFlagBitIndex) :Event(s, 0, 0) {
		this->eventFlagBitIndex = eventFlagBitIndex;
		this->mapID = mapID;
	}
	void handleCollision(Sprite* s) {
		printf("Event\n");
		if (assignedSprite != NULL) assignedSprite->objectInUse = false;
		mapEventFlagBitmap[mapID] |= 1 << eventFlagBitIndex;
		if (MapScriptState::mapScriptStates[mapID] != NULL)
			MapScriptState::mapScriptStates[mapID]->handleEvents();
	}
	StateMachineTriggerEvent* clone() const { 
		if (assignedSprite != NULL)
			return new StateMachineTriggerEvent(assignedSprite, mapID, eventFlagBitIndex);
		return new StateMachineTriggerEvent(uniquePos.x, uniquePos.y, mapID, eventFlagBitIndex);
	}
	static unsigned int mapEventFlagBitmap[];
	unsigned char mapID;
private:
	unsigned char eventFlagBitIndex;
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