#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <SDL_thread.h>

int BG[32][32] = {
	{ 7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7 },
	{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,626,627,628,629,1,1,1,1,1,1,1,1,7 },
	{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,632,633,634,635,636,637,638,639,1,1,1,1,1,1,7 },
	{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,640,641,642,643,644,645,646,647,1,1,1,1,1,1,7 },
	{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,648,649,650,651,652,653,654,655,1,1,1,1,1,1,7 },
	{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,656,657,658,659,660,661,662,663,1,1,1,1,1,1,7 },
	{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7 },
	{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7 },
	{ 7,1,1,1,1,1,1,21248,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7 },
	{ 7,1,1,1,1,1,1,1,1,1,1,1,13,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7 },
	{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7 },
	{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7 },
	{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7 },
	{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7 },
	{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,600,601,1,1,1,7 },
	{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,608,609,1,1,1,7 },
	{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,616,617,1,1,1,7 },
	{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7 },
	{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7 },
	{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7 },
	{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7 },
	{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7 },
	{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7 },
	{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7 },
	{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7 },
	{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7 },
	{ 7,21256,21264,21296,21248,21264,21296,21248,21248,21248,21248,21296,21296,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,7 },
	{ 7,21256,21256,21248,21248,21264,21264,21248,21248,21248,21248,21296,21296,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,7 },
	{ 7,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,21248,7 },
	{ 7,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,7 },
	{ 7,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,21504,7 },
	//{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7 },
	//{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7 },
	//{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7 },
	//{ 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7 },
	{ 7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7 }
};

int threadFunction(void* data)
{
	printf("Running thread with value = %d\n", (int)data);
	return 0;
}

int main(int argc, char* args[])
{

	int data = 101;
	SDL_Thread* threadID = SDL_CreateThread(threadFunction, "LazyThread", (void*)data);
	


	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0){
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError()); return -1;
	}
	
	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
	if (window == NULL){
		printf("Window could not be created! SDL Error: %s\n", SDL_GetError()); return -1;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL){
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError()); return -1;
	}

	Uint32 time;
	int resolutionX = 640;
	int resolutionY = (resolutionX / 4) * 3;
	SDL_RenderSetLogicalSize(renderer, resolutionX, resolutionY);//(renderer, 320, 240);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	SDL_Surface *surface = SDL_LoadBMP("tilesAnim.bmp");
	if (surface == NULL){
		printf("load bmp error: %s\n", SDL_GetError()); return -1;
	}
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer,surface);
	SDL_FreeSurface(surface);	
	SDL_SetRenderDrawColor(renderer, 100, 50, 150, 20);

	SDL_Rect curPos = { 0,0,0,0 }, srcRect = { 0,0,16,16 }, destRect = { 0,0,16,16 };
	int tileNum;
		
	int wrapAroundRight = (512 / 2) + (resolutionX / 2);
	int wrapAroundLeft = (-512 / 2) + (resolutionX / 2);
	int wrapAroundTop = (-512 / 2) + (resolutionY / 2);
	int wrapAroundBottom = (512 / 2) + (resolutionY / 2);

	bool quit = 0;
	SDL_Event e;
	while (!quit)
	{
		time = SDL_GetTicks();
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			else if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_UP:
					curPos.y += 2;
					break;

				case SDLK_DOWN:
					curPos.y -= 2;
					break;

				case SDLK_LEFT:
					curPos.x += 2;
					break;

				case SDLK_RIGHT:
					curPos.x -= 2;
					break;

				case SDLK_KP_PLUS:
					resolutionX -= 24;

				case SDLK_KP_MINUS:
					resolutionX += 12;
					resolutionY = (resolutionX / 4) * 3;
					SDL_RenderSetLogicalSize(renderer, resolutionX, resolutionY);
					wrapAroundRight = (512 / 2) + (resolutionX / 2);
					wrapAroundLeft = (-512 / 2) + (resolutionX / 2);
					wrapAroundTop = (-512 / 2) + (resolutionY / 2);
					wrapAroundBottom = (512 / 2) + (resolutionY / 2);
					break;

				default:
					break;
				}

				if (curPos.x >= 512)curPos.x -= 512;
				else if (curPos.x < 0)curPos.x += 512;
				if (curPos.y >= 512)curPos.y -= 512;
				else if (curPos.y < 0)curPos.y += 512;
			}
		}
		destRect.x = (resolutionX / 2) - (512 / 2) + curPos.x;
		destRect.y = (resolutionY / 2) - (512 / 2) + curPos.y;
		SDL_RenderClear(renderer);
		for (int i = 0; i < 32; i++) {
			for (int j = 0; j < 32; j++) {
				tileNum = BG[i][j];

				if (tileNum < 664) {//664 erstes anim tile
					srcRect.y = 16 * (tileNum / 8);
					srcRect.x = 16 * (tileNum % 8);
				}
				else {//format: byte 4 3 2 (zeilennummer), 1 (bit 7/6/ 543 (tileno) 210 (pause count) )
					tileNum = (tileNum & 0xffffff00) | (tileNum + 1 & 0x3f);
					BG[i][j] = tileNum;
					srcRect.y = 16 * (tileNum >> 8);
					srcRect.x = 16 * ((tileNum >> 3) & 0x7);
				}

				SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
				destRect.x += 16;
				if (destRect.x >= wrapAroundRight) destRect.x = wrapAroundLeft + (destRect.x - wrapAroundRight);
			}
			destRect.y += 16;
			if (destRect.y >= wrapAroundBottom) destRect.y = wrapAroundTop + (destRect.y - wrapAroundBottom);
		}
		SDL_RenderPresent(renderer);

		if (20 > (SDL_GetTicks() - time)) SDL_Delay(20 - (SDL_GetTicks() - time)); //SDL_Delay pauses the execution.
	}
	SDL_DestroyWindow(window);
	SDL_WaitThread(threadID, NULL);
	SDL_Quit();
	return 0;
}