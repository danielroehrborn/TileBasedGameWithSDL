#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <SDL_thread.h>

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

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
	{ 0,0,0,0,0,24,24,24,24,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,24,24,24,24,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
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
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
};
class SpriteData {
public:
	class AnimAndTiming {
	public:
		const SDL_Rect frame;
		const char time;
		const char moveSpeed;
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
const SpriteData::AnimAndTimingList HiroLookDown = { 1,{ {{1,34,32,32},16,1} } };
const SpriteData::AnimAndTimingList HiroWalkDown = { 4,{ {{34,34,32,32},12,1}, {{1,34,32,32},12,1 }, {{67,34,32,32},12,1 }, {{1,34,32,32},12,1 } } };
const SpriteData::AnimAndTimingList HiroLookUp = { 1,{ {{1,1,32,32},12,1 } } };
const SpriteData::AnimAndTimingList HiroWalkUp = { 4,{ {{34,1,32,32 },12,3 }, {{1,1,32,32},12,3 }, {{67,1,32,32},12,3 }, {{1,1,32,32},12,3 } } };
const SpriteData::AnimAndTimingList HiroLookLeft = { 1,{ {{1,67,32,32},16,1 } } };
const SpriteData::AnimAndTimingList HiroWalkLeft = { 4,{ {{34,67,32,32},12,1 }, {{1,67,32,32},12,0 }, {{67,67,32,32},12,1 }, {{1,67,32,32},12,0 } } };
const SpriteData::AnimAndTimingList HiroLookRight = { 1,{ {{1,100,32,32},16,1} } };
const SpriteData::AnimAndTimingList HiroWalkRight = { 4,{ {{34,100,32,32},10,1 }, {{1,100,32,32},8,1 }, {{67,100,32,32},10,1 }, {{1,100,32,32},8,1 } } };
const SpriteData::AnimAndTimingList HiroRunDown = { 4,{ {{166,34,32,32},8,3 }, {{133,34,32,32},6,2 }, {{199,34,32,32},8,3 }, {{133,34,32,32},6,2 } } };
const SpriteData::AnimAndTimingList HiroRunUp = { 4,{ { { 166,1,32,32 },8,3 },{ { 133,1,32,32 },6,2 },{ { 199,1,32,32 },8,3 },{ { 133,1,32,32 },6,2 } } };
const SpriteData::AnimAndTimingList HiroRunLeft = { 4,{ { { 166,67,32,32 },8,3 },{ { 133,67,32,32 },6,2 },{ { 199,67,32,32 },8,3 },{ { 133,67,32,32 },6,2 } } };
const SpriteData::AnimAndTimingList HiroRunRight = { 4,{ { { 166,100,32,32 },8,3 },{ { 133,100,32,32 },6,2 },{ { 199,100,32,32 },8,3 },{ { 133,100,32,32 },6,2 } } };
const SpriteData::AnimAndTimingList HiroAngelDown = { 4,{ { { 1,594,64,64 },12,0 },{ { 66,594,64,64 },8,0 },{ { 131,594,64,64 },4,0 },{ { 196,594,64,64 },12,0 } } };
const SpriteData Hiro = {
	"HiroSprites.png",13,{ &HiroLookDown, &HiroWalkDown, &HiroLookUp, &HiroWalkUp, &HiroLookLeft,
	&HiroWalkLeft, &HiroLookRight, &HiroWalkRight, &HiroRunDown, &HiroRunUp, &HiroRunLeft, &HiroRunRight, &HiroAngelDown }
};

class Sprite {
public:
	const SpriteData* sData;
	Sprite() {
		curAnimNum = NULL;
		objectInUse = NULL;
		animated = NULL;
	}
	void init(const SpriteData* sd) {
		sData = sd;
		curAnimNum = 0;
		objectInUse = true;
		animated = false;
		movementSpeed = 2;

		if (spriteTexture != NULL) SDL_DestroyTexture(spriteTexture);
		SDL_Surface* tmpSurface = IMG_Load(sData->path);
		spriteTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
		if (spriteTexture == NULL) {
			printf("Unable to create texture from %s! SDL Error: %s\n", sData->path, SDL_GetError());
		}
		SDL_FreeSurface(tmpSurface);
	};
	SDL_Texture* spriteTexture = NULL;

