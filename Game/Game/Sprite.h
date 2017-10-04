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
	Sprite(const SpriteData* sd, const bool& autoDel);
	SDL_Texture* spriteTexture = NULL;
	static SDL_Texture* loadTexture(const char* path);
	virtual void pushAnim(unsigned char index);
	void pushAnim(const unsigned char& num, std::vector<unsigned char>* data);
	void setPos(const int& x, const int&y);
	virtual const SDL_Rect& getFrameCoord();
	const SDL_Rect& getSpriteMapCoord();
	void changeSData(const SpriteData* sd);
	~Sprite() {};
	SDL_Rect mapPos;
	SDL_Rect gridPos;
	bool objectInUse;
	char curAnimFrameNum;
	char frameDurCnt;
	bool autoDelete;
	std::queue<unsigned char> animList;
	static SDL_Texture* textures[];
};