#pragma once
#include <SDL.h>
#include "SpriteData.h"

extern char const map1breite;
extern const char map1hoehe;
extern char const map1border;
//extern unsigned char map1tiledata[20][50];
//extern unsigned char map1walkdata[20][50];
extern unsigned char map1tiledata[20 * 50];
extern unsigned char map1walkdata[20 * 50];

class MapData {
public:
	class ConnectionData {
	public:
		unsigned const char mapID;
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
	unsigned char* tileData, *walkData;
	const ConnectionData connectionData[4];
	unsigned const char borderTile;
	const SpritePos sprites[];
};