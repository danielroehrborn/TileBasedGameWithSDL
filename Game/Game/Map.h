#pragma once
#include <SDL.h>
#include "SpriteData.h"

extern char const map1breite;
extern const char map1hoehe;
extern char const map1border;
extern unsigned char map1tiledata[20 * 50];
extern unsigned char map1walkdata[20 * 50];

class MapData {
public:
	enum Position{North,South,West,East};
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
	unsigned char* const tileData, * const walkData;
	const ConnectionData const connectionData[4];
	unsigned const char borderTile;
	const SpritePos const sprites[];
};

extern const MapData map1Data;
extern const MapData map2Data;
extern const MapData map3Data;