	void setAnim(const char& index) {
		curAnimNum = index%sData->numAnimations;
		mapPos.h = sData->animData[curAnimNum]->list[0].frame.h;
		mapPos.w = sData->animData[curAnimNum]->list[0].frame.w;
		animate(false);
	}
	void animate(const bool& activate, const bool& oneShotNotLoop = 0) {
		animated = activate;
		this->oneShotNotLoop = oneShotNotLoop;
		curAnimFrameNum = 0;
		frameCnt = 0;
	}
	void setPos(const char& x, const char&y) {
		mapPos.x = x;
		mapPos.y = y;
	}
	const SDL_Rect& getFrameCoord() {
		if (animated) {
			++frameCnt %= sData->animData[curAnimNum]->list[curAnimFrameNum].time;
			if (frameCnt == 0) {
				++curAnimFrameNum %= sData->animData[curAnimNum]->numFrames;
				if (curAnimFrameNum == 0 && oneShotNotLoop)
					animate(false);
			}
		}
		return sData->animData[curAnimNum]->list[curAnimFrameNum].frame;
	}
	const SDL_Rect& getSpriteMapCoord() {
		return mapPos;
	}
	const char getSpeed() {
		return sData->animData[curAnimNum]->list[curAnimFrameNum].moveSpeed;
	}
	~Sprite() {
		SDL_DestroyTexture(spriteTexture);
	};
	SDL_Rect mapPos;
	char curAnimNum;
	bool objectInUse;
	char curAnimFrameNum;
	char frameCnt;
	bool animated;
	bool oneShotNotLoop;
	char movementSpeed;
};
Sprite sprites[10];

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
	int resolutionX = 640;
	int resolutionY = (resolutionX / 4) * 3;
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
	sprites[0].init(&Hiro);
	sprites[0].setAnim(0);
	sprites[0].setPos(100, 100);
	Sprite *curSprite = &sprites[0];
	sprites[1].init(&Hiro);
	sprites[1].setAnim(0);
	sprites[1].setPos(0, 0);

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
			curSprite->mapPos.y -= curSprite->getSpeed();
			tmpLastDir = 1;
			if (!animSet) {
				animSet = 1;
				curSprite->setAnim(9);//3
				curSprite->animate(true);
			}
		}
		else if (keystates[SDL_SCANCODE_DOWN]) {
			curSprite->mapPos.y += curSprite->getSpeed();
			tmpLastDir = 0;
			if (!animSet) {
				animSet = 1;
				curSprite->setAnim(8);//0
				curSprite->animate(true);
			}
		}
		else if (keystates[SDL_SCANCODE_LEFT]) {
			curSprite->mapPos.x -= curSprite->getSpeed();
			tmpLastDir = 2;
			if (!animSet) {
				animSet = 1;
				curSprite->setAnim(10);//5
				curSprite->animate(true);
			}
		}
		else if (keystates[SDL_SCANCODE_RIGHT]) {
			curSprite->mapPos.x += curSprite->getSpeed();
			tmpLastDir = 3;
			if (!animSet) {
				animSet = 1;
				curSprite->setAnim(11);//7
				curSprite->animate(true);
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
			sprites[1].mapPos.y -= 2;
		}
		else if (keystates[SDL_SCANCODE_KP_4]) {
			sprites[1].mapPos.x -= 2;
		}
		else if (keystates[SDL_SCANCODE_KP_6]) {
			sprites[1].mapPos.x += 2;
		}
		else if (keystates[SDL_SCANCODE_KP_2]) {
			sprites[1].mapPos.y += 2;
		}
		else if (keystates[SDL_SCANCODE_KP_1]) {
			sprites[1].animate(!sprites[1].animated,true);
			SDL_Delay(200);
		}
		else if (keystates[SDL_SCANCODE_KP_3]) {
			char tmp = (sprites[1].curAnimNum + 1) % sprites[1].sData->numAnimations;
			sprites[1].setAnim(tmp);
			SDL_Delay(200);
		}
		else if (keystates[SDL_SCANCODE_KP_0]) {
			if(curSprite== &sprites[0])
			curSprite = &sprites[1];
			else curSprite = &sprites[0];
			SDL_Delay(200);
		}
		else {
			if (animSet) {
				curSprite->setAnim(tmpLastDir * 2);
				animSet = 0;
			}
		}

		destRect.x = (resolutionX / 2) - (512 / 2) - curSprite->mapPos.x % 16;//destRect.x = (resolutionX / 2) - (512 / 2) + playerXOffset;
		destRect.y = (resolutionY / 2) - (512 / 2) - curSprite->mapPos.y % 16;//destRect.y = (resolutionY / 2) - (512 / 2) + playerYOffset;
		SDL_RenderClear(renderer);
		for (i = 0; i < 32; i++) {
			mapTopLeftY = (curSprite->mapPos.y / 16) - 16 + i;//mapTopLeftY = playerPos.y - 16 + i;
			mapTopLeftX = (curSprite->mapPos.x / 16) - 16;//mapTopLeftX = playerPos.x - 16;
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
			destRect.x = (resolutionX / 2) - (512 / 2) - curSprite->mapPos.x % 16;//destRect.x = (resolutionX / 2) - (512 / 2) + playerXOffset;
			destRect.y += 16;
		}
		/*add sprites to BG*/
		for (i = 0; i < 10; i++) {
			if (sprites[i].objectInUse) {
				if ((abs(sprites[i].mapPos.x - curSprite->mapPos.x) < 250) && (abs(sprites[i].mapPos.y - curSprite->mapPos.y) < 250)) {
					int bildmitteX = (resolutionX / 2);
					int bildmitteY = (resolutionY / 2);
					int ursprungX = bildmitteX - curSprite->mapPos.x;
					int ursprungY = bildmitteY - curSprite->mapPos.y;
					SDL_Rect tmp;
					tmp.h = sprites[i].mapPos.h;
					tmp.w = sprites[i].mapPos.w;
					tmp.x = ursprungX + sprites[i].mapPos.x;
					tmp.y = ursprungY + sprites[i].mapPos.y;

					tmp.x -= sprites[i].mapPos.w / 2;
					tmp.y -= sprites[i].mapPos.h / 2;

					//SDL_RenderCopy(renderer, sprites[i].spriteTexture, &sprites[i].getFrameCoord(), &sprites[i].getSpriteMapCoord());
					//SDL_RenderCopy(renderer, sprites[i].spriteTexture, &sprites[i].framePos, &tmp);// &sprites[i].mapPos);
					SDL_RenderCopy(renderer, sprites[i].spriteTexture, &sprites[i].getFrameCoord(), &tmp);
				}
			}
		}

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