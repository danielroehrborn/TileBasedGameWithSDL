#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <SDL_thread.h>
#include <queue>

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
int resolutionX = 640;
int resolutionY = (resolutionX / 4) * 3;

const char map1breite = 50, map1hoehe = 20, map1border = 13;
unsigned char map1tiledata[map1hoehe][map1breite] = {
	{ 7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7 },
	{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7 },
	{ 7,1,1,1,176,177,177,177,177,178,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7 },
	{ 7,1,1,1,184,0,0,0,0,186,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7 },
	{ 7,1,1,1,184,0,8,8,0,186,1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7 },
	{ 7,1,1,1,184,0,8,8,0,186,1,1,1,1,1,1,5,1,1,1,1,1,1,1,1,72,73,74,75,76,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7 },
	{ 7,1,1,1,184,0,0,0,0,186,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,80,81,82,83,84,1,1,1,13,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7 },
	{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,88,89,90,91,92,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7 },
	{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,96,97,98,99,100,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7 },
	{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7 },
	{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,62,63,1,1,1,1,1,1,1,1,1,1,1,7 },
	{ 7,1,1,13,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,69,70,71,77,1,1,1,1,1,1,1,1,1,1,7 },
	{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,13,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,78,79,1,1,1,1,1,1,1,1,1,1,1,7 },
	{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7 },
	{ 7,1,1,1,1,1,1,13,1,1,1,1,1,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7 },
	{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7 },
	{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7 },
	{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7 },
	{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7 },
	{ 7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7 }
};

unsigned char map1walkdata[map1hoehe][map1breite] = {
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,24,24,24,24,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,24,24,24,24,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,24,24,24,24,0,0,0,0,0,0,0,224,0,0,0,0,0,0,0,0,224,224,224,224,224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,24,24,24,24,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,224,224,224,224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,224,224,224,224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,224,224,224,224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
};

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
		const AnimMovement moveFrame;//const char moveSpeed;
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
const SpriteData::AnimAndTimingList HiroLookDown = { 1,{ {{1,34,32,32},{0,0},16} } };
const SpriteData::AnimAndTimingList HiroWalkDown = { 4,{ {{34,34,32,32},{0,1},9}, {{1,34,32,32},{ 0,1 },9 }, {{67,34,32,32},{ 0,1 },9 }, {{1,34,32,32},{ 0,1 },9 } } };
const SpriteData::AnimAndTimingList HiroLookUp = { 1,{ {{1,1,32,32},{ 0,0 },16 } } };
const SpriteData::AnimAndTimingList HiroWalkUp = { 4,{ {{34,1,32,32 },{ 0,-1 },9 }, {{1,1,32,32},{ 0,-1 },9 }, {{67,1,32,32},{ 0,-1 },9 }, {{1,1,32,32},{ 0,-1 },9 } } };
const SpriteData::AnimAndTimingList HiroLookLeft = { 1,{ {{1,67,32,32},{ 0,0 },16 } } };
const SpriteData::AnimAndTimingList HiroWalkLeft = { 4,{ {{34,67,32,32},{ -1,0 },9 }, {{1,67,32,32},{ -1,0 },9 }, {{67,67,32,32},{ -1,0 },9 }, {{1,67,32,32},{ -1,0 },9 } } };
const SpriteData::AnimAndTimingList HiroLookRight = { 1,{ {{1,100,32,32},{ 0,0 },16 } } };
const SpriteData::AnimAndTimingList HiroWalkRight = { 4,{ {{34,100,32,32},{ 1,0 },9 }, {{1,100,32,32},{ 1,0 },9 }, {{67,100,32,32},{ 1,0 },9 }, {{1,100,32,32},{ 1,0 },9 } } };
const SpriteData::AnimAndTimingList HiroRunDown = { 4,{ {{166,34,32,32},{ 0,3 },8 }, {{133,34,32,32},{ 0,2 },6 }, {{199,34,32,32},{ 0,3 },8 }, {{133,34,32,32},{ 0,2 },6 } } };
const SpriteData::AnimAndTimingList HiroRunUp = { 4,{ { { 166,1,32,32 },{ 0,-3 },8 },{ { 133,1,32,32 },{ 0,-2 },6 },{ { 199,1,32,32 },{ 0,-3 },8 },{ { 133,1,32,32 },{ 0,-2 },6 } } };
const SpriteData::AnimAndTimingList HiroRunLeft = { 4,{ { { 166,67,32,32 },{ -3,0 },8 },{ { 133,67,32,32 },{ -2,0 },6 },{ { 199,67,32,32 },{ -3,0 },8 },{ { 133,67,32,32 },{ -2,0 },6 } } };
const SpriteData::AnimAndTimingList HiroRunRight = { 4,{ { { 166,100,32,32 },{ 3,0 },8 },{ { 133,100,32,32 },{ 2,0 },6 },{ { 199,100,32,32 },{ 3,0 },8 },{ { 133,100,32,32 },{ 2,0 },6 } } };
const SpriteData::AnimAndTimingList HiroAngelDown = { 4,{ { { 1,594,64,64 },{ 0,0 },12 },{ { 66,594,64,64 },{ 0,0 },8 },{ { 131,594,64,64 },{ 0,1 },4 },{ { 196,594,64,64 },{ 0,-1 },12 } } };
const SpriteData Hiro = {
	"HiroSprites.png",13,{ &HiroLookDown, &HiroWalkDown, &HiroLookUp, &HiroWalkUp, &HiroLookLeft,
	&HiroWalkLeft, &HiroLookRight, &HiroWalkRight, &HiroRunDown, &HiroRunUp, &HiroRunLeft, &HiroRunRight, &HiroAngelDown }
};

