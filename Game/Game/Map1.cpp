#include "Map.h"
#include "Event.h"
#include "Hiro.h"
#include "HyperLightDrifter.h"
#include "Commandos.h"
#include "Diablo.h"
#include "Explosive.h"

extern std::vector<Sprite*> vSprites;

const char map1breite = 50, map1hoehe = 20, map1border = 1;
unsigned char map1tiledata[map1hoehe*map1breite] = {
	 7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
	 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7,
	 7,1,1,1,176,177,177,177,177,178,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	 7,1,1,1,184,0,0,0,0,186,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	 7,1,1,1,184,0,8,8,0,186,1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7,
	 7,1,1,1,184,0,8,8,0,186,1,1,1,1,1,1,5,1,1,1,1,1,1,1,1,72,73,74,75,76,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7,
	 7,1,1,1,184,0,0,0,0,186,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,80,81,82,83,84,1,1,1,13,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7,
	 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,88,89,90,91,92,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7,
	 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,96,97,98,99,100,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7,
	 7,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7,
	 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,62,63,1,1,1,1,1,1,1,1,1,1,1,7,
	 7,1,1,13,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,69,70,71,77,1,1,1,1,1,1,1,1,1,1,7,
	 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,13,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,78,79,1,1,1,1,1,1,1,1,1,1,1,7,
	 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7,
	 7,1,1,1,1,1,1,13,1,1,1,1,1,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7,
	 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7,
	 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7,
	 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7,
	 7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7,
	 7,7,7,7,7,7,1,1,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7
};
unsigned char map1walkdata[map1hoehe*map1breite] = {
	 224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,
	 224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,
	 224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	 224,0,0,0,0,24,24,24,24,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	 224,0,0,0,0,24,24,24,24,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,
	 224,0,0,0,0,24,24,24,24,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,224,224,224,224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,
	 224,0,0,0,0,24,24,24,24,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,224,224,224,224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,
	 224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,224,224,224,224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,
	 224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,0,224,224,224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,
	 224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,
	 224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,224,0,0,0,0,0,0,0,0,0,0,0,224,
	 224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,224,0,0,0,0,0,0,0,0,0,0,0,224,
	 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,224,0,0,0,0,0,0,0,0,0,0,0,224,
	 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,
	 224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,
	 224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,
	 224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,
	 224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,
	 224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,
	 224,224,224,224,224,224,0,0,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224
};
class Map1Script2 :public StateMachineTriggerEvent::MapScriptState {
	Event* doNothingEvent;
public:
	void init() {
		printf("map1 script 2 init, create 1 doNothingEvent (5,10)\n");
		Event* doNothingEvent = EventManagement::addEvent(new StateMachineTriggerEvent(10, 10, 0, 5), false);
		EventManagement::delEvent(EventManagement::addEvent(new ChangeTimeEvent(0, 0, 255, 197, 157), true));
	}
	void exit() {
		printf("map1 script 2 exit\n");
	}
	void handleEvents() {
		printf("map1 script 2 handleEvents\n");
	}
};
class Map1Script1 :public StateMachineTriggerEvent::MapScriptState {
	Event* jumpTopLeft;
	Event* setFlag5ByWarp;
	Sprite* switchSprite;
	Event* triggerSwitchSprite;
public:
	void init() {
		switchSprite = new Sprite(&Hiro, false);
		switchSprite->setPos((20 + 8) * 16, (10 + 8) * 16);
		switchSprite->pushAnim(0);
		vSprites.push_back(switchSprite);
		triggerSwitchSprite = EventManagement::addEvent(new StateMachineTriggerEvent(switchSprite, 0, 30), false);

		printf("map1 init script 1, create 1 warp (10,10), create 1 setFlag5Event (10,5)\n");
		jumpTopLeft = EventManagement::addEvent(new WarpEvent(5, 10, 0, 0, 0, 5, 5), false);//selbe map nach oben links
		setFlag5ByWarp = EventManagement::addEvent(new StateMachineTriggerEvent(8, 10, 0, 5), false);
	}
	void exit() {
		printf("map1 script 1 exit\n");
	}
	void handleEvents() {
		printf("map1 script 1 handleEvents\n");
		if (StateMachineTriggerEvent::mapEventFlagBitmap[0] & 1 << 5) {
			EventManagement::delEvent(jumpTopLeft);
			EventManagement::delEvent(setFlag5ByWarp);
			printf("map1 script 1 handleEvents, flag 5 == 1 -> change state to script 2\n");
			StateMachineTriggerEvent::MapScriptState::changeState(0, new Map1Script2());
		}
	}
};
class Map1SwitchSpriteScript :public StateMachineTriggerEvent::MapScriptState {
	Sprite* switchSprite;
	Event* spriteTriggerBit30;
	Event* spriteAngelHochGehenAnimUndAutoDel;
public:
	void init() {
		StateMachineTriggerEvent::mapEventFlagBitmap[0] = 0;
		printf("scrip init, create switch-sprite, add trigger-event(bit30)\n");
		switchSprite = new Sprite(&Hiro, false);
		switchSprite->setPos((20 + 8) * 16, (10 + 8) * 16);
		switchSprite->pushAnim(0);
		vSprites.push_back(switchSprite);

		std::vector<unsigned char>* vAnim_Angel_WalkUp = new std::vector<unsigned char>;
		vAnim_Angel_WalkUp->push_back(12);//angel
		vAnim_Angel_WalkUp->push_back(3);//walk up
		vAnim_Angel_WalkUp->push_back(6);//turn right
		vAnim_Angel_WalkUp->push_back(0);//turn down
		//sprite event: add animations: angel, gehe hoch außerdem set autoDel
		spriteAngelHochGehenAnimUndAutoDel = EventManagement::addEvent(new ChangeAnimEvent(switchSprite, vAnim_Angel_WalkUp->size(), vAnim_Angel_WalkUp, switchSprite, true), false);
		//sprite event: setze trigger bit 30 mit waitBefore (ca. halbe angel anim)
		spriteTriggerBit30 = EventManagement::addEvent(new StateMachineTriggerEvent(switchSprite, 0, 30, 40), false);

		/*printf("map1 init script 1, create 1 warp (10,10), create 1 setFlag5Event (10,5)\n");
		jumpTopLeft = EventManagement::addEvent(new WarpEvent(5, 10, 0, 0, 0, 5, 5), false);//selbe map nach oben links
		setFlag5ByWarp = EventManagement::addEvent(new StateMachineTriggerEvent(8, 10, 0, 5), false);*/
	}
	void exit() {
		printf("script exit\n");
		//vSprites.erase(std::find(vSprites.begin(), vSprites.end(), switchSprite));
	}
	void handleEvents() {
		printf("map1 script 1 handleEvents\n");
		if (StateMachineTriggerEvent::mapEventFlagBitmap[0] & 1 << 30) {
			EventManagement::delEvent(EventManagement::addEvent(new ChangeTimeEvent(0, 0, 255, 197, 157), true));
			EventManagement::delEvent(spriteAngelHochGehenAnimUndAutoDel);
		}
		/*EventManagement::delEvent(jumpTopLeft);
		EventManagement::delEvent(setFlag5ByWarp);
		printf("map1 script 1 handleEvents, flag 5 == 1 -> change state to script 2\n");
		StateMachineTriggerEvent::MapScriptState::changeState(0, new Map1Script2()); //calls exit, delete, init
	}*/
	}
};
const MapData map1Data = {
	"tilesAnim.bmp", map1hoehe, map1breite, map1tiledata, map1walkdata, new Map1SwitchSpriteScript(),
	{ { -1,0,0 }, //nord //mapID, xOffset, yOffset
	  { 1,-2,0 }, //süd
	  { 2,0,18 }, //west
	  { 2,0,3 } }, //ost
	map1border, 2,                                     //x,y,w,h
	{ { &Hiro,{ 2, 2, 0, 0 }, 0 },{ &HyperLightDrifter,{ 3,4,0,0 } ,0 } } //sprites laden zukünftig in state machine
};


