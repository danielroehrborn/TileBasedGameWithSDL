#include <SDL.h>
#include <SDL_image.h>
#include "Sprite.h"
#include "Map.h"
extern unsigned int resolutionX, resolutionY;
extern Sprite *curSprite;
extern SDL_Renderer* renderer;

extern unsigned const char bghoehe = 100, bgbreite = 100;
//extern unsigned char bgTiles[bghoehe*bgbreite];
extern unsigned char bgWalk[bghoehe*bgbreite];

bool checkCollision(const SDL_Rect& pos) {
	for (int i = pos.y; i < pos.y + pos.h / 2; i++) {
		for (int j = pos.x - pos.w / 3; j < pos.x + (pos.w / 3); j++) {
			//if ((j / 16) < map1breite && (i / 16) < map1hoehe && (map1walkdata[i / 16][j / 16] >> 5) == 7) {
			//if ((j / 16) < map1breite && (i / 16) < map1hoehe && (map1walkdata[(i / 16)*map1breite+(j / 16)] >> 5) == 7) {
			if ((j / 16) < bgbreite && (i / 16) < bghoehe && (bgWalk[(i / 16)*bgbreite + (j / 16)] >> 5) == 7) {

				int bildmitteX = (resolutionX / 2);
				int bildmitteY = (resolutionY / 2);
				int ursprungX = bildmitteX - curSprite->mapPos.x;
				int ursprungY = bildmitteY - curSprite->mapPos.y;

				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 80);
				SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
				SDL_Rect collision;
				collision.x = ursprungX + pos.x - pos.w / 3;
				collision.y = ursprungY + pos.y;
				collision.h = pos.h / 2;
				collision.w = (pos.w / 3) * 2;
				SDL_RenderDrawRect(renderer, &collision);

				SDL_Rect object;
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

const SDL_Rect& Sprite::getFrameCoord() {
	if (animList.empty()) printf("AnimList empty\n");
	if (animList.size() == 0) printf("AnimList size 0\n");
	++frameCnt %= sData->animData[animList.front()]->list[curAnimFrameNum].displayDuration;
	if (frameCnt == 0) {
		++curAnimFrameNum %= sData->animData[animList.front()]->numFrames;
		if (curAnimFrameNum == 0 && animList.size() > 1) {
			animList.pop();
			mapPos.h = sData->animData[animList.front()]->list[curAnimFrameNum].frame.h;
			mapPos.w = sData->animData[animList.front()]->list[curAnimFrameNum].frame.w;
		}
		else if (autoDelete && curAnimFrameNum == 0 && animList.size() == 1) objectInUse = false;
	}
	SDL_Rect newPos;
	newPos.x = mapPos.x + sData->animData[animList.front()]->list[curAnimFrameNum].moveFrame.moveXPixel;
	newPos.y = mapPos.y + sData->animData[animList.front()]->list[curAnimFrameNum].moveFrame.moveYPixel;
	newPos.h = mapPos.h;
	newPos.w = mapPos.w;
	if (!checkCollision(newPos)) {
		mapPos.x = newPos.x;
		mapPos.y = newPos.y;
	}
	return sData->animData[animList.front()]->list[curAnimFrameNum].frame;
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

SDL_Texture* Sprite::textures[6];

Sprite::Sprite(const SpriteData* sd, const bool& autoDel) {
	sData = sd;
	objectInUse = true;
	autoDelete = autoDel;
	frameCnt = 0;
	curAnimFrameNum = 0;
	pushAnim(0);
	textures[0] = NULL;
	textures[1] = NULL;
	textures[2] = NULL;
	textures[3] = NULL;
	textures[4] = NULL;
	textures[5] = NULL;
	if (textures[sData->globalSpriteID] == NULL) {
		textures[sData->globalSpriteID] = loadTexture(sData->path);
		spriteTexture = textures[sData->globalSpriteID];
	}
}

void Sprite::pushAnim(const char& index) {
	if (animList.size() == 1) {
		animList.pop();
		frameCnt = 0;
		curAnimFrameNum = 0;
	}
	animList.push(index);
	mapPos.h = sData->animData[animList.front()]->list[curAnimFrameNum].frame.h;
	mapPos.w = sData->animData[animList.front()]->list[curAnimFrameNum].frame.w;
}

void Sprite::pushAnim(const char& num, const char* data) {
	for (int i = 0; i < num; i++) {
		animList.push(data[i]);
	}
}

void Sprite::setPos(const int& x, const int&y) {
	mapPos.x = x;
	mapPos.y = y;
}

const SDL_Rect& Sprite::getSpriteMapCoord() {
	return mapPos;
}