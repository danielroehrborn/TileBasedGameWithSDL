#include <SDL.h>
#include "SpriteGroup.h"

extern SDL_Renderer* renderer;

SpriteGroup::SpriteGroup(int groupTexH, int groupTexW) :Sprite(NULL, false) {
	spriteTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET, groupTexW, groupTexH);
	SDL_SetTextureBlendMode(spriteTexture, SDL_BLENDMODE_BLEND);
	mapPos.w = groupTexW;
	mapPos.h = groupTexH;
}

const SDL_Rect& SpriteGroup::getFrameCoord() {
	GroupAnim* curGroupSpriteAnim = &vGroupAnimList[animList.front()];
	++frameDurCnt %= curGroupSpriteAnim->duration;
	if (frameDurCnt == 0 && animList.size() > 1) {
		animList.pop();
		for (int i = 0; i < vGroupSprites.size(); ++i) {
			SDL_Rect tmpPos = curGroupSpriteAnim->memberSpriteAnims[i].AnimStartPos;
			if (tmpPos.x != 0) vGroupSprites[i]->mapPos = tmpPos;
			vGroupSprites[i]->pushAnim(curGroupSpriteAnim->memberSpriteAnims[i].AnimNum);
		}
	}
	mapPos.x += curGroupSpriteAnim->move.x;
	mapPos.y += curGroupSpriteAnim->move.y;
	for (std::vector<Sprite*>::iterator it = vGroupSprites.begin(); it != vGroupSprites.end(); ++it) {
		Sprite* s = *it;
		if (s->animList.empty()) printf("AnimList empty\n");
		++s->frameDurCnt %= s->sData->animData[s->animList.front()]->frames[s->curAnimFrameNum].displayDuration;
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
}

void SpriteGroup::renderGroupTexture() {
	SDL_SetRenderTarget(renderer, spriteTexture);
	SDL_RenderClear(renderer);
	for (std::vector<Sprite*>::iterator it = vGroupSprites.begin(); it != vGroupSprites.end(); ++it) {
		Sprite* s = *it;
		if ((*it)->objectInUse) {
			SDL_Rect src = s->sData->animData[s->animList.front()]->frames[s->curAnimFrameNum].imgPos;
			SDL_RenderCopy(renderer, s->spriteTexture, &src, &s->mapPos);
		}
	}
	SDL_SetRenderTarget(renderer, NULL);
}

void SpriteGroup::addAnimToMemberSprite(unsigned char spriteID, SDL_Rect startPos, const unsigned char animNum, std::vector<unsigned char>* anims) {
	if (startPos.x != 0) vGroupSprites[spriteID]->mapPos = startPos;                   //separate member animation
	if (animNum == 1) vGroupSprites[spriteID]->pushAnim(anims->front());
	else vGroupSprites[spriteID]->pushAnim(animNum, anims);
}

void SpriteGroup::pushAnim(unsigned char index) {
	Sprite::pushAnim(index);

	GroupAnim* curGroupSpriteAnim = &vGroupAnimList[animList.front()];
	for (int i = 0; i < vGroupSprites.size(); ++i) {
		SDL_Rect tmpPos = curGroupSpriteAnim->memberSpriteAnims[i].AnimStartPos;
		if (tmpPos.x != 0)
			vGroupSprites[i]->mapPos = tmpPos;
		vGroupSprites[i]->pushAnim(curGroupSpriteAnim->memberSpriteAnims[i].AnimNum);
	}
}

SpriteGroup::~SpriteGroup() {
	SDL_DestroyTexture(spriteTexture);
}