const char map2breite = 20, map2hoehe = 20, map2border = 188;
unsigned char map2tiledata[map2hoehe*map2breite] = {
	159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,1,1,159,159,
	159,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,159,
	159,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,159,
	159,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,159,
	159,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,159,
	159,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,159,
	159,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,159,
	159,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,159,
	159,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,159,
	159,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,159,
	159,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,159,
	159,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,159,
	159,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,159,
	159,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,159,
	159,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,159,
	159,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,159,
	159,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,159,
	159,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,159,
	159,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,159,
	159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159
};
unsigned char map2walkdata[map2hoehe*map2breite] = {
	224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,1,1,224,224,
	224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,
	224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,
	224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,
	224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,
	224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,
	224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,
	224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,
	224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,
	224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,
	224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,
	224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,
	224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,
	224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,
	224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,
	224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,
	224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,
	224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,
	224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,
	224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224
};
class Map2Script1 :public StateMachineTriggerEvent::MapScriptState {
	Event* doNothingEvent;
public:
	void init() {
		printf("map2 script 1 init, create 1 doNothingEvent (3,3)\n");
		Event* doNothingEvent = EventManagement::addEvent(new StateMachineTriggerEvent(3, 3, 0, 5), false);
		Event* changeTileEvent = EventManagement::addEvent(new ChangeBGTileEvent(10, 3, 0, 0, 3, 0), false);
		EventManagement::delEvent(EventManagement::addEvent(new ChangeBGTileEvent(0, 0, 1, 0, 3, 0), true));
	}
	void exit() {
		printf("map2 script 1 exit\n");
	}
	void handleEvents() {
		printf("map2 script 1 handleEvents\n");
	}
};
const MapData map2Data = {
	"fireredtiles.bmp", map2hoehe, map2breite, map2tiledata, map2walkdata, new Map2Script1(),
	{ { 0,18,0 },{ -1,0,0 },{ -1,0,0 },{ -1,0,0 } }, map2border, 4,
	{ { &Commandos,{ 9, 7, 0, 0 }, 0 },{ &Commandos,{ 9,5,0,0 } ,2 },{ &Commandos,{ 7,6,0,0 } ,4 },{ &Commandos,{ 11,6,0,0 } ,6 } }
};


