#pragma once
#include <queue>
#include "SpriteData.h"
#include "Sprite.h"


class SpriteGroup :public Sprite {
public:
	SpriteGroup(int groupTexH, int groupTexW);
	~SpriteGroup();
	//void addSpriteToGroup(Sprite* s, SDL_Rect sPos);
	const SDL_Rect& getFrameCoord();
	void renderGroupTexture();
	void addAnimToMemberSprite(unsigned char spriteID, SDL_Rect startPos, const unsigned char animNum, std::vector<unsigned char>* anims);

	class GroupMemberAnim {
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

	std::vector<GroupAnim> vGroupAnimList;
	std::vector<Sprite*> vGroupSprites;
	SDL_Texture* spriteTexture;
	unsigned char animDurCnt;
};