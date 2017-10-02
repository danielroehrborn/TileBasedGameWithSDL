#pragma once
#include <queue>
#include "SpriteData.h"
#include "Sprite.h"


class SpriteGroup :public Sprite {
public:
	class GroupMemberSpriteAnim {
	public:
		unsigned char SpriteAnimNum;
		SDL_Rect SpriteAnimStartPos;
	};
	class GroupSpriteAnim {
	public:
		std::vector<GroupMemberSpriteAnim> memberSpriteAnims;
		unsigned char duration;
		SDL_Rect move;
	};

	SpriteGroup(const SpriteData* sd, const bool& autoDel, int groupTexH, int groupTexW);/* : Sprite(sd, autoDel) {
		spriteTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, groupTexW, groupTexH);
		mapPos.w = groupTexW;
		mapPos.h = groupTexH;
	}*/
	//void addSpriteToGroup(Sprite* s, SDL_Rect sPos);
	const SDL_Rect& getFrameCoord();/* {
		GroupSpriteAnim* curGroupSpriteAnim = &groupAnimList[animList.front()];
		++animDurCnt %= curGroupSpriteAnim->duration;
		if (animDurCnt == 0 && animList.size() > 1) {
			animList.pop();
			for (int i = 0; i < vGroupSprites.size(); ++i) {
				SDL_Rect tmpPos = curGroupSpriteAnim->memberSpriteAnims[i].SpriteAnimStartPos;
				if (tmpPos.x != 0) vGroupSprites[i]->mapPos = tmpPos;
				vGroupSprites[i]->pushAnim(curGroupSpriteAnim->memberSpriteAnims[i].SpriteAnimNum);
			}
		}
		//todo: groupSprite collision check
		mapPos.x += curGroupSpriteAnim->move.x;
		mapPos.y += curGroupSpriteAnim->move.y;
		for (std::vector<Sprite*>::iterator it = vGroupSprites.begin(); it != vGroupSprites.end(); ++it) {
			Sprite* s = *it;
			if (s->animList.empty()) printf("AnimList empty\n");
			++s->frameDurCnt %= s->sData->animData[s->animList.front()]->frames[curAnimFrameNum].displayDuration;
			if (s->frameDurCnt == 0) {
				++s->curAnimFrameNum %= s->sData->animData[animList.front()]->numFrames;
				if (s->curAnimFrameNum == 0 && s->animList.size() > 1) {
					s->animList.pop();
					s->mapPos.h = s->sData->animData[animList.front()]->frames[curAnimFrameNum].imgPos.h;
					s->mapPos.w = s->sData->animData[animList.front()]->frames[curAnimFrameNum].imgPos.w;
				}
				else if (s->autoDelete && s->curAnimFrameNum == 0 && s->animList.size() == 1) s->objectInUse = false;
			}
			s->mapPos.x += s->sData->animData[s->animList.front()]->frames[s->curAnimFrameNum].move.moveXPixel;
			s->mapPos.y += s->sData->animData[s->animList.front()]->frames[s->curAnimFrameNum].move.moveYPixel;
		}
		renderGroupTexture();
		return{ 0, 0, mapPos.w, mapPos.h };//xywh
	}*/
	void renderGroupTexture();/* {
		SDL_SetRenderTarget(renderer, spriteTexture);
		SDL_RenderClear(renderer);
		for (std::vector<Sprite*>::iterator it = vGroupSprites.begin(); it != vGroupSprites.end(); ++it) {
			Sprite* s = *it;
			if ((*it)->objectInUse) {
				SDL_Rect src = s->sData->animData[animList.front()]->frames[curAnimFrameNum].imgPos;
				SDL_RenderCopy(renderer, s->spriteTexture, &src, &s->mapPos);
			}
		}
		SDL_SetRenderTarget(renderer, NULL);
	}*/
	void addAnimToMemberSprite(unsigned char spriteID, SDL_Rect startPos, const unsigned char animNum, std::vector<unsigned char>* anims);/* {
		if (startPos.x != 0) vGroupSprites[spriteID]->mapPos = startPos;                   //separate member animation
		if (animNum == 1) vGroupSprites[spriteID]->pushAnim(anims->front());
		else vGroupSprites[spriteID]->pushAnim(animNum, anims);
	}*/
	
	std::vector<GroupSpriteAnim> groupAnimList;//jede groupAnim=x*spriteAnim
	std::vector<Sprite*> vGroupSprites;
	SDL_Texture* spriteTexture;
	unsigned char animDurCnt;
	//von Sprite geerbt:
	//std::queue<unsigned char> animList //index für groupAnimList
	//void pushAnim(unsigned char index, unsigned char duration)
	//void pushAnim(const unsigned char& num, std::vector<unsigned char>* data, unsigned char duration)
	~SpriteGroup() {
		SDL_DestroyTexture(spriteTexture);
	}
};