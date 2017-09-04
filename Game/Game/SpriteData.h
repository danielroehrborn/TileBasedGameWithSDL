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
		const SDL_Rect frame;
		const AnimMovement moveFrame;
		const char displayDuration;
	};
	class AnimAndTimingList {
	public:
		const char numFrames;
		const AnimAndTiming list[];
	};
	const char* path;
	const char numAnimations;
	const AnimAndTimingList* animData[];
};