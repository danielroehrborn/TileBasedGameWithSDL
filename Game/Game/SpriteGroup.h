#pragma once
#include <queue>
#include "SpriteData.h"
#include "SpriteGroupData.h"
#include "Sprite.h"

class SpriteGroup :public Sprite {
public:
	SpriteGroup(const SpriteGroupData* sgd);
	~SpriteGroup();
	//void addSpriteToGroup(Sprite* s, SDL_Rect sPos);
	void pushAnim(unsigned char index);
	const SDL_Rect& getFrameCoord();
	void renderGroupTexture();
	void addAnimToMemberSprite(unsigned char spriteID, SDL_Rect startPos, const unsigned char animNum, std::vector<unsigned char>* anims);
	const unsigned char getNumAnims();

	/*class GroupMemberAnim {
	public:
		unsigned char AnimNum;
		SDL_Rect AnimStartPos;
	};
	class GroupAnim {
	public:
		std::vector<GroupMemberAnim> memberSpriteAnims;
		unsigned char duration;
		SDL_Rect move;
	};

	std::vector<GroupAnim> vGroupAnimList;*/
	std::vector<Sprite*> vGroupSprites;
	const SpriteGroupData* sgData;
	/*Sprite inheritance
	SDL_Texture* spriteTexture;
	SDL_Rect mapPos;
	bool objectInUse;
	std::queue<unsigned char> animList;*/
};