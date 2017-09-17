#include <stdio.h>
#include <queue>
#include "CollisionObject.h"

std::vector<CollisionObject*> CollisionObject::vColObj;

void CollisionObject::checkForCollision() {
	for (std::vector<CollisionObject*>::iterator it = vColObj.begin(); it != vColObj.end(); it++) {
		if (this->gridPos.x == (*it)->gridPos.x && this->gridPos.y == (*it)->gridPos.y && (*it) != this) {
			this->handleCollision(*it);
			(*it)->handleCollision(this);
		}
	}
}

/*void Warp::handleCollision(CollisionObject* other) {
	printf("Warp handle collision\n");
}*/