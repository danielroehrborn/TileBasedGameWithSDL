#include <SDL.h>
#include <SDL_image.h>
#include "Sprite.h"
#include "Map.h"
#include "Event.h"
extern unsigned int resolutionX, resolutionY;
extern Sprite *curSprite;
extern SDL_Renderer* renderer;

extern unsigned const char bghoehe = 100, bgbreite = 100;
//extern unsigned char bgTiles[bghoehe*bgbreite];
extern unsigned char bgWalk[bghoehe*bgbreite];

SDL_Rect collision;
SDL_Rect object;
int bildmitteX, bildmitteY, ursprungX, ursprungY;
bool checkCollision(const SDL_Rect& pos) {
	for (int i = pos.y; i < pos.y + pos.h / 2; i++) {
		for (int j = pos.x - pos.w / 4; j < pos.x + (pos.w / 4); j++) {//for (int j = pos.x - pos.w / 3; j < pos.x + (pos.w / 3); j++) {
			if ((j / 16) < bgbreite && (i / 16) < bghoehe && (bgWalk[(i / 16)*bgbreite + (j / 16)] >> 5) == 7) {

				bildmitteX = (resolutionX / 2);
				bildmitteY = (resolutionY / 2);
				ursprungX = bildmitteX - curSprite->mapPos.x;
				ursprungY = bildmitteY - curSprite->mapPos.y;

				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 80);
				SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
				collision.x = ursprungX + pos.x - pos.w / 4;//collision.x = ursprungX + pos.x - pos.w / 3;
				collision.y = ursprungY + pos.y;
				collision.h = pos.h / 2;
				collision.w = (pos.w / 2);//collision.w = (pos.w / 3) * 2;
				SDL_RenderDrawRect(renderer, &collision);

				object.x = ursprungX + (j / 16) * 16;
				object.y = ursprungY + (i / 16) * 16;
				object.h = 16;
				object.w = 16;
				SDL_RenderDrawRect(renderer, &object);

				SDL_SetRenderDrawColor(renderer, 100, 50, 150, 20);
				SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
				return true;
			}
		}
	}
	return false;
}

extern std::vector<SDL_Rect*> vWarps;
SDL_Rect newPos, newGridPos;
extern void checkAndDoMapTransition(Sprite* s);
const SDL_Rect& Sprite::getFrameCoord() {
	if (animList.empty()) printf("AnimList empty\n");
	if (animList.size() == 0) printf("AnimList size 0\n");
	++frameDurCnt %= sData->animData[animList.front()]->frames[curAnimFrameNum].displayDuration;
	if (frameDurCnt == 0) {
		++curAnimFrameNum %= sData->animData[animList.front()]->numFrames;
		if (curAnimFrameNum == 0 && animList.size() > 1) {
			animList.pop();
			mapPos.h = sData->animData[animList.front()]->frames[curAnimFrameNum].imgPos.h;
			mapPos.w = sData->animData[animList.front()]->frames[curAnimFrameNum].imgPos.w;
		}
		else if (autoDelete && curAnimFrameNum == 0 && animList.size() == 1) objectInUse = false;
	}
	newPos.x = mapPos.x + sData->animData[animList.front()]->frames[curAnimFrameNum].move.moveXPixel;
	newPos.y = mapPos.y + sData->animData[animList.front()]->frames[curAnimFrameNum].move.moveYPixel;
	newPos.h = mapPos.h;
	newPos.w = mapPos.w;
	/*if ((newPos.x != mapPos.x || newPos.y != mapPos.y) && !checkCollision(newPos)) {
		mapPos.x = newPos.x;
		mapPos.y = newPos.y;
		newGridPos.x = (newPos.x / 16) - 8;
		newGridPos.y = (newPos.y / 16) - 8;
		if (newGridPos.x != gridPos.x || newGridPos.y != gridPos.y) {
			gridPos.x = newGridPos.x;
			gridPos.y = newGridPos.y;
			EventManagement::checkCollision(this);
			checkAndDoMapTransition(this);
		}
	}*/
	unsigned char doSpriteSlide = 1;
	do {
		if ((newPos.x != mapPos.x || newPos.y != mapPos.y)) {
			if (!checkCollision(newPos)) {
				mapPos.x = newPos.x;
				mapPos.y = newPos.y;
				newGridPos.x = (newPos.x / 16) - 8;
				newGridPos.y = (newPos.y / 16) - 8;
				if (newGridPos.x != gridPos.x || newGridPos.y != gridPos.y) {
					gridPos.x = newGridPos.x;
					gridPos.y = newGridPos.y;
					EventManagement::checkCollision(this);
					checkAndDoMapTransition(this);
				}
				break;
			}
			else {
				if (newPos.x != mapPos.x) {
					newPos.x = mapPos.x;
					newPos.y = newPos.y % 16 > 7 ? newPos.y + 1 : newPos.y % 16 > 0 ? newPos.y - 1 : newPos.y;
				}
				else if (newPos.y != mapPos.y) {
					newPos.y = mapPos.y;
					newPos.x = (newPos.x + newPos.w / 4) % 16 > 8 ? newPos.x + 1 : (newPos.x + newPos.w / 4) % 16 > 0 ? newPos.x - 1 : newPos.x;
				}
			}
		}
	} while (doSpriteSlide--);
	return sData->animData[animList.front()]->frames[curAnimFrameNum].imgPos;
}

SDL_Texture* Sprite::loadTexture(const char* path) {
	SDL_Surface* tmpSurface = IMG_Load(path);
	SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	if (tmpTexture == NULL) {
		printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
	}
	SDL_FreeSurface(tmpSurface);
	return tmpTexture;
}

SDL_Texture* Sprite::textures[7];
//SDL_Rect tmpZero = { 0,0,0,0 };
Sprite::Sprite(const SpriteData* sd, const bool& autoDel) {
	sData = sd;
	objectInUse = true;
	autoDelete = autoDel;
	frameDurCnt = 0;
	curAnimFrameNum = 0;
	pushAnim(0);
	if (textures[sData->globalSpriteID] == NULL)
		textures[sData->globalSpriteID] = loadTexture(sData->path);
	spriteTexture = textures[sData->globalSpriteID];
}

void Sprite::pushAnim(unsigned char index) {
	if (animList.size() == 1) {
		animList.pop();
		frameDurCnt = 0;
		curAnimFrameNum = 0;
	}
	animList.push(index);
	mapPos.h = sData->animData[animList.front()]->frames[curAnimFrameNum].imgPos.h;
	mapPos.w = sData->animData[animList.front()]->frames[curAnimFrameNum].imgPos.w;
}

void Sprite::pushAnim(const unsigned char& num, std::vector<unsigned char>* data) {
	for (int i = 0; i < num; i++) {
		animList.push((*data)[i]);
	}
}

void Sprite::setPos(const int& x, const int&y) {
	mapPos.x = x;
	mapPos.y = y;
	gridPos.x = (x / 16) - 8;
	gridPos.y = (y / 16) - 8;
}

const SDL_Rect& Sprite::getSpriteMapCoord() {
	return mapPos;
}