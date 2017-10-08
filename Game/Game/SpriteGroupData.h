#pragma once
#include "SDL.h"
#include "SpriteData.h"

class SpriteGroupData {
public:
	class SpriteAnimInGroup {
	public:
		const unsigned char animNum;
		const SDL_Rect startPos;
	};
	class GroupAnim {
	public:
		const unsigned char duration;
		const SDL_Rect move;
		const SpriteAnimInGroup spriteAnims[];
	};
	const SDL_Rect mapPos;
	const unsigned char numGroupSprites;
	const SpriteData** groupSprites;
	const unsigned char numGroupAnims;
	const GroupAnim* groupAnims[];
};