#include <stdio.h>
#include <queue>
#include "Event.h"

extern unsigned const char bghoehe, bgbreite;
extern unsigned char bgTiles[];
extern unsigned char bgWalk[];
extern SDL_Texture *tilemapTexture;

void ChangeBGTileEvent::handleCollision(Sprite* s) {
	bgTiles[8 * bgbreite + tileGridY * bgbreite + 8 + tileGridX] = tileData;
	bgWalk[8 * bgbreite + tileGridY * bgbreite + 8 + tileGridX] = walkData;
}
void ChangeTimeEvent::handleCollision(Sprite* s) {
	SDL_SetTextureColorMod(tilemapTexture, colRed, colGreen, colBlue);
}

//std::vector<Event*> Event::vEvents;

//std::queue<ActiveEvent> ActiveEvent::vEventActivationQueue;

std::list<Event*> EventManagement::lEvents;
std::queue<EventManagement::ActivatedEvent*> EventManagement::lEventActivationQueues[4];

unsigned int StateMachineTriggerEvent::mapEventFlagBitmap[10];
StateMachineTriggerEvent::MapScriptState* StateMachineTriggerEvent::MapScriptState::mapScriptStates[10];

/*void Event::checkCollision(Sprite* s) {
	Sprite* sTmp;
	for (std::vector<Event*>::iterator it = vEvents.begin(); it != vEvents.end(); ++it) {
		sTmp = (*it)->assignedSprite;
		if (sTmp != NULL && sTmp != s && s->gridPos.x == sTmp->gridPos.x && s->gridPos.y == sTmp->gridPos.y) {
			new ActiveEvent(*it, s, 0, 0);
			//return; mehrere an selber stelle
		}
		else if (sTmp == NULL && s->gridPos.x == (*it)->uniquePos.x && s->gridPos.y == (*it)->uniquePos.y) {
			new ActiveEvent(*it, s, 0, 0);
			//return;
		}
	}
}*/

void Event::handleCollision(Sprite* s) {
	printf("Default handler\n");
}

/*void Event::clearEventList() {
	for (std::vector<Event*>::iterator it = vEvents.begin(); it != vEvents.end(); ++it) {
		delete *it;
	}
	vEvents.clear();
}*/

extern std::vector<Sprite*> vSprites;
Event* EventManagement::addEvent(Event* newEvent, bool runNow, Sprite* param, unsigned char queueID, bool checkCollisionNow) {
	lEvents.push_back(newEvent);
	if (runNow) {
		activateEvent(newEvent, param, queueID);
	}
	if (checkCollisionNow) {
		for (std::vector<Sprite*>::iterator it = vSprites.begin(); it != vSprites.end(); ++it) {
			if (checkCollision(*it, newEvent))
				activateEvent(newEvent, *it);
		}
	}
	return newEvent;
}