const char map3breite = 10, map3hoehe = 10, map3border = 188;
unsigned char map3tiledata[map3hoehe*map3breite] = {
	159,159,159,159,159,159,159,159,159,159,
	159,1,1,1,1,1,1,1,1,159,
	159,1,1,1,1,1,1,1,1,1,
	159,1,1,1,1,1,1,1,1,1,
	159,1,1,1,1,1,1,1,1,159,
	159,1,1,1,1,1,1,1,1,159,
	159,1,1,1,1,1,1,1,1,159,
	1,1,1,1,1,1,1,1,1,159,
	1,1,1,1,1,1,1,1,1,159,
	159,159,159,159,159,159,159,159,159,159
};
unsigned char map3walkdata[map3hoehe*map3breite] = {
	224,224,224,224,224,224,224,224,224,224,
	224,0,0,0,0,0,0,0,0,224,
	224,0,0,0,0,0,0,0,0,0,
	224,0,0,0,0,0,0,0,0,0,
	224,0,0,0,0,0,0,0,0,224,
	224,0,0,0,0,0,0,0,0,224,
	224,0,0,0,0,0,0,0,0,224,
	0,0,0,0,0,0,0,0,0,224,
	0,0,0,0,0,0,0,0,0,224,
	224,224,224,224,224,224,224,224,224,224
};
class Map3Script1 :public StateMachineTriggerEvent::MapScriptState {
	Event* doNothingEvent;
public:
	void init() {
		printf("map3 script 1 init, create 1 doNothingEvent (3,3)\n");
		Event* doNothingEvent = EventManagement::addEvent(new StateMachineTriggerEvent(3, 3, 2, 5), false);
	}
	void exit() {
		printf("map3 script 1 exit\n");
	}
	void handleEvents() {
		printf("map3 script 1 handleEvents\n");
	}
};
const MapData map3Data = {
	"fireredtiles.bmp", map3hoehe, map3breite, map3tiledata, map3walkdata, new Map3Script1(),
	{ { -1,0,0 },{ -1,0,0 },{ 0,0,13 },{ 0,0,-2 } }, map3border, 1,
	{ { &Diablo,{ 5, 3, 0, 0 }, 0 } }
};