const SpriteData::AnimAndTimingList CommandosLookDown = { 4,{ { { 599,452,30,41 },{ 0,0 },20 },{ { 631,452,30,41 },{ 0,0 },20 },{ { 663,452,30,41 },{ 0,0 },20 },{ { 631,452,30,41 },{ 0,0 },20 } } };
const SpriteData::AnimAndTimingList CommandosWalkDown = { 8,{ { { 2,192,24,43 },{ 0,1 },6 },{ { 30,192,24,43 },{ 0,1 },8 },{ { 58,192,24,43 },{ 0,1 },8 },{ { 86,192,24,43 },{ 0,1 },6 },{ { 114,192,24,43 },{ 0,1 },8 },{ { 142,192,24,43 },{ 0,1 },6 },{ { 170,192,24,43 },{ 0,1 },8 },{ { 198,192,24,43 },{ 0,1 },8 } } };
const SpriteData::AnimAndTimingList CommandosLookUp = { 4,{ { { 588,315,31,39 },{ 0,0 },20 },{ { 620,315,31,39 },{ 0,0 },20 },{ { 652,315,31,39 },{ 0,0 },20 },{ { 620,315,31,39 },{ 0,0 },20 } } };
const SpriteData::AnimAndTimingList CommandosWalkUp = { 8,{ { { 1,7,24,43 },{ 0,-1 },6 },{ { 29,7,24,43 },{ 0,-1 },8 },{ { 57,7,24,43 },{ 0,-1 },8 },{ { 85,7,24,43 },{ 0,-1 },6 },{ { 113,7,24,43 },{ 0,-1 },8 },{ { 141,7,24,43 },{ 0,-1 },6 },{ { 169,7,24,43 },{ 0,-1 },10 },{ { 197,7,24,43 },{ 0,-1 },10 } } };
const SpriteData::AnimAndTimingList CommandosLookLeft = { 4,{ { { 658,355,17,49 },{ 0,0 },20 },{ { 640,355,17,49 },{ 0,0 },20 },{ { 658,355,17,49 },{ 0,0 },20 },{ { 676,355,17,49 },{ 0,0 },20 } } };
const SpriteData::AnimAndTimingList CommandosWalkLeft = { 8,{ { { 237,442,25,48 },{ -1,0 },6 },{ { 265,442,25,48 },{ -1,0 },8 },{ { 293,442,25,48 },{ -1,0 },10 },{ { 321,442,25,48 },{ -1,0 },6 },{ { 349,442,25,48 },{ -1,0 },8 },{ { 377,442,25,48 },{ -1,0 },6 },{ { 405,442,25,48 },{ -1,0 },10 },{ { 433,442,25,48 },{ -1,0 },8 } } };
const SpriteData::AnimAndTimingList CommandosLookRight = { 4,{ { { 603,355,17,49 },{ 0,0 },20 },{ { 585,355,17,49 },{ 0,0 },20 },{ { 603,355,17,49 },{ 0,0 },20 },{ { 621,355,17,49 },{ 0,0 },20 } } };
const SpriteData::AnimAndTimingList CommandosWalkRight = { 8,{ { { 1,99,25,48 },{ 1,0 },6 },{ { 29,99,25,48 },{ 1,0 },8 },{ { 57,99,25,48 },{ 1,0 },10 },{ { 85,99,25,48 },{ 1,0 },6 },{ { 113,99,25,48 },{ 1,0 },8 },{ { 141,99,25,48 },{ 1,0 },6 },{ { 169,99,25,48 },{ 1,0 },10 },{ { 197,99,25,48 },{ 1,0 },8 } } };
const SpriteData Commandos = {
	"Commandos.png",8,{ &CommandosLookDown, &CommandosWalkDown, &CommandosLookUp, &CommandosWalkUp, &CommandosLookLeft,
	&CommandosWalkLeft, &CommandosLookRight, &CommandosWalkRight, &HiroRunDown, &HiroRunUp, &HiroRunLeft, &HiroRunRight, &HiroAngelDown }
};

