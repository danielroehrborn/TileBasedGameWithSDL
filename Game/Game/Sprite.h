#pragma once
#include <queue>
#include "SpriteData.h"

class SpritePersistanceData {
public:
	const SpriteData* sData;
	unsigned char curMapID;
	SDL_Rect mapPos;
	unsigned char curAnim;
};

class Sprite {
public:
	const SpriteData* sData;
	SpritePersistanceData* pData = NULL;
	Sprite(const SpriteData* sd, const bool& autoDel);/* {
		sData = sd;
		objectInUse = true;
		autoDelete = autoDel;
		frameCnt = 0;
		curAnimFrameNum = 0;
		pushAnim(0);
		spriteTexture = tex;
	}*/
	SDL_Texture* spriteTexture = NULL;
	static SDL_Texture* loadTexture(const char* path);/* {
		SDL_Surface* tmpSurface = IMG_Load(path);
		SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
		if (tmpTexture == NULL) {
			printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
		}
		SDL_FreeSurface(tmpSurface);
		return tmpTexture;
	}*/
	void pushAnim(const unsigned char& index);/* {
		if (animList.size() == 1) {
			animList.pop();
			frameCnt = 0;
			curAnimFrameNum = 0;
		}
		animList.push(index);
		mapPos.h = sData->animData[animList.front()]->list[curAnimFrameNum].frame.h;
		mapPos.w = sData->animData[animList.front()]->list[curAnimFrameNum].frame.w;
	}*/
	void pushAnim(const unsigned char& num, const unsigned char* data);/* {
		for (int i = 0; i < num; i++) {
			animList.push(data[i]);
		}
	}*/
	void setPos(const int& x, const int&y);/* {
		mapPos.x = x;
		mapPos.y = y;
	}*/
	const SDL_Rect& getFrameCoord();
	const SDL_Rect& getSpriteMapCoord();/* {
		return mapPos;
	}*/
	~Sprite() {};
	SDL_Rect mapPos;
	SDL_Rect gridPos;
	bool objectInUse;
	char curAnimFrameNum;
	char frameDurCnt;
	bool autoDelete;
	std::queue<char> animList;
	static SDL_Texture* textures[6];
};