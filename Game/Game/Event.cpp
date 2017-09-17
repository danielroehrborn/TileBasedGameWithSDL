#include <stdio.h>
#include <queue>
#include "Event.h"

std::vector<Event*> Event::vEvents;

void Event::checkCollision(Sprite* s) {
	Sprite* sTmp;
	for (std::vector<Event*>::iterator it = vEvents.begin(); it != vEvents.end(); ++it) {
		sTmp = (*it)->immuneSprite;
		if (sTmp != NULL && sTmp != s && s->gridPos.x == sTmp->gridPos.x && s->gridPos.y == sTmp->gridPos.y) {
			(*it)->handleCollision(s);
			return;
		}
		else if (sTmp == NULL && s->gridPos.x == (*it)->uniquePos.x && s->gridPos.y == (*it)->uniquePos.y) {
			(*it)->handleCollision(s);
			return;
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