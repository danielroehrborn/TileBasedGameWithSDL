#pragma once
#include <queue>
#include "SpriteData.h"
#include "Sprite.h"

class SpriteGroup :public Sprite {
public:
	SpriteGroup(int groupTexH, int groupTexW);
	~SpriteGroup();
	//void addSpriteToGroup(Sprite* s, SDL_Rect sPos);
	void pushAnim(unsigned char index);
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
	/*Sprite inheritance
	SDL_Texture* spriteTexture;
	SDL_Rect mapPos;
	bool objectInUse;
	std::queue<unsigned char> animList;*/
};