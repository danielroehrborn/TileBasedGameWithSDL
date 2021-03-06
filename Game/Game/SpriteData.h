#pragma once
class SpriteData {
public:
	class AnimMovement {
	public:
		const char moveXPixel;
		const char moveYPixel;
	};
	class AnimAndTiming {
	public:
		const SDL_Rect imgPos;
		const AnimMovement move;
		const char displayDuration;
	};
	class AnimAndTimingList {
	public:
		const char numFrames;
		const AnimAndTiming frames[];
	};
	const unsigned char globalSpriteID;
	const char* path;
	const char numAnimations;
	const AnimAndTimingList* animData[];
};