#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <SDL_thread.h>
#include <queue>
#include "Map.h"
#include "Sprite.h"
#include "SpriteGroup.h"
#include "SpriteData.h"
#include "SpriteGroupData.h"
#include "Hiro.h"
#include "Commandos.h"
#include "Diablo.h"
#include "HyperLightDrifter.h"
#include "Explosive.h"
#include "Switch.h"
#include "Ent.h"
#include "DungeonSprites.h"
#include "Ship.h"
#include "GenericSprite.h"
#include "Event.h"

const MapData* const mapIDs[] = {
	&map1Data,	//ID: 0
	&map2Data,  //ID: 1
	&map3Data,	//ID: 2
	&mapDungeonData //ID: 3
};
const MapData* curMap = &map1Data;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture *tilemapTexture;
unsigned char tilemapNumColumns;
Sprite *curSprite = NULL;
SDL_Rect curCamera;
bool detachedCamera = false;
std::vector<Sprite*> vSprites;
std::vector<SpritePersistanceData*> vPersistantSprites;
unsigned char vSprites_curSpriteNum = 0;
unsigned int resolutionX = 640, newResolutionX = 0;
unsigned int resolutionY = (resolutionX / 4) * 3;
unsigned const char bghoehe = 100, bgbreite = 100;
unsigned char bgTiles[bghoehe*bgbreite] = {};
unsigned char bgWalk[bghoehe*bgbreite] = {};
unsigned char curMapID = 0;
unsigned char lastMapID = 0;
unsigned char curColorRed = 255, curColorGreen = 255, curColorBlue = 255;

