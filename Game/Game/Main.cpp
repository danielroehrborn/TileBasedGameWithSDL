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
const char* pathHiroSprite = "HiroSprites.png";
const char spriteHiroAnimNum = 2;
const SDL_Rect spriteHiroAnimPositions[] = { {1,1,32,33},{1,34,32,33} };//hwxy
const char spriteHiroFramesPerAnim[] = { 3,3 };


class Sprite {
public:
	const char* spriteImagePath;
	char numberOfAnimations;
	const SDL_Rect* animationPositions;
	const char* framesPerAnimation;
	Sprite() {
		spriteImagePath = NULL;
		numberOfAnimations = NULL;
		animationPositions = NULL;
		framesPerAnimation = NULL;
		curAnimPos = NULL;
		inUse = NULL;
		animated = NULL;
	}
	void init(const char* path, const char &animNum, const SDL_Rect* animPos, const char* framesPerAnim) {
		spriteImagePath = path;
		numberOfAnimations = animNum;
		animationPositions = animPos;
		framesPerAnimation = framesPerAnim;
		curAnimPos = 0;
		inUse = true;
		animated = false;
		movementSpeed = 2;

		if (spriteTexture != NULL) SDL_DestroyTexture(spriteTexture);
		SDL_Surface* tmpSurface = IMG_Load(path);
		spriteTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
		if (spriteTexture == NULL) {
			printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
		}
		SDL_FreeSurface(tmpSurface);
	};
	SDL_Texture* spriteTexture = NULL;

	void setAnim(const char& index) {
		framePos = animationPositions[index];
		mapPos = framePos;
		curFrame = 0;
	}
	void setPos(const char& x, const char&y) {
		mapPos.x = x;
		mapPos.y = y;
	}
	const SDL_Rect& getFrameCoord() {
		/*if (animated) {
			++frameCnt %= 8;
			if (frameCnt == 0) {
				++curFrame %= framesPerAnimation[curAnimPos];
				if (curFrame == 0) {
					framePos.x = animationPositions[curAnimPos].x;
				}
				else {
					framePos.x += framePos.w;
				}
			}
		}
		else */return framePos;
		
	}
	const SDL_Rect& getSpriteMapCoord() {
		return mapPos;
	}

	~Sprite() {
		SDL_DestroyTexture(spriteTexture);
	};
	SDL_Rect mapPos;
	SDL_Rect framePos;
	char curAnimPos;
	bool inUse;
	char curFrame;
	char frameCnt;
	bool animated;
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
	sprites[0].init(pathHiroSprite, spriteHiroAnimNum, spriteHiroAnimPositions, spriteHiroFramesPerAnim);
	sprites[0].setAnim(0);
	sprites[0].setPos(100, 100);
	Sprite *curSprite = &sprites[0];
	sprites[1].init(pathHiroSprite, spriteHiroAnimNum, spriteHiroAnimPositions, spriteHiroFramesPerAnim);
	sprites[1].setAnim(0);
	sprites[1].setPos(0, 0);

	char i, j;
	bool quit = 0;
	SDL_Event e;
	const Uint8* keystates;
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
			curSprite->mapPos.y -= curSprite->movementSpeed;
			/*playerYOffset += 2;
			if (playerYOffset > 15) {
				playerYOffset = 0;
				playerPos.y--;
			}*/
		}
		else if (keystates[SDL_SCANCODE_DOWN]) {
			curSprite->mapPos.y += curSprite->movementSpeed;
			/*playerYOffset -= 2;
			if (playerYOffset < 0) {
				playerYOffset = 14;
				playerPos.y++;
			}*/
		}
		else if (keystates[SDL_SCANCODE_LEFT]) {
			curSprite->mapPos.x -= curSprite->movementSpeed;
			/*playerXOffset += 2;
			if (playerXOffset > 15) {
				playerXOffset = 0;
				playerPos.x--;
			}*/
		}
		else if (keystates[SDL_SCANCODE_RIGHT]) {
			curSprite->mapPos.x += curSprite->movementSpeed;
			/*playerXOffset -= 2;
			if (playerXOffset < 0) {
				playerXOffset = 14;
				playerPos.x++;
			}*/
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
			if (sprites[i].inUse) {
				int bildmitteX = (resolutionX / 2);
				int bildmitteY = (resolutionY / 2);
				int ursprungX = bildmitteX - curSprite->mapPos.x;
				int ursprungY = bildmitteY - curSprite->mapPos.y;
				SDL_Rect tmp;
				tmp.h = curSprite->mapPos.h;
				tmp.w = curSprite->mapPos.w;
				tmp.x = ursprungX + sprites[i].mapPos.x;
				tmp.y = ursprungY + sprites[i].mapPos.y;

				//SDL_RenderCopy(renderer, sprites[i].spriteTexture, &sprites[i].getFrameCoord(), &sprites[i].getSpriteMapCoord());
				SDL_RenderCopy(renderer, sprites[i].spriteTexture, &sprites[i].framePos, &tmp);// &sprites[i].mapPos);
			}
		}

		SDL_RenderPresent(renderer);

		if (20 > (SDL_GetTicks() - time)) SDL_Delay(20 - (SDL_GetTicks() - time));
	}
	SDL_DestroyWindow(window);
	//SDL_WaitThread(threadID, NULL);
	IMG_Quit();
	SDL_Quit();
	return 0;
}