const SpriteData::AnimAndTimingList DiabloLookDown = { 16,{ { { 0,1301,160,160 },{ 0,0 },8 },{ { 160,1301,160,160 },{ 0,0 },8 },{ { 320,1301,160,160 },{ 0,0 },8 },{ { 480,1301,160,160 },{ 0,0 },8 },{ { 640,1301,160,160 },{ 0,0 },8 },{ { 800,1301,160,160 },{ 0,0 },8 },{ { 960,1301,160,160 },{ 0,0 },8 },{ { 1120,1301,160,160 },{ 0,0 },8 },{ { 1280,1301,160,160 },{ 0,0 },8 },{ { 1440,1301,160,160 },{ 0,0 },8 },{ { 1600,1301,160,160 },{ 0,0 },8 },{ { 1760,1301,160,160 },{ 0,0 },8 },{ { 1920,1301,160,160 },{ 0,0 },8 },{ { 2080,1301,160,160 },{ 0,0 },8 },{ { 2240,1301,160,160 },{ 0,0 },8 },{ { 2400,1301,160,160 },{ 0,0 },8 } } };
const SpriteData::AnimAndTimingList DiabloWalkDown = { 6,{ { { 5122,1301,160,160 },{ 0,1 },8 },{ { 5282,1301,160,160 },{ 0,1 },8 },{ { 5442,1301,160,160 },{ 0,1 },8 },{ { 5602,1301,160,160 },{ 0,1 },8 },{ { 5762,1301,160,160 },{ 0,1 },8 },{ { 5922,1301,160,160 },{ 0,1 },8 } } };
const SpriteData::AnimAndTimingList DiabloLookUp = { 16,{ { { 0,1945,160,160 },{ 0,0 },8 },{ { 160,1945,160,160 },{ 0,0 },8 },{ { 320,1945,160,160 },{ 0,0 },8 },{ { 480,1945,160,160 },{ 0,0 },8 },{ { 640,1945,160,160 },{ 0,0 },8 },{ { 800,1945,160,160 },{ 0,0 },8 },{ { 960,1945,160,160 },{ 0,0 },8 },{ { 1120,1945,160,160 },{ 0,0 },8 },{ { 1280,1945,160,160 },{ 0,0 },8 },{ { 1440,1945,160,160 },{ 0,0 },8 },{ { 1600,1945,160,160 },{ 0,0 },8 },{ { 1760,1945,160,160 },{ 0,0 },8 },{ { 1920,1945,160,160 },{ 0,0 },8 },{ { 2080,1945,160,160 },{ 0,0 },8 },{ { 2240,1945,160,160 },{ 0,0 },8 },{ { 2400,1945,160,160 },{ 0,0 },8 } } };
const SpriteData::AnimAndTimingList DiabloWalkUp = { 6,{ { { 5122,1945,160,160 },{ 0,-1 },8 },{ { 5282,1945,160,160 },{ 0,-1 },8 },{ { 5442,1945,160,160 },{ 0,-1 },8 },{ { 5602,1945,160,160 },{ 0,-1 },8 },{ { 5762,1945,160,160 },{ 0,-1 },8 },{ { 5922,1945,160,160 },{ 0,-1 },8 } } };
const SpriteData::AnimAndTimingList DiabloLookLeft = { 16,{ { { 0,1623,160,160 },{ 0,0 },8 },{ { 160,1623,160,160 },{ 0,0 },8 },{ { 320,1623,160,160 },{ 0,0 },8 },{ { 480,1623,160,160 },{ 0,0 },8 },{ { 640,1623,160,160 },{ 0,0 },8 },{ { 800,1623,160,160 },{ 0,0 },8 },{ { 960,1623,160,160 },{ 0,0 },8 },{ { 1120,1623,160,160 },{ 0,0 },8 },{ { 1280,1623,160,160 },{ 0,0 },8 },{ { 1440,1623,160,160 },{ 0,0 },8 },{ { 1600,1623,160,160 },{ 0,0 },8 },{ { 1760,1623,160,160 },{ 0,0 },8 },{ { 1920,1623,160,160 },{ 0,0 },8 },{ { 2080,1623,160,160 },{ 0,0 },8 },{ { 2240,1623,160,160 },{ 0,0 },8 },{ { 2400,1623,160,160 },{ 0,0 },8 } } };
const SpriteData::AnimAndTimingList DiabloWalkLeft = { 6,{ { { 5122,1623,160,160 },{ -1,0 },9 },{ { 5282,1623,160,160 },{ -1,0 },9 },{ { 5442,1623,160,160 },{ -1,0 },9 },{ { 5602,1623,160,160 },{ -1,0 },9 },{ { 5762,1623,160,160 },{ -1,0 },9 },{ { 5922,1623,160,160 },{ -1,0 },9 } } };
const SpriteData::AnimAndTimingList DiabloLookRight = { 16,{ { { 0,2267,160,160 },{ 0,0 },8 },{ { 160,2267,160,160 },{ 0,0 },8 },{ { 320,2267,160,160 },{ 0,0 },8 },{ { 480,2267,160,160 },{ 0,0 },8 },{ { 640,2267,160,160 },{ 0,0 },8 },{ { 800,2267,160,160 },{ 0,0 },8 },{ { 960,2267,160,160 },{ 0,0 },8 },{ { 1120,2267,160,160 },{ 0,0 },8 },{ { 1280,2267,160,160 },{ 0,0 },8 },{ { 1440,2267,160,160 },{ 0,0 },8 },{ { 1600,2267,160,160 },{ 0,0 },8 },{ { 1760,2267,160,160 },{ 0,0 },8 },{ { 1920,2267,160,160 },{ 0,0 },8 },{ { 2080,2267,160,160 },{ 0,0 },8 },{ { 2240,2267,160,160 },{ 0,0 },8 },{ { 2400,2267,160,160 },{ 0,0 },8 } } };
const SpriteData::AnimAndTimingList DiabloWalkRight = { 6,{ { { 5122,2267,160,160 },{ 1,0 },9 },{ { 5282,2267,160,160 },{ 1,0 },9 },{ { 5442,2267,160,160 },{ 1,0 },9 },{ { 5602,2267,160,160 },{ 1,0 },9 },{ { 5762,2267,160,160 },{ 1,0 },9 },{ { 5922,2267,160,160 },{ 1,0 },9 } } };
const SpriteData::AnimAndTimingList DiabloAttackDown = { 16,{ { { 0,7,160,160 },{ 0,0 },4 },{ { 160,7,160,160 },{ 0,0 },4 },{ { 320,7,160,160 },{ 0,0 },6 },{ { 480,7,160,160 },{ 0,0 },6 },{ { 640,7,160,160 },{ 0,0 },8 },{ { 800,7,160,160 },{ 0,0 },8 },{ { 960,7,160,160 },{ 0,0 },8 },{ { 1120,7,160,160 },{ 0,0 },8 },{ { 1280,7,160,160 },{ 0,0 },8 },{ { 1440,7,160,160 },{ 0,0 },8 },{ { 1600,7,160,160 },{ 0,0 },8 },{ { 1760,7,160,160 },{ 0,0 },6 },{ { 1920,7,160,160 },{ 0,0 },6 },{ { 2080,7,160,160 },{ 0,0 },6 },{ { 2240,7,160,160 },{ 0,0 },6 },{ { 2400,7,160,160 },{ 0,0 },8 } } };
const SpriteData::AnimAndTimingList DiabloDieDown = { 16,{ { { 2561,7,160,160 },{ 0,0 },4 },{ { 2721,7,160,160 },{ 0,0 },4 },{ { 2881,7,160,160 },{ 0,0 },6 },{ { 3041,7,160,160 },{ 0,0 },6 },{ { 3201,7,160,160 },{ 0,0 },8 },{ { 3361,7,160,160 },{ 0,0 },8 },{ { 3521,7,160,160 },{ 0,0 },8 },{ { 3681,7,160,160 },{ 0,0 },8 },{ { 3841,7,160,160 },{ 0,0 },8 },{ { 4001,7,160,160 },{ 0,0 },8 },{ { 4161,7,160,160 },{ 0,0 },8 },{ { 4321,7,160,160 },{ 0,0 },6 },{ { 4481,7,160,160 },{ 0,0 },6 },{ { 4641,7,160,160 },{ 0,0 },6 },{ { 4801,7,160,160 },{ 0,0 },6 },{ { 4961,7,160,160 },{ 0,0 },8 } } };
const SpriteData::AnimAndTimingList DiabloSpecialDown = { 16,{ { { 2561,1301,160,160 },{ 0,0 },4 },{ { 2721,1301,160,160 },{ 0,0 },4 },{ { 2881,1301,160,160 },{ 0,0 },6 },{ { 3041,1301,160,160 },{ 0,0 },6 },{ { 3201,1301,160,160 },{ 0,0 },8 },{ { 3361,1301,160,160 },{ 0,0 },8 },{ { 3521,1301,160,160 },{ 0,0 },8 },{ { 3681,1301,160,160 },{ 0,0 },8 },{ { 3841,1301,160,160 },{ 0,0 },8 },{ { 4001,1301,160,160 },{ 0,0 },8 },{ { 4161,1301,160,160 },{ 0,0 },8 },{ { 4321,1301,160,160 },{ 0,0 },6 },{ { 4481,1301,160,160 },{ 0,0 },6 },{ { 4641,1301,160,160 },{ 0,0 },6 },{ { 4801,1301,160,160 },{ 0,0 },6 },{ { 4961,1301,160,160 },{ 0,0 },8 } } };
const SpriteData::AnimAndTimingList DiabloGetHitDown = { 6,{ { { 5122,7,160,160 },{ 0,0 },9 },{ { 5282,7,160,160 },{ 0,0 },9 },{ { 5442,7,160,160 },{ 0,0 },9 },{ { 5602,7,160,160 },{ 0,0 },9 },{ { 5762,7,160,160 },{ 0,0 },9 },{ { 5922,7,160,160 },{ 0,0 },9 } } };