Sprite* newSprite = NULL;
void loadMap(unsigned const char& newMapID) {
	curMapID = newMapID;//static unsigned char lastMapID = mapID;
	//clear bg map
	curMap = mapIDs[newMapID];
	for (int i = bghoehe*bgbreite; i--;) {
		bgTiles[i] = curMap->borderTile;
		bgWalk[i] = 0;
	}
	//copy map to bg
	int topLeftIndex = 8 * bgbreite + 8; //int topLeftIndex = (bghoehe / 2 - curMap->height / 2) * bgbreite + bgbreite / 2 - curMap->width / 2;
	int curMapTileIndex = 0;
	for (int i = 0; i < curMap->height; i++) {
		for (int j = 0; j < curMap->width; j++) {
			bgTiles[topLeftIndex + j] = curMap->tileData[curMapTileIndex];
			bgWalk[topLeftIndex + j] = curMap->walkData[curMapTileIndex];
			++curMapTileIndex;
		}
		topLeftIndex += bgbreite;
	}
	//load connection strips
	const char NorthConnectedMapID = curMap->connectionData[MapData::North].mapID;
	if (NorthConnectedMapID != -1) {
		const MapData* NorthConnectedMap = mapIDs[curMap->connectionData[MapData::North].mapID];
		int ConnStripIndex = (NorthConnectedMap->height - 8) * NorthConnectedMap->width;
		for (int i = curMap->connectionData[MapData::North].yOffset; i < curMap->connectionData[MapData::North].yOffset + 8; i++) {
			for (int j = 0; j < NorthConnectedMap->width; j++) {
				if (i >= 0 && i < bghoehe && j + curMap->connectionData[MapData::North].xOffset >= 0 && j + curMap->connectionData[MapData::North].xOffset < bgbreite) {
					bgTiles[i*bgbreite + j + curMap->connectionData[MapData::North].xOffset] = NorthConnectedMap->tileData[ConnStripIndex];
					bgWalk[i*bgbreite + j + curMap->connectionData[MapData::North].xOffset] = NorthConnectedMap->walkData[ConnStripIndex];
				}
				++ConnStripIndex;
			}
		}
	}
	const MapData::ConnectionData southConnection = curMap->connectionData[MapData::South];
	if (southConnection.mapID != -1) {
		const MapData* SouthConnectedMap = mapIDs[southConnection.mapID];
		unsigned int ConnStripIndex = 0;
		int curBgRow = curMap->height + 8 + southConnection.yOffset;
		int curBgColumn = southConnection.xOffset;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < SouthConnectedMap->width; j++) {
				if (curBgRow + i >= 0 && curBgRow + i < bghoehe && curBgColumn + j >= 0 && curBgColumn + j < bgbreite) {
					bgTiles[(curBgRow + i) * bgbreite + curBgColumn + j] = SouthConnectedMap->tileData[ConnStripIndex];
					bgWalk[(curBgRow + i) * bgbreite + curBgColumn + j] = SouthConnectedMap->walkData[ConnStripIndex];
				}
				++ConnStripIndex;
			}
		}
	}
	const MapData::ConnectionData westConnection = curMap->connectionData[MapData::West];
	if (westConnection.mapID != -1) {
		const MapData* WestConnectedMap = mapIDs[westConnection.mapID];
		unsigned int ConnStripIndex = WestConnectedMap->width - 8;
		int curBgRow = westConnection.yOffset;
		int curBgColumn = westConnection.xOffset;
		for (int i = 0; i < WestConnectedMap->height; i++) {
			for (int j = 0; j < 8; j++) {
				if (curBgRow + i >= 0 && curBgRow + i < bghoehe && curBgColumn + j >= 0 && curBgColumn + j < bgbreite) {
					bgTiles[(curBgRow + i) * bgbreite + curBgColumn + j] = WestConnectedMap->tileData[ConnStripIndex + j];
					bgWalk[(curBgRow + i) * bgbreite + curBgColumn + j] = WestConnectedMap->walkData[ConnStripIndex + j];
				}
			}
			ConnStripIndex += WestConnectedMap->width;
		}
	}
	const MapData::ConnectionData eastConnection = curMap->connectionData[MapData::East];
	if (eastConnection.mapID != -1) {
		const MapData* EastConnectedMap = mapIDs[eastConnection.mapID];
		unsigned int ConnStripIndex = 0;
		int curBgRow = eastConnection.yOffset;
		int curBgColumn = curMap->width + 8 + eastConnection.xOffset;
		for (int i = 0; i < EastConnectedMap->height; i++) {
			for (int j = 0; j < 8; j++) {
				if (curBgRow + i >= 0 && curBgRow + i < bghoehe && curBgColumn + j >= 0 && curBgColumn + j < bgbreite) {
					bgTiles[(curBgRow + i) * bgbreite + curBgColumn + j] = EastConnectedMap->tileData[ConnStripIndex + j];
					bgWalk[(curBgRow + i) * bgbreite + curBgColumn + j] = EastConnectedMap->walkData[ConnStripIndex + j];
				}
			}
			ConnStripIndex += EastConnectedMap->width;
		}
	}
	//load new tilemap
	SDL_Surface *surface = SDL_LoadBMP(curMap->pathTileset);
	if (surface == NULL) {
		printf("load bmp error: %s\n", SDL_GetError()); return;
	}
	tilemapTexture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	tilemapNumColumns = curMap->numColumnsTileset;
	//delete all sprites
	SpritePersistanceData* pData, *curSpritePData = curSprite != NULL ? curSprite->pData : NULL;
	if (vSprites.size() > 0)
		for (std::vector<Sprite*>::iterator it = vSprites.begin(); it != vSprites.end(); it++) {
			if ((*it)->pData != NULL && (*it)->pData->curMapID == lastMapID) {
				pData = (*it)->pData;
				pData->sData = (*it)->sData;
				pData->curMapID = lastMapID;
				pData->mapPos = (*it)->mapPos;
				pData->curAnim = (*it)->animList.front();
			}
			delete *it;
		}
	vSprites.clear();
	curSprite = NULL;//new
	//load new map sprites -> zuk�nftig in state machine
	for (unsigned char spriteNum = 0; spriteNum < curMap->numSprites; ++spriteNum) {
		newSprite = new Sprite(curMap->sprites[spriteNum].sprite, false);
		newSprite->setPos((curMap->sprites[spriteNum].mapPos.x + 8) * 16, (curMap->sprites[spriteNum].mapPos.y + 8) * 16);
		newSprite->pushAnim(curMap->sprites[spriteNum].curAnim);
		vSprites.push_back(newSprite);
	}
	//load persistant sprites
	for (std::vector<SpritePersistanceData*>::iterator it = vPersistantSprites.begin(); it != vPersistantSprites.end(); it++) {
		if ((*it)->curMapID == newMapID) {
			pData = *it;
			newSprite = new Sprite(pData->sData, false);
			newSprite->mapPos = pData->mapPos;
			newSprite->pushAnim(pData->curAnim);
			newSprite->pData = pData;
			vSprites.push_back(newSprite);
			if (curSpritePData == pData) curSprite = newSprite; //new
		}
	}
	if (curSprite == NULL)
		curSprite = *vSprites.begin();
	curCamera.x = curSprite->mapPos.x;//new
	curCamera.y = curSprite->mapPos.y;//new
	lastMapID = newMapID;

	unsigned char eventNum;
	EventManagement::delAllEvents();
	//load warp events
	/*const WarpEventData::WarpEventPos* curWarpEvent;
	for (eventNum = 0; eventNum < curMap->warpEvents->numWarpEvents; ++eventNum) {
		curWarpEvent = &curMap->warpEvents->wepList[eventNum];
		if (curWarpEvent->spriteNum != -1)
			EventManagement::addEvent(new WarpEvent(vSprites[curWarpEvent->spriteNum], curWarpEvent->destMapID,
				curWarpEvent->destXGridPos, curWarpEvent->destYGridPos), false);
		else
			EventManagement::addEvent(new WarpEvent(curWarpEvent->xGridPos, curWarpEvent->yGridPos, 0, 0,
				curWarpEvent->destMapID, curWarpEvent->destXGridPos, curWarpEvent->destYGridPos), false);
	}*/
	//load anim events
	/*const AnimEventData::AnimEventPos* curAnimEvent;
	for (eventNum = 0; eventNum < curMap->animEvents->numAnimEvents; ++eventNum) {
		curAnimEvent = &curMap->animEvents->aepList[eventNum];
		if (curAnimEvent->spriteNum != -1)
			new ChangeAnimEvent(vSprites[curAnimEvent->spriteNum], curAnimEvent->numAnims,
				&curAnimEvent->anims, curAnimEvent->waitBefore, curAnimEvent->waitAfter);
		else
			new ChangeAnimEvent(curAnimEvent->xGridPos, curAnimEvent->yGridPos, curAnimEvent->numAnims,
				&curAnimEvent->anims, curAnimEvent->waitBefore, curAnimEvent->waitAfter);
	}*/
	//load state machine trigger events
	/*const StateMachineTriggerEventData::TriggerEvent* curTriggerEvent;
	for (eventNum = 0; eventNum < curMap->stateMachineTriggerEvents->numStateMachineTriggerEvents; ++eventNum) {
		curTriggerEvent = &curMap->stateMachineTriggerEvents->TriggerEventList[eventNum];
		if (curTriggerEvent->spriteNum != -1)
			EventManagement::addEvent(new StateMachineTriggerEvent(vSprites[curTriggerEvent->spriteNum], curTriggerEvent->mapID,
				curTriggerEvent->eventFlagBitIndex), false);
		else
			EventManagement::addEvent(new StateMachineTriggerEvent(curTriggerEvent->xGridPos, curTriggerEvent->yGridPos, curTriggerEvent->mapID,
				curTriggerEvent->eventFlagBitIndex), false);
	}*/
	//load map script state if uninitialised
	if (StateMachineTriggerEvent::MapScriptState::mapScriptStates[newMapID] == NULL && curMap->initState != NULL)
		StateMachineTriggerEvent::MapScriptState::changeState(newMapID, const_cast<StateMachineTriggerEvent::MapScriptState*>(curMap->initState));
	else if (StateMachineTriggerEvent::MapScriptState::mapScriptStates[newMapID] != NULL)
		StateMachineTriggerEvent::MapScriptState::mapScriptStates[newMapID]->init();
	StateMachineTriggerEvent::MapScriptState::mapScriptStates[newMapID]->handleEvents();
}
SDL_Rect curGridPos;
SpritePersistanceData *pData;
void checkAndDoMapTransition(Sprite* s) {
	if (s->gridPos.x < 0 && curMap->connectionData[MapData::West].mapID != -1) {
		EventManagement::delEvent(EventManagement::addEvent(new WarpEvent(s->gridPos.x, s->gridPos.y, 0, 0,
			curMap->connectionData[MapData::West].mapID,
			mapIDs[curMap->connectionData[MapData::West].mapID]->width - 1,
			s->gridPos.y + 8 - curMap->connectionData[MapData::West].yOffset), true, s));
	}
	else if (s->gridPos.x >= curMap->width && curMap->connectionData[MapData::East].mapID != -1) {
		EventManagement::delEvent(EventManagement::addEvent(new WarpEvent(s->gridPos.x, s->gridPos.y, 0, 0,
			curMap->connectionData[MapData::East].mapID,
			0,
			s->gridPos.y + 8 - curMap->connectionData[MapData::East].yOffset), true, s));
	}
	else if (s->gridPos.y < 0 && curMap->connectionData[MapData::North].mapID != -1) {
		EventManagement::delEvent(EventManagement::addEvent(new WarpEvent(s->gridPos.x, s->gridPos.y, 0, 0,
			curMap->connectionData[MapData::North].mapID,
			s->gridPos.x + 8 - curMap->connectionData[MapData::North].xOffset,
			mapIDs[curMap->connectionData[MapData::North].mapID]->height - 1), true, s));
	}
	else if (s->gridPos.y >= curMap->height && curMap->connectionData[MapData::South].mapID != -1) {
		EventManagement::delEvent(EventManagement::addEvent(new WarpEvent(s->gridPos.x, s->gridPos.y, 0, 0,
			curMap->connectionData[MapData::South].mapID,
			s->gridPos.x + 8 - curMap->connectionData[MapData::South].xOffset,
			0), true, s));
	}
}
/*void FadeBlack() {
	int ret=SDL_SetWindowBrightness(window, 1.0);
	float test = SDL_GetWindowBrightness(window);
	while (SDL_GetWindowBrightness(window)>0.1) {
		SDL_Delay(20);
		SDL_SetWindowBrightness(window, SDL_GetWindowBrightness(window)/2);
	}
}*/
void WarpSprite(Sprite* s, unsigned char destMapID, char destX, char destY) {
	if (std::find(vSprites.begin(), vSprites.end(), s) == vSprites.end()) {
		printf("Warpevent failed, Sprite schon gel�scht\n"); return;
	}
	if (mapIDs[destMapID] == curMap) {
		s->mapPos.y = (8 + destY) * 16 + s->mapPos.y % 16;
		s->mapPos.x = (8 + destX) * 16 + s->mapPos.x % 16;
	}
	else {
		s->objectInUse = false;
		if (s->pData != NULL) {
			pData = s->pData;
			pData->mapPos.y = (8 + destY) * 16 + s->mapPos.y % 16;
			pData->mapPos.x = (8 + destX) * 16 + s->mapPos.x % 16;
			pData->curMapID = destMapID;
			pData->curAnim = s->animList.front();
			pData->sData = s->sData;
			if (s == curSprite) {
				//FadeBlack();
				loadMap(destMapID);
				//SDL_SetTextureColorMod(tilemapTexture, curColorRed, curColorGreen, curColorBlue);
			}
		}
	}
}

