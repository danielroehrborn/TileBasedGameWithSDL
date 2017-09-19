#pragma once
#include <SDL.h>
#include "SpriteData.h"

extern char const map1breite;
extern const char map1hoehe;
extern char const map1border;
extern unsigned char map1tiledata[20 * 50];
extern unsigned char map1walkdata[20 * 50];

class WarpEventData {
public:
	class WarpEventPos {
	public:
		const char spriteNum;
		const char xGridPos;
		const char yGridPos;
		const unsigned char destMapID;
		const char destXGridPos;
		const char destYGridPos;
	};
	const unsigned char numWarpEvents;
	const WarpEventPos const wepList[];
};

class MapData {
public:
	enum Position { North, South, West, East, Unknown };
	class ConnectionData {
	public:
		const char mapID;
		const char xOffset, yOffset;
	};
	class SpritePos {
	public:
		const SpriteData* sprite;
		SDL_Rect mapPos;
		unsigned const char curAnim;
	};
	const char* pathTileset;
	unsigned const char height, width;
	unsigned char* const tileData, *const walkData;
	const WarpEventData* warpEvents;
	const ConnectionData const connectionData[4];
	unsigned const char borderTile;
	const unsigned char numSprites;
	const SpritePos const sprites[];
};

extern const MapData map1Data;
extern const WarpEventData map1WarpEventData;

extern const MapData map2Data;
extern const WarpEventData map2WarpEventData;

extern const MapData map3Data;
extern const WarpEventData map3WarpEventData;