const SpriteData Diablo = {
	"Diablo.png",12,{ &DiabloLookDown, &DiabloWalkDown, &DiabloLookUp, &DiabloWalkUp, &DiabloLookLeft, &DiabloWalkLeft, &DiabloLookRight, &DiabloWalkRight, &DiabloAttackDown, &DiabloDieDown, &DiabloSpecialDown, &DiabloGetHitDown }
};

const SpriteData::AnimAndTimingList HyperLightDrifterLookDown = { 1,{ { { 64,32,32,32 },{ 0,0 },20 } } };
const SpriteData::AnimAndTimingList HyperLightDrifterWalkDown = { 12,{ { { 96,32,32,32 },{ 0,2 },4 },{ { 128,32,32,32 },{ 0,2 },4 },{ { 160,32,32,32 },{ 0,2 },4 },{ { 192,32,32,32 },{ 0,2 },4 },{ { 224,32,32,32 },{ 0,2 },4 },{ { 256,32,32,32 },{ 0,2 },4 },{ { 288,32,32,32 },{ 0,2 },4 },{ { 320,32,32,32 },{ 0,2 },4 },{ { 352,32,32,32 },{ 0,2 },4 },{ { 0,32,32,32 },{ 0,2 },4 },{ { 32,32,32,32 },{ 0,2 },4 },{ { 64,32,32,32 },{ 0,2 },4 } } };
const SpriteData::AnimAndTimingList HyperLightDrifterLookUp = { 1,{ { { 32,0,32,32 },{ 0,0 },20 } } };
const SpriteData::AnimAndTimingList HyperLightDrifterWalkUp = { 12,{ { { 64,0,32,32 },{ 0,-2 },4 },{ { 96,0,32,32 },{ 0,-2 },4 },{ { 128,0,32,32 },{ 0,-2 },4 },{ { 160,0,32,32 },{ 0,-2 },4 },{ { 192,0,32,32 },{ 0,-2 },4 },{ { 224,0,32,32 },{ 0,-2 },4 },{ { 256,0,32,32 },{ 0,-2 },4 },{ { 288,0,32,32 },{ 0,-2 },4 },{ { 320,0,32,32 },{ 0,-2 },4 },{ { 352,0,32,32 },{ 0,-2 },4 },{ { 0,0,32,32 },{ 0,-2 },4 },{ { 32,0,32,32 },{ 0,-2 },4 } } };
const SpriteData::AnimAndTimingList HyperLightDrifterLookLeft = { 1,{ { { 64,64,32,32 },{ 0,0 },20 } } };
const SpriteData::AnimAndTimingList HyperLightDrifterWalkLeft = { 12,{ { { 96,64,32,32 },{ -2,0 },4 },{ { 128,64,32,32 },{ -2,0 },4 },{ { 160,64,32,32 },{ -2,0 },4 },{ { 192,64,32,32 },{ -2,0 },4 },{ { 224,64,32,32 },{ -2,0 },4 },{ { 256,64,32,32 },{ -2,0 },4 },{ { 288,64,32,32 },{ -2,0 },4 },{ { 320,64,32,32 },{ -2,0 },4 },{ { 352,64,32,32 },{ -2,0 },4 },{ { 0,64,32,32 },{ -2,0 },4 },{ { 32,64,32,32 },{ -2,0 },4 },{ { 64,64,32,32 },{ -2,0 },4 } } };
const SpriteData::AnimAndTimingList HyperLightDrifterLookRight = { 1,{ { { 64,96,32,32 },{ 0,0 },20 } } };
const SpriteData::AnimAndTimingList HyperLightDrifterWalkRight = { 12,{ { { 96,96,32,32 },{ 2,0 },4 },{ { 128,96,32,32 },{ 2,0 },4 },{ { 160,96,32,32 },{ 2,0 },4 },{ { 192,96,32,32 },{ 2,0 },4 },{ { 224,96,32,32 },{ 2,0 },4 },{ { 256,96,32,32 },{ 2,0 },4 },{ { 288,96,32,32 },{ 2,0 },4 },{ { 320,96,32,32 },{ 2,0 },4 },{ { 352,96,32,32 },{ 2,0 },4 },{ { 0,96,32,32 },{ 2,0 },4 },{ { 32,96,32,32 },{ 2,0 },4 },{ { 64,96,32,32 },{ 2,0 },4 } } };

