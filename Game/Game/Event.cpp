#include <stdio.h>
#include <queue>
#include "Event.h"

std::vector<Event*> Event::vEvents;

std::queue<ActiveEvent> ActiveEvent::vEventActivationQueue;

void Event::checkCollision(Sprite* s) {
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
}

void Event::handleCollision(Sprite* s) {
	printf("Default handler\n");
}

void Event::clearEventList() {
	for (std::vector<Event*>::iterator it = vEvents.begin(); it != vEvents.end(); ++it) {
		delete *it;
	}
	vEvents.clear();
}