int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError()); return -1;
	}

	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
	if (window == NULL) {
		printf("Window could not be created! SDL Error: %s\n", SDL_GetError()); return -1;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);//new
	if (renderer == NULL) {
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError()); return -1;
	}
	IMG_Init(IMG_INIT_PNG);

	Uint32 time;
	SDL_RenderSetLogicalSize(renderer, resolutionX, resolutionY);
	SDL_SetRenderDrawColor(renderer, 100, 50, 150, 20);
	SDL_Rect playerPos = { 0,0,0,0 }, srcRect = { 0,0,16,16 }, destRect = { 0,0,16,16 };
	int tileBlockNum, tileNum;
	int mapTopLeftX, mapTopLeftY, playerXOffset = 0, playerYOffset = 0, walkData;

	loadMap(0);

	char i, j;
	bool quit = 0;
	SDL_Event e;
	const Uint8* keystates;
	static unsigned char LastPressed[100];
	static unsigned char KeyPressed[100];
	char tmpLastDir = 0, animSet = 0;
	Sprite* shipSpriteGroup = NULL;
	bool buttonPressed = false;
	while (!quit)
	{
		time = SDL_GetTicks();

		EventManagement::RunNextEvent();

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
			if (!animSet && curSprite->animList.size() == 1) {
				animSet = 1;
				curSprite->pushAnim(3);
			}
		}
		else if (keystates[SDL_SCANCODE_DOWN]) {
			tmpLastDir = 0;
			if (!animSet && curSprite->animList.size() == 1) {
				animSet = 1;
				curSprite->pushAnim(1);
			}
		}
		else if (keystates[SDL_SCANCODE_LEFT]) {
			tmpLastDir = 2;
			if (!animSet && curSprite->animList.size() == 1) {
				animSet = 1;
				curSprite->pushAnim(5);
			}
		}
		else if (keystates[SDL_SCANCODE_RIGHT]) {
			tmpLastDir = 3;
			if (!animSet && curSprite->animList.size() == 1) {
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
			//loadMap(0);
			curColorRed = 255; curColorGreen = 197; curColorBlue = 157;
			SDL_SetTextureColorMod(tilemapTexture, curColorRed, curColorGreen, curColorBlue);
		}
		else if (keystates[SDL_SCANCODE_KP_4]) {
			//loadMap(1);
			curColorRed = 255; curColorGreen = 255; curColorBlue = 255;
			SDL_SetTextureColorMod(tilemapTexture, curColorRed, curColorGreen, curColorBlue);
		}
		else if (keystates[SDL_SCANCODE_KP_9]) {
			//--colblue;
			curColorRed = 60; curColorGreen = 50; curColorBlue = 135;
			SDL_SetTextureColorMod(tilemapTexture, curColorRed, curColorGreen, curColorBlue);
		}
		else if (keystates[SDL_SCANCODE_Q]) {
			detachedCamera = true;
		}
		else if (keystates[SDL_SCANCODE_E]) {
			detachedCamera = false;
		}
		else if (keystates[SDL_SCANCODE_W]) {
			//if (detachedCamera) 
			curCamera.y -= 4;
		}
		else if (keystates[SDL_SCANCODE_S]) {
			//if (detachedCamera) 
			curCamera.y += 4;
		}
		else if (keystates[SDL_SCANCODE_A]) {
			//if (detachedCamera) 
			curCamera.x -= 4;
		}
		else if (keystates[SDL_SCANCODE_D]) {
			//if (detachedCamera) 
			curCamera.x += 4;
		}
		else if (keystates[SDL_SCANCODE_I]) {
			if (shipSpriteGroup != NULL && !buttonPressed) {
				buttonPressed = true;
				std::vector<unsigned char> hyperjump = { 10,11,2 };
				shipSpriteGroup->pushAnim(/*hyperjump.size(), */&hyperjump);
			}
		}
		else if (keystates[SDL_SCANCODE_K]) {
			if (shipSpriteGroup != NULL && !buttonPressed) {
				buttonPressed = true;
				std::vector<unsigned char> hyperjump = { 8,9,0 };
				shipSpriteGroup->pushAnim(/*hyperjump.size(), */&hyperjump);
			}
		}
		else if (keystates[SDL_SCANCODE_J]) {
			if (shipSpriteGroup != NULL && !buttonPressed) {
				buttonPressed = true;
				std::vector<unsigned char> hyperjump = { 12,13,4 };
				shipSpriteGroup->pushAnim(/*hyperjump.size(), */&hyperjump);
			}
		}
		else if (keystates[SDL_SCANCODE_L]) {
			if (shipSpriteGroup != NULL && !buttonPressed) {
				buttonPressed = true;
				std::vector<unsigned char> hyperjump = { 14,15,6 };
				shipSpriteGroup->pushAnim(/*hyperjump.size(), */&hyperjump);
			}
		}
		else if (keystates[SDL_SCANCODE_C]) {
			static bool created = false;
			if (!created) {
				created = true;
				shipSpriteGroup = new SpriteGroup(&shipGroupData);
				shipSpriteGroup->pushAnim((unsigned char)0);
				vSprites.push_back(shipSpriteGroup);
			}
		}
		else if (keystates[SDL_SCANCODE_Z]) {
			static Sprite* genSprite = NULL;
			static unsigned char genSpriteCreated = 0;
			if (!animSet) {
				animSet = true;
				if (genSprite == NULL) {
					genSprite = new Sprite(GenericSpritesList[0], false);
					genSprite->setPos((4 + 8) * 16, (2 + 8) * 16);
					genSprite->pushAnim((unsigned char)0);
					vSprites.push_back(genSprite);
				}
				else {
					++genSpriteCreated;
					if (GenericSpritesList[genSpriteCreated] == NULL)genSpriteCreated = 0;
					genSprite->changeSData(GenericSpritesList[genSpriteCreated]);
				}
			}
		}
		else if (keystates[SDL_SCANCODE_KP_5]) {
			if (curSprite->pData == NULL) {
				SpritePersistanceData* newPSData = new SpritePersistanceData;
				newPSData->curMapID = curMapID;
				vPersistantSprites.push_back(newPSData);
				curSprite->pData = newPSData;
			}
		}
		else if (keystates[SDL_SCANCODE_KP_6]) {
			Sprite* newExplodeBulletRight = new Sprite(&Explosive, true);
			newExplodeBulletRight->setPos(curSprite->mapPos.x, curSprite->mapPos.y);
			vSprites.push_back(newExplodeBulletRight);
			std::vector<unsigned char> explosivemove = { 0,0,1 };
			newExplodeBulletRight->pushAnim(/*3, */&explosivemove);
			//curSprite = newExplodeBulletRight;
			SDL_Delay(50);
		}
		else if (keystates[SDL_SCANCODE_KP_2]) {
			if (LastPressed[SDL_SCANCODE_KP_2] == 0)
				KeyPressed[SDL_SCANCODE_KP_2] = 1;
			else
				KeyPressed[SDL_SCANCODE_KP_2] = 0;
			LastPressed[SDL_SCANCODE_KP_2] = 1;

			if (KeyPressed[SDL_SCANCODE_KP_2]) {
				Sprite* newHyperLightDrifter = new Sprite(&HyperLightDrifter, true);
				newHyperLightDrifter->setPos((10 + 8) * 16, (10 + 8) * 16);
				vSprites.push_back(newHyperLightDrifter);
				std::vector<unsigned char> hyperlightdriftermove = { 7, 7, 1, 1, 5, 5, 3, 3, 7, 7, 1, 1, 5, 5, 3, 3 };
				//const unsigned char hyperlightdriftermove[] = { 7,7,1,1,5,5,3,3,7,7,1,1,5,5,3,3 };
				newHyperLightDrifter->pushAnim(/*16, */&hyperlightdriftermove);
			}
		}
		else if (keystates[SDL_SCANCODE_KP_3]) {
			curSprite->pushAnim((curSprite->animList.front() + 1) % curSprite->sData->numAnimations);
			SDL_Delay(200);
		}
		else if (keystates[SDL_SCANCODE_KP_0]) {
			vSprites_curSpriteNum = ++vSprites_curSpriteNum % vSprites.size();
			curSprite = vSprites[vSprites_curSpriteNum];
			SDL_Delay(200);
		}
		else if (keystates[SDL_SCANCODE_KP_7]) {
			std::vector<unsigned char> moveCircle = {
				7, 7, 1, 1, 5, 5, 3, 3, 7, 7, 1, 1, 5, 5, 3, 3
			};
			curSprite->pushAnim(/*16, */&moveCircle);
			SDL_Delay(200);
		}
		else {
			if (animSet) {
				curSprite->pushAnim(tmpLastDir * 2);
				animSet = 0;
			}
			buttonPressed = false;
			LastPressed[SDL_SCANCODE_KP_2] = 0;
		}

		if (!detachedCamera) {
			if (curCamera.x < curSprite->mapPos.x) {
				newResolutionX = (curSprite->mapPos.x - curCamera.x + 10);
				curCamera.x += newResolutionX / 10;
			}
			else if (curCamera.x > curSprite->mapPos.x) {
				newResolutionX = (curCamera.x - curSprite->mapPos.x + 10);
				curCamera.x -= newResolutionX / 10;
			}
			if (curCamera.y < curSprite->mapPos.y) {
				newResolutionX = (curSprite->mapPos.y - curCamera.y + 10);
				curCamera.y += newResolutionX / 10;
			}
			else if (curCamera.y > curSprite->mapPos.y) {
				newResolutionX = (curCamera.y - curSprite->mapPos.y + 10);
				curCamera.y -= newResolutionX / 10;
			}

			if (newResolutionX > 20) {
				resolutionX = 320 + newResolutionX;
				if (resolutionX > 460) resolutionX = 460;
				resolutionY = (resolutionX / 4) * 3;
				SDL_RenderSetLogicalSize(renderer, resolutionX, resolutionY);
				newResolutionX = 0;
			}
		}

		destRect.x = (resolutionX / 2) - (512 / 2) - curCamera.x % 16;
		destRect.y = (resolutionY / 2) - (512 / 2) - curCamera.y % 16;
		SDL_RenderClear(renderer);
		for (i = 0; i < 32; i++) {
			mapTopLeftY = (curCamera.y / 16) - 16 + i;
			mapTopLeftX = (curCamera.x / 16) - 17;
			for (j = 0; j < 32; j++) {
				++mapTopLeftX;

				unsigned int mapTopTile = mapTopLeftY * bgbreite + mapTopLeftX;

				if (mapTopLeftX >= bgbreite || mapTopLeftX < 0 || mapTopLeftY >= bghoehe || mapTopLeftY < 0) {
					tileNum = 13;
					tileBlockNum = 0;
				}
				else {
					tileNum = bgTiles[mapTopTile];
					walkData = bgWalk[mapTopTile];
					tileBlockNum = (walkData >> 3) & 0x3;
				}
				srcRect.y = tileBlockNum * 512 + 16 * (tileNum / tilemapNumColumns /*8*/);
				srcRect.x = 16 * (tileNum % tilemapNumColumns /*8*/);

				if (tileBlockNum > 2) {//format: bit 7 6 5 (walk data), 4 3 (tile block num) 2 1 0 (pause count) )
					if (((walkData + 1) & 0x7) == 0) {
						if ((++tileNum % 8) == 0)
							bgTiles[mapTopTile] -= 7;
						else
							bgTiles[mapTopTile] = tileNum;
						bgWalk[mapTopTile] &= 0xf8;
					}
					else {
						bgWalk[mapTopTile] = (walkData & 0xf8) | ((walkData + 1) & 0x7);
					}
				}
				SDL_RenderCopy(renderer, tilemapTexture, &srcRect, &destRect);
				destRect.x += 16;
			}
			destRect.x = (resolutionX / 2) - (512 / 2) - curCamera.x % 16;
			destRect.y += 16;
		}
		//sprite drawing order
		for (std::vector<Sprite*>::iterator it = vSprites.begin(); it != vSprites.end() - 1; ++it)
			for (std::vector<Sprite*>::iterator it2 = vSprites.begin(); it2 != vSprites.end() - 1; ++it2)
				if ((*it2)->mapPos.y + (*it2)->mapPos.h > (*(it2 + 1))->mapPos.y + (*(it2 + 1))->mapPos.h)
					std::iter_swap(it2, it2 + 1);
		//add sprites to BG
		int bildmitteX = (resolutionX / 2);
		int bildmitteY = (resolutionY / 2);
		int ursprungX = bildmitteX - curCamera.x;//curSprite->mapPos.x;
		int ursprungY = bildmitteY - curCamera.y;//curSprite->mapPos.y;
		SDL_Rect tmp;
		Sprite* its;
		for (std::vector<Sprite*>::iterator it = vSprites.begin(); it != vSprites.end();) {
			if ((*it)->objectInUse) {
				its = *it;
				if ((abs(its->mapPos.x - curCamera.x) < 250) && (abs(its->mapPos.y - curCamera.y) < 250)) {//if ((abs(its->mapPos.x - curSprite->mapPos.x) < 250) && (abs(its->mapPos.y - curSprite->mapPos.y) < 250)) {
					const SDL_Rect* srcTmp = &its->getFrameCoord();

					if (its->objectInUse) {
						tmp.h = its->mapPos.h;
						tmp.w = its->mapPos.w;
						tmp.x = ursprungX + its->mapPos.x;
						tmp.y = ursprungY + its->mapPos.y;
						tmp.x -= its->mapPos.w / 2;
						tmp.y -= its->mapPos.h / 2;
						SDL_RenderCopy(renderer, its->spriteTexture, srcTmp, &tmp);
					}
				}
				++it;
			}
			else {
				if (vSprites.size() == 1) {
					newSprite = new Sprite(curMap->sprites[0].sprite, false);
					newSprite->setPos((curMap->sprites[0].mapPos.x + 8) * 16, (curMap->sprites[0].mapPos.y + 8) * 16);
					newSprite->pushAnim(curMap->sprites[0].curAnim);
					vSprites.push_back(newSprite);
				}
				if (curSprite == (*it)) curSprite = NULL;
				delete *it;
				it = vSprites.erase(it);
				if (curSprite == NULL) curSprite = *vSprites.begin();
			}
		}
		SDL_RenderPresent(renderer);
		if (20 > (SDL_GetTicks() - time)) SDL_Delay(20 - (SDL_GetTicks() - time));
	}
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
	return 0;
}