const SpriteData HyperLightDrifter = {
	"HyperLightDrifter.png",8,{ &HyperLightDrifterLookDown, &HyperLightDrifterWalkDown, &HyperLightDrifterLookUp, &HyperLightDrifterWalkUp, &HyperLightDrifterLookLeft,
	&HyperLightDrifterWalkLeft, &HyperLightDrifterLookRight, &HyperLightDrifterWalkRight }
};

const SpriteData::AnimAndTimingList ExplosiveFlyRight = { 1,{ { { 20,196,196,179 },{ 0,0 },20 } } };
const SpriteData::AnimAndTimingList ExplosiveExplode = { 12,{ { { 216,196,196,179 },{ 0,0 },4 },{ { 412,196,196,179 },{ 0,0 },4 },
{ { 608,196,196,179 },{ 0,0 },4 },{ { 804,196,196,179 },{ 0,0 },4 },{ { 1000,196,196,179 },{ 0,0 },4 },{ { 1196,196,196,179 },{ 0,0 },4 },
{ { 1392,196,196,179 },{ 0,0 },4 },{ { 1588,196,196,179 },{ 0,0 },4 },{ { 1784,196,196,179 },{ 0,0 },4 },{ { 1980,196,196,179 },{ 0,0 },4 },
{ { 2176,196,196,179 },{ 0,0 },4 },{ { 2372,196,196,179 },{ 0,0 },8 } } };

const SpriteData Explosive = {
	"Explosive.png",2,{ &ExplosiveFlyRight, &ExplosiveExplode }
};


class Sprite {
public:
	const SpriteData* sData;
	Sprite(SDL_Texture* tex, const SpriteData* sd, const bool& autoDel) {
		sData = sd;
		objectInUse = true;
		autoDelete = autoDel;
		frameCnt = 0;
		curAnimFrameNum = 0;
		pushAnim(0);
		spriteTexture = tex;
	}
	/*void init(SDL_Texture* tex, const SpriteData* sd, const bool& autoDel) {
		sData = sd;
		objectInUse = true;
		autoDelete = autoDel;
		frameCnt = 0;
		curAnimFrameNum = 0;
		pushAnim(0);

		spriteTexture = tex;
		/*if (spriteTexture != NULL) SDL_DestroyTexture(spriteTexture);
		SDL_Surface* tmpSurface = IMG_Load(sData->path);
		spriteTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
		if (spriteTexture == NULL) {
			printf("Unable to create texture from %s! SDL Error: %s\n", sData->path, SDL_GetError());
		}
		SDL_FreeSurface(tmpSurface);
	};*/
	SDL_Texture* spriteTexture = NULL;

	static SDL_Texture* loadTexture(const char* path) {
		SDL_Surface* tmpSurface = IMG_Load(path);
		SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
		if (tmpTexture == NULL) {
			printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
		}
		SDL_FreeSurface(tmpSurface);
		return tmpTexture;
	}

	void pushAnim(const char& index) {
		if (animList.size() == 1) {
			animList.pop();
			frameCnt = 0;
			curAnimFrameNum = 0;
		}
		animList.push(index);
		mapPos.h = sData->animData[animList.front()]->list[curAnimFrameNum].frame.h;
		mapPos.w = sData->animData[animList.front()]->list[curAnimFrameNum].frame.w;
	}
	void pushAnim(const char& num, const char* data) {
		for (int i = 0; i < num; i++) {
			animList.push(data[i]);
		}
	}
	void setPos(const int& x, const int&y) {
		mapPos.x = x;
		mapPos.y = y;
	}
	const SDL_Rect& getFrameCoord();
	const SDL_Rect& getSpriteMapCoord() {
		return mapPos;
	}
	~Sprite() {
		//SDL_DestroyTexture(spriteTexture);
	};
	SDL_Rect mapPos;
	bool objectInUse;
	char curAnimFrameNum;
	char frameCnt;
	bool autoDelete;
	std::queue<char> animList;
};
Sprite *curSprite = NULL;

bool checkCollision(const SDL_Rect& pos) {
	for (int i = pos.y; i < pos.y + pos.h / 2; i++) {
		for (int j = pos.x - pos.w / 3; j < pos.x + (pos.w / 3); j++) {
			if ((j / 16) < map1breite && (i / 16) < map1hoehe && (map1walkdata[i / 16][j / 16] >> 5) == 7) {

				int bildmitteX = (resolutionX / 2);
				int bildmitteY = (resolutionY / 2);
				int ursprungX = bildmitteX - curSprite->mapPos.x;
				int ursprungY = bildmitteY - curSprite->mapPos.y;

				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 80);
				SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
				SDL_Rect collision;
				collision.x = ursprungX + pos.x - pos.w / 3;
				collision.y = ursprungY + pos.y;
				collision.h = pos.h / 2;
				collision.w = (pos.w / 3) * 2;
				SDL_RenderDrawRect(renderer, &collision);

				SDL_Rect object;
				object.x = ursprungX + (j / 16) * 16;
				object.y = ursprungY + (i / 16) * 16;
				object.h = 16;
				object.w = 16;
				SDL_RenderDrawRect(renderer, &object);

				SDL_SetRenderDrawColor(renderer, 100, 50, 150, 20);
				SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
				return true;
			}
		}
	}
	return false;
}

const SDL_Rect& Sprite::getFrameCoord() {
	if (animList.empty()) printf("AnimList empty\n");
	if (animList.size() == 0) printf("AnimList size 0\n");
	++frameCnt %= sData->animData[animList.front()]->list[curAnimFrameNum].displayDuration;
	if (frameCnt == 0) {
		++curAnimFrameNum %= sData->animData[animList.front()]->numFrames;
		if (curAnimFrameNum == 0 && animList.size() > 1) {
			animList.pop();
			mapPos.h = sData->animData[animList.front()]->list[curAnimFrameNum].frame.h;
			mapPos.w = sData->animData[animList.front()]->list[curAnimFrameNum].frame.w;
		}
		else if (autoDelete && curAnimFrameNum == 0 && animList.size() == 1) objectInUse = false;
	}
	SDL_Rect newPos;
	newPos.x = mapPos.x + sData->animData[animList.front()]->list[curAnimFrameNum].moveFrame.moveXPixel;//mapPos.x += sData->animData[animList.front()]->list[curAnimFrameNum].moveFrame.moveXPixel;
	newPos.y = mapPos.y + sData->animData[animList.front()]->list[curAnimFrameNum].moveFrame.moveYPixel;//mapPos.y += sData->animData[animList.front()]->list[curAnimFrameNum].moveFrame.moveYPixel;
	newPos.h = mapPos.h;
	newPos.w = mapPos.w;
	if (!checkCollision(newPos)) {
		mapPos.x = newPos.x;
		mapPos.y = newPos.y;
	}
	//SDL_Rect tmp = sData->animData[animList.front()]->list[curAnimFrameNum].frame;
	return sData->animData[animList.front()]->list[curAnimFrameNum].frame;
}

/*int threadFunction(void* data)
{
	printf("Running thread with value = %d\n", (int)data);
	return 0;
}*/

int main(int argc, char* args[])
{
	//int data = 101;
	//SDL_Thread* threadID = SDL_CreateThread(threadFunction, "LazyThread", (void*)data);

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError()); return -1;
	}

	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
	if (window == NULL) {
		printf("Window could not be created! SDL Error: %s\n", SDL_GetError()); return -1;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL) {
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError()); return -1;
	}
	IMG_Init(IMG_INIT_PNG);

	Uint32 time;
	//int resolutionX = 640;
	//int resolutionY = (resolutionX / 4) * 3;
	SDL_RenderSetLogicalSize(renderer, resolutionX, resolutionY);//(renderer, 320, 240);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	SDL_Surface *surface = SDL_LoadBMP("tilesAnim.bmp");
	if (surface == NULL) {
		printf("load bmp error: %s\n", SDL_GetError()); return -1;
	}
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	SDL_SetRenderDrawColor(renderer, 100, 50, 150, 20);

	SDL_Rect playerPos = { 0,0,0,0 }, srcRect = { 0,0,16,16 }, destRect = { 0,0,16,16 };
	int tileBlockNum, tileNum;
	int mapTopLeftX, mapTopLeftY, playerXOffset = 0, playerYOffset = 0, walkData, tileData;


	//sprite init - load map part
	SDL_Texture* tHiro = Sprite::loadTexture(Hiro.path);
	SDL_Texture* tCommando = Sprite::loadTexture(Commandos.path);
	SDL_Texture* tDiablo = Sprite::loadTexture(Diablo.path);
	SDL_Texture* tHyperLightDrifter = Sprite::loadTexture(HyperLightDrifter.path);
	SDL_Texture* tExplosive = Sprite::loadTexture(Explosive.path);
	std::vector<Sprite*> vSprites;
	Sprite* newSprite = new Sprite(tHiro, &Hiro, false);
	newSprite->setPos(100, 100);
	vSprites.push_back(newSprite);
	Sprite* pHiro1 = newSprite;
	curSprite = newSprite;
	newSprite = new Sprite(tCommando, &Commandos, false);
	newSprite->setPos(10, 10);
	vSprites.push_back(newSprite);
	newSprite = new Sprite(tDiablo, &Diablo, false);
	newSprite->setPos(150, 200);
	vSprites.push_back(newSprite);
	Sprite* pDiablo1 = newSprite;
	newSprite = new Sprite(tHyperLightDrifter, &HyperLightDrifter, false);
	newSprite->setPos(200, 200);
	vSprites.push_back(newSprite);
	newSprite = new Sprite(tDiablo, &Diablo, false);
	newSprite->setPos(200, 100);
	vSprites.push_back(newSprite);
	std::vector<Sprite*>::iterator itCurSprite = vSprites.begin();
	/*std::vector<Sprite*> vSprites;
	Sprite* newSprite = new Sprite;
	newSprite->init(&Hiro, false);
	newSprite->setPos(100, 100);
	vSprites.push_back(newSprite);
	Sprite* pHiro1 = newSprite;
	curSprite = newSprite;
	newSprite = new Sprite;
	newSprite->init(&Commandos, false);
	newSprite->setPos(10, 10);
	vSprites.push_back(newSprite);
	newSprite = new Sprite;
	newSprite->init(&Diablo, false);
	newSprite->setPos(150, 200);
	vSprites.push_back(newSprite);
	Sprite* pDiablo1 = newSprite;
	newSprite = new Sprite;
	newSprite->init(&HyperLightDrifter, false);
	newSprite->setPos(200, 200);
	vSprites.push_back(newSprite);
	newSprite = new Sprite;
	newSprite->init(&Diablo, false);
	newSprite->setPos(200, 100);
	vSprites.push_back(newSprite);
	std::vector<Sprite*>::iterator itCurSprite = vSprites.begin();*/

	char i, j;
	bool quit = 0;
	SDL_Event e;
	const Uint8* keystates;
	char tmpLastDir = 0, animSet = 0;
	while (!quit)
	{
		time = SDL_GetTicks();
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}
		keystates = SDL_GetKeyboardState(NULL);
		if (keystates[SDL_SCANCODE_UP]) {
			tmpLastDir = 1;
			if (!animSet) {
				animSet = 1;
				curSprite->pushAnim(3);
			}
		}
		else if (keystates[SDL_SCANCODE_DOWN]) {
			tmpLastDir = 0;
			if (!animSet) {
				animSet = 1;
				curSprite->pushAnim(1);
			}
		}
		else if (keystates[SDL_SCANCODE_LEFT]) {
			tmpLastDir = 2;
			if (!animSet) {
				animSet = 1;
				curSprite->pushAnim(5);
			}
		}
		else if (keystates[SDL_SCANCODE_RIGHT]) {
			tmpLastDir = 3;
			if (!animSet) {
				animSet = 1;
				curSprite->pushAnim(7);
			}
		}
		else if (keystates[SDL_SCANCODE_KP_PLUS]) {
			resolutionX -= 12;
			resolutionY = (resolutionX / 4) * 3;
			SDL_RenderSetLogicalSize(renderer, resolutionX, resolutionY);
		}
		else if (keystates[SDL_SCANCODE_KP_MINUS]) {
			resolutionX += 12;
			resolutionY = (resolutionX / 4) * 3;
			SDL_RenderSetLogicalSize(renderer, resolutionX, resolutionY);
		}
		else if (keystates[SDL_SCANCODE_KP_8]) {
		}
		else if (keystates[SDL_SCANCODE_KP_4]) {
		}
		else if (keystates[SDL_SCANCODE_KP_6]) {
			Sprite* newExplodeBulletRight = new Sprite(tExplosive, &Explosive, true);
			newExplodeBulletRight->setPos(curSprite->mapPos.x, curSprite->mapPos.y);
			vSprites.push_back(newExplodeBulletRight);
			const char explosivemove[] = { 0,0,1 };
			newExplodeBulletRight->pushAnim(3, explosivemove);
			itCurSprite = vSprites.begin();
			curSprite = newExplodeBulletRight;
			SDL_Delay(20);
		}
		else if (keystates[SDL_SCANCODE_KP_2]) {
			Sprite* newHyperLightDrifter = new Sprite(tHyperLightDrifter, &HyperLightDrifter, true);
			newHyperLightDrifter->setPos(100, 100);
			vSprites.push_back(newHyperLightDrifter);
			const char hyperlightdriftermove[] = { 7,7,1,1,5,5,3,3,7,7,1,1,5,5,3,3 };
			newHyperLightDrifter->pushAnim(16, hyperlightdriftermove);
			itCurSprite = vSprites.begin();
			SDL_Delay(50);
		}
		else if (keystates[SDL_SCANCODE_KP_3]) {
			curSprite->pushAnim((curSprite->animList.front() + 1) % curSprite->sData->numAnimations);
			SDL_Delay(200);
		}
		else if (keystates[SDL_SCANCODE_KP_0]) {
			if (++itCurSprite == vSprites.end())
				itCurSprite = vSprites.begin();
			curSprite = *itCurSprite;
			SDL_Delay(200);
		}
		else if (keystates[SDL_SCANCODE_KP_7]) {
			const char diablomove[] = {
				1,1,0,7,7,3,3,7,10,8,11,9
			};
			pDiablo1->pushAnim(12, diablomove);
			const char hiromove[] = {
				11,11,12,9,9,10,10,10,8,8,12,2,12,0
			};
			pHiro1->pushAnim(14, hiromove);
			SDL_Delay(200);
		}
		else {
			if (animSet) {
				curSprite->pushAnim(tmpLastDir * 2);
				animSet = 0;
			}
		}

		destRect.x = (resolutionX / 2) - (512 / 2) - curSprite->mapPos.x % 16;
		destRect.y = (resolutionY / 2) - (512 / 2) - curSprite->mapPos.y % 16;
		SDL_RenderClear(renderer);
		for (i = 0; i < 32; i++) {
			mapTopLeftY = (curSprite->mapPos.y / 16) - 16 + i;
			mapTopLeftX = (curSprite->mapPos.x / 16) - 17;
			for (j = 0; j < 32; j++) {
				++mapTopLeftX;

				if (mapTopLeftX >= map1breite || mapTopLeftX < 0 || mapTopLeftY >= map1hoehe || mapTopLeftY < 0) {
					tileNum = map1border;
					tileBlockNum = 0;
				}
				else {
					tileNum = map1tiledata[mapTopLeftY][mapTopLeftX];
					walkData = map1walkdata[mapTopLeftY][mapTopLeftX];
					tileBlockNum = (walkData >> 3) & 0x3;
				}

				srcRect.y = tileBlockNum * 512 + 16 * (tileNum / 8);
				srcRect.x = 16 * (tileNum % 8);

				if (tileBlockNum > 2) {//format: bit 7 6 5 (walk data), 4 3 (tile block num) 2 1 0 (pause count) )
					if (((walkData + 1) & 0x7) == 0) {
						if ((++tileNum % 8) == 0)
							map1tiledata[mapTopLeftY][mapTopLeftX] -= 7;
						else
							map1tiledata[mapTopLeftY][mapTopLeftX] = tileNum;
						map1walkdata[mapTopLeftY][mapTopLeftX] &= 0xf8;
					}
					else {
						map1walkdata[mapTopLeftY][mapTopLeftX] = (walkData & 0xf8) | ((walkData + 1) & 0x7);
					}
				}

				SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
				destRect.x += 16;
			}
			destRect.x = (resolutionX / 2) - (512 / 2) - curSprite->mapPos.x % 16;
			destRect.y += 16;
		}
		//sprite drawing order
		for (std::vector<Sprite*>::iterator it = vSprites.begin(); it != vSprites.end() - 1; ++it)
			for (std::vector<Sprite*>::iterator it2 = vSprites.begin(); it2 != vSprites.end() - 1; ++it2)
				if ((*it2)->mapPos.y + (*it2)->mapPos.h > (*(it2 + 1))->mapPos.y + (*(it2 + 1))->mapPos.h)
					std::iter_swap(it2, it2 + 1);
		//add sprites to BG
		for (std::vector<Sprite*>::iterator it = vSprites.begin(); it != vSprites.end();) {
			if ((*it)->objectInUse) {
				if ((abs((*it)->mapPos.x - curSprite->mapPos.x) < 250) && (abs((*it)->mapPos.y - curSprite->mapPos.y) < 250)) {
					const SDL_Rect* srcTmp = &(*it)->getFrameCoord();
					if ((*it)->objectInUse) {
						int bildmitteX = (resolutionX / 2);
						int bildmitteY = (resolutionY / 2);
						int ursprungX = bildmitteX - curSprite->mapPos.x;
						int ursprungY = bildmitteY - curSprite->mapPos.y;
						SDL_Rect tmp;
						tmp.h = (*it)->mapPos.h;
						tmp.w = (*it)->mapPos.w;
						tmp.x = ursprungX + (*it)->mapPos.x;
						tmp.y = ursprungY + (*it)->mapPos.y;

						tmp.x -= (*it)->mapPos.w / 2;
						tmp.y -= (*it)->mapPos.h / 2;

						SDL_RenderCopy(renderer, (*it)->spriteTexture, srcTmp, &tmp);
					}
				}
				++it;
			}
			else {
				if (curSprite == (*it)) curSprite = NULL;
				delete *it;
				it = vSprites.erase(it);
				if (it == vSprites.end()) it = vSprites.begin();
				itCurSprite = it;
				if (curSprite == NULL) curSprite = *itCurSprite;
				/*

				if (curSprite == (*it)) {
					delete *it;
					it = vSprites.erase(it);
					if (it == vSprites.end()) {
						curSprite = *vSprites.begin();
						itCurSprite = vSprites.begin();
					}
					else {
						curSprite = *it;
						itCurSprite = it;
					}
				}
				else {
					delete *it;
					it = vSprites.erase(it);
					itCurSprite = it;
				}
				if (it == vSprites.end())itCurSprite = vSprites.begin();
				else
					itCurSprite = it;*/
			}
		}
		/*
		char spriteOrder[] = { 0,1,2,3,4,5,6,7,8,9 };
		for (i = 0; i < 9; i++)
			for (j = 0; j < 9; j++)
				if (sprites[spriteOrder[j]].mapPos.y + sprites[spriteOrder[j]].mapPos.h > sprites[spriteOrder[j + 1]].mapPos.y + sprites[spriteOrder[j + 1]].mapPos.h)
					std::swap(spriteOrder[j], spriteOrder[j + 1]);
		//add sprites to BG
		for (i = 0; i < 10; i++) {
			j = spriteOrder[i];
			if (sprites[j].objectInUse) {
				if ((abs(sprites[j].mapPos.x - curSprite->mapPos.x) < 250) && (abs(sprites[j].mapPos.y - curSprite->mapPos.y) < 250)) {
					const SDL_Rect* srcTmp = &sprites[j].getFrameCoord();

					int bildmitteX = (resolutionX / 2);
					int bildmitteY = (resolutionY / 2);
					int ursprungX = bildmitteX - curSprite->mapPos.x;
					int ursprungY = bildmitteY - curSprite->mapPos.y;
					SDL_Rect tmp;
					tmp.h = sprites[j].mapPos.h;
					tmp.w = sprites[j].mapPos.w;
					tmp.x = ursprungX + sprites[j].mapPos.x;
					tmp.y = ursprungY + sprites[j].mapPos.y;

					tmp.x -= sprites[j].mapPos.w / 2;
					tmp.y -= sprites[j].mapPos.h / 2;

					SDL_RenderCopy(renderer, sprites[j].spriteTexture, srcTmp, &tmp);
				}
			}
		}
		*/
		SDL_RenderPresent(renderer);
		//SDL_Delay(100);
		if (20 > (SDL_GetTicks() - time)) SDL_Delay(20 - (SDL_GetTicks() - time));
	}
	SDL_DestroyWindow(window);
	//SDL_WaitThread(threadID, NULL);
	IMG_Quit();
	SDL_Quit();
	return 0;
}