#include "Map.h"
#include "Event.h"
#include "Hiro.h"
#include "HyperLightDrifter.h"
#include "Commandos.h"
#include "Diablo.h"
#include "Explosive.h"
#include "Switch.h"
#include "DungeonSprites.h"
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
		switchSprite->pushAnim((unsigned char)0);
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
extern unsigned char curColorRed, curColorGreen, curColorBlue;
class Map1SwitchSpriteScript :public StateMachineTriggerEvent::MapScriptState {
	Sprite* switchSprite, *warpSwitchSprite;
	Event* spriteTriggerBit30;
	Event* spriteAngelHochGehenAnimUndAutoDel;
	bool darkerLight = false;
public:
	void init() {
		/*StateMachineTriggerEvent::mapEventFlagBitmap[0] = 0;////////hiro
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
		spriteTriggerBit30 = EventManagement::addEvent(new StateMachineTriggerEvent(switchSprite, 0, 30, 40), false);*/
		darkerLight = 0;
		StateMachineTriggerEvent::mapEventFlagBitmap[0] = 0;
		printf("scrip init, create switch-sprite, add trigger-event(bit30)\n");
		switchSprite = new Sprite(&Switch, false);
		switchSprite->setPos((26 + 8) * 16 + 8, (8 + 8) * 16 + 8);
		switchSprite->pushAnim((unsigned char)0);
		vSprites.push_back(switchSprite);

		warpSwitchSprite = new Sprite(&Switch, false);
		warpSwitchSprite->setPos((10 + 8) * 16 + 8, (8 + 8) * 16 + 8);
		warpSwitchSprite->pushAnim((unsigned char)0);
		vSprites.push_back(warpSwitchSprite);
		std::vector<unsigned char>* vSwitchDisappear = new std::vector<unsigned char>;
		vSwitchDisappear->push_back(1);//switch weg
		vSwitchDisappear->push_back(0);//switch normal
		EventManagement::addEvent(new ChangeAnimEvent(warpSwitchSprite, vSwitchDisappear->size(), vSwitchDisappear, warpSwitchSprite, false), false);
		EventManagement::addEvent(new WarpEvent(warpSwitchSprite, 3, 7, 7, 145), false);


		std::vector<unsigned char>* vAnim_Angel_WalkUp = new std::vector<unsigned char>;
		vAnim_Angel_WalkUp->push_back(1);//angel
		vAnim_Angel_WalkUp->push_back(2);//walk up
										 //sprite event: add animations: angel, gehe hoch außerdem set autoDel
		spriteAngelHochGehenAnimUndAutoDel = EventManagement::addEvent(new ChangeAnimEvent(switchSprite, vAnim_Angel_WalkUp->size(), vAnim_Angel_WalkUp, switchSprite, true), false);
		//sprite event: setze trigger bit 30 mit waitBefore (ca. halbe angel anim)
		//spriteTriggerBit30 = EventManagement::addEvent(new StateMachineTriggerEvent(switchSprite, 0, 30, 152), false); sofort auslösen
		spriteTriggerBit30 = EventManagement::addEvent(new StateMachineTriggerEvent(switchSprite, 0, 30), false);

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
			if (spriteAngelHochGehenAnimUndAutoDel != NULL) {//mehrfachaufruf, nicht nötig bei state change
				EventManagement::delEvent(spriteAngelHochGehenAnimUndAutoDel);
				spriteAngelHochGehenAnimUndAutoDel = NULL;
			}
			if (spriteTriggerBit30 != NULL) {
				EventManagement::delEvent(spriteTriggerBit30);
				spriteTriggerBit30 = NULL;
			}
			if (!darkerLight) {
				darkerLight = true;
				EventManagement::delEvent(EventManagement::addEvent(new ChangeTimeEvent(0, 0, 255, 244, 236, 145), true, 0, 1));
				EventManagement::delEvent(EventManagement::addEvent(new ChangeTimeEvent(0, 0, 255, 233, 217, 15), true, 0, 1));
				EventManagement::delEvent(EventManagement::addEvent(new ChangeTimeEvent(0, 0, 255, 222, 198, 15), true, 0, 1));
				EventManagement::delEvent(EventManagement::addEvent(new ChangeTimeEvent(0, 0, 255, 211, 179, 15), true, 0, 1));
				EventManagement::delEvent(EventManagement::addEvent(new ChangeTimeEvent(0, 0, 255, 197, 157, 15), true, 0, 1));
				curColorRed = 255; curColorGreen = 197; curColorBlue = 157;
			}
			//EventManagement::delEvent(EventManagement::addEvent(new ChangeTimeEvent(0, 0, 255, 197, 157, 150), true));
			//weitere dunkelheitsstufen
		}
		/*EventManagement::delEvent(jumpTopLeft);
		EventManagement::delEvent(setFlag5ByWarp);
		printf("map1 script 1 handleEvents, flag 5 == 1 -> change state to script 2\n");
		StateMachineTriggerEvent::MapScriptState::changeState(0, new Map1Script2()); //calls exit, delete, init
	}*/
	}
};
const MapData map1Data = {
	"tilesAnim.bmp", 8, map1hoehe, map1breite, map1tiledata, map1walkdata, new Map1SwitchSpriteScript(),
	{ { -1,0,0 }, //nord //mapID, xOffset, yOffset
	  { 1,-2,0 }, //süd
	  { 2,0,18 }, //west
	  { 2,0,3 } }, //ost
	map1border, 2,                                     //x,y,w,h
	{ { &Hiro,{ 2, 2, 0, 0 }, 0 },{ &HyperLightDrifter,{ 3,4,0,0 }, 0 } }//sprites laden zukünftig in state machine
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
	"fireredtiles.bmp", 8, map2hoehe, map2breite, map2tiledata, map2walkdata, new Map2Script1(),
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
	"fireredtiles.bmp", 8, map3hoehe, map3breite, map3tiledata, map3walkdata, new Map3Script1(),
	{ { -1,0,0 },{ -1,0,0 },{ 0,0,13 },{ 0,0,-2 } }, map3border, 1,
	{ { &Diablo,{ 5, 3, 0, 0 }, 0 } }
};


const char mapDungeonbreite = 14, mapDungeonhoehe = 13, mapDungeonborder = 25;
unsigned char mapDungeontiledata[mapDungeonbreite*mapDungeonhoehe] = {
	25,25,25,25,25,25,25,25,25,25,25,25,25,25,
	25,5,6,105,6,25,6,104,7,25,5,6,7,25,
	25,29,30,129,30,54,30,128,31,25,29,54,31,25,
	25,53,54,54,54,54,54,54,56,6,57,54,55,25,
	25,102,54,54,54,54,54,54,80,54,81,54,55,25,
	25,76,54,54,54,54,54,54,183,54,184,54,75,25,
	25,100,54,54,54,54,54,54,54,54,54,54,99,25,
	25,53,54,54,54,54,54,54,54,54,54,54,55,25,
	25,53,54,8,78,9,54,54,54,54,54,54,75,25,
	25,103,54,99,25,33,54,54,54,54,54,54,99,25,
	25,77,78,79,25,77,9,54,54,54,54,54,55,25,
	25,25,25,25,25,25,77,78,78,127,78,78,79,25,
	25,25,25,25,25,25,25,25,25,25,25,25,25,25
};
unsigned char mapDungeonwalkdata[mapDungeonbreite*mapDungeonhoehe] = {
	000,000,000,000,000,000,000,000,000,000,000,000,000,000,
	000,000,000,000,000,000,000,000,000,000,000,000,000,000,
	000,000,224,224,224,000,224,224,224,000,224,000,224,000,
	000,224,000,000,000,000,000,000,224,000,224,000,224,000,
	000,224,000,000,000,000,000,000,224,000,224,000,224,000,
	000,224,000,000,000,000,000,000,000,000,000,000,224,000,
	000,224,000,000,000,000,000,000,000,000,000,000,224,000,
	000,224,000,000,000,000,000,000,000,000,000,000,224,000,
	000,224,000,224,224,224,000,000,000,000,000,000,224,000,
	000,224,000,224,000,224,000,000,000,000,000,000,224,000,
	000,000,224,000,000,000,224,000,000,000,000,000,224,000,
	000,000,000,000,000,000,000,224,224,224,224,224,000,000,
	000,000,000,000,000,000,000,000,000,000,000,000,000,000
};
class MapDungeonScript1 :public StateMachineTriggerEvent::MapScriptState {
public://protected:
	Event* animStatueGlowEvent, *animSwitchOnEvent, *animDoorOpenEvent, *animIronDoorOpenCloseEvent, *animStepBackFromDoorEvent,
		*animStepBackFromDoorEvent2, *Bit1SwitchDoorOpenEvent, *Bit2SwitchDoorCloseEvent, *WarpOutOfClosingDoor, *WarpBackToOverworld;
	Sprite* statue1, *door, *doorswitch, *ironDoor, *woodDoor;
public:
	void init();
	void exit();
	void handleEvents();
};
/*class MapDungeonScript2 :public MapDungeonScript1 {
public:
	MapDungeonScript2(MapDungeonScript1* parent);
	void init();
	void exit();
	void handleEvents();
};*/
void MapDungeonScript1::init() {
	printf("mapDungeon script 1 init\n");
	statue1 = new Sprite(&DungeonStatue1, false);
	statue1->setPos((3 + 8) * 16, (3 + 8) * 16);
	statue1->pushAnim((unsigned char)0);
	vSprites.push_back(statue1);

	door = new Sprite(&DungeonDoor, false);
	door->setPos(216, 164);
	door->pushAnim((unsigned char)1);
	vSprites.push_back(door);
	EventManagement::delEvent(EventManagement::addEvent(new ChangeBGTileEvent(0, 0, 5, 2, 30, 224)));

	ironDoor = new Sprite(&DungeonIronDoor, false);
	ironDoor->setPos(312, 168);
	ironDoor->pushAnim((unsigned char)1);
	vSprites.push_back(ironDoor);

	woodDoor = new Sprite(&DungeonWoodDoor, false);
	woodDoor->setPos(280, 200);
	woodDoor->pushAnim((unsigned char)1);
	vSprites.push_back(woodDoor);

	doorswitch = new Sprite(&DungeonSwitch, false);
	doorswitch->setPos((6 + 8) * 16, (6 + 8) * 16);
	doorswitch->pushAnim((unsigned char)1);
	vSprites.push_back(doorswitch);

	/*EventManagement::delEvent(EventManagement::addEvent(new ChangeBGTileEvent(0, 0, 5, 2, 30, 224)));
	std::vector<unsigned char>* vSwitchOffAtBeginning = new std::vector<unsigned char>;
	vSwitchOffAtBeginning->push_back(0);
	vSwitchOffAtBeginning->push_back(3);
	vSwitchOffAtBeginning->push_back(1);
	EventManagement::delEvent(EventManagement::addEvent(new ChangeAnimEvent(0, 0, vSwitchOffAtBeginning->size(), vSwitchOffAtBeginning, doorswitch, 0, false, 50)));
	std::vector<unsigned char>* vStatueRedAtBeginning = new std::vector<unsigned char>;
	vStatueRedAtBeginning->push_back(5);
	vStatueRedAtBeginning->push_back(5);
	vStatueRedAtBeginning->push_back(0);
	EventManagement::delEvent(EventManagement::addEvent(new ChangeAnimEvent(0, 0, vStatueRedAtBeginning->size(), vStatueRedAtBeginning, statue1, false, 20)));
	*/
	//step back from iron door
	EventManagement::delEvent(EventManagement::addEvent(new ChangeBGTileEvent(0, 0, 11, 2, 30, 224)));
	std::vector<unsigned char>* vIronDoorOpenClose = new std::vector<unsigned char>;
	vIronDoorOpenClose->push_back(4);
	vIronDoorOpenClose->push_back(1);
	animIronDoorOpenCloseEvent = EventManagement::addEvent(new ChangeAnimEvent(11, 3, vIronDoorOpenClose->size(), vIronDoorOpenClose, ironDoor), false);
	std::vector<unsigned char>* vStepBack = new std::vector<unsigned char>;
	vStepBack->push_back(1);
	/*vStepBack->push_back(2);
	vStepBack->push_back(0);*/
	animStepBackFromDoorEvent = EventManagement::addEvent(new ChangeAnimEvent(11, 3, vStepBack->size(), vStepBack), false);
	std::vector<unsigned char>* vStepBack2 = new std::vector<unsigned char>;
	vStepBack2->push_back(2);
	vStepBack2->push_back(1);
	vStepBack2->push_back(0);
	animStepBackFromDoorEvent2 = EventManagement::addEvent(new ChangeAnimEvent(11, 3, vStepBack2->size(), vStepBack2, 0, false, 50), false);

	Bit1SwitchDoorOpenEvent = EventManagement::addEvent(new StateMachineTriggerEvent(6, 6, 3, 1), false);
}
void MapDungeonScript1::exit() {
	printf("mapDungeon script 1 exit\n");
}
void MapDungeonScript1::handleEvents() {
	printf("mapDungeon script 1 handleEvents\n");
	if (StateMachineTriggerEvent::mapEventFlagBitmap[3] & 1 << 1) { //door open anim
		if (Bit1SwitchDoorOpenEvent != NULL) {
			EventManagement::delEvent(Bit1SwitchDoorOpenEvent);
			Bit1SwitchDoorOpenEvent = NULL;
		}
		if (WarpOutOfClosingDoor != NULL) {
			EventManagement::delEvent(WarpOutOfClosingDoor);
			WarpOutOfClosingDoor = NULL;
		}
		std::vector<unsigned char>* vSwitchAndStayOn = new std::vector<unsigned char>;
		vSwitchAndStayOn->push_back(1);
		vSwitchAndStayOn->push_back(2);
		vSwitchAndStayOn->push_back(0);
		EventManagement::delEvent(EventManagement::addEvent(new ChangeAnimEvent(0, 0, vSwitchAndStayOn->size(), vSwitchAndStayOn, doorswitch)));
		std::vector<unsigned char>* vStatueFlashGreen = new std::vector<unsigned char>;
		vStatueFlashGreen->push_back(0);
		vStatueFlashGreen->push_back(9);
		vStatueFlashGreen->push_back(10);
		vStatueFlashGreen->push_back(12);
		EventManagement::delEvent(EventManagement::addEvent(new ChangeAnimEvent(0, 0, vStatueFlashGreen->size(), vStatueFlashGreen, statue1, false, 20)));
		std::vector<unsigned char>* vDoorOpen = new std::vector<unsigned char>;
		vDoorOpen->push_back(1);
		vDoorOpen->push_back(2);
		vDoorOpen->push_back(0);
		EventManagement::delEvent(EventManagement::addEvent(new ChangeAnimEvent(0, 0, vDoorOpen->size(), vDoorOpen, door, false, 50, 20)));
		EventManagement::delEvent(EventManagement::addEvent(new ChangeBGTileEvent(0, 0, 5, 2, 54, 0)));

		WarpBackToOverworld = EventManagement::addEvent(new WarpEvent(5, 1, 16, 16, 0, 10, 5), false);

		StateMachineTriggerEvent::mapEventFlagBitmap[3] = 0;
		EventManagement::delEvent(EventManagement::addEvent(new StateMachineTriggerEvent(0, 0, 3, 2, 250, 0), true, 0, 1));//close flag with delay
	}
	if (StateMachineTriggerEvent::mapEventFlagBitmap[3] & 1 << 2) { //door close anim
		StateMachineTriggerEvent::mapEventFlagBitmap[3] = 0;
		if (WarpBackToOverworld != NULL) {
			EventManagement::delEvent(WarpBackToOverworld);
			WarpBackToOverworld = NULL;
		}
		WarpOutOfClosingDoor = EventManagement::addEvent(new WarpEvent(door, 3, 5, 3), false, 0, 0, true);
		Bit1SwitchDoorOpenEvent = EventManagement::addEvent(new StateMachineTriggerEvent(6, 6, 3, 1), false);//reactivate switch
		std::vector<unsigned char>* vSwitchAndStayOff = new std::vector<unsigned char>;
		vSwitchAndStayOff->push_back(3);
		vSwitchAndStayOff->push_back(1);
		EventManagement::delEvent(EventManagement::addEvent(new ChangeAnimEvent(0, 0, vSwitchAndStayOff->size(), vSwitchAndStayOff, doorswitch)));
		std::vector<unsigned char>* vStatueFlashRed = new std::vector<unsigned char>;
		vStatueFlashRed->push_back(11);
		vStatueFlashRed->push_back(5);
		vStatueFlashRed->push_back(0);
		EventManagement::delEvent(EventManagement::addEvent(new ChangeAnimEvent(0, 0, vStatueFlashRed->size(), vStatueFlashRed, statue1, false)));
		std::vector<unsigned char>* vDoorClose = new std::vector<unsigned char>;
		vDoorClose->push_back(3);
		vDoorClose->push_back(1);
		EventManagement::delEvent(EventManagement::addEvent(new ChangeAnimEvent(0, 0, vDoorClose->size(), vDoorClose, door, false, 0, 20)));
		EventManagement::delEvent(EventManagement::addEvent(new ChangeBGTileEvent(0, 0, 5, 2, 30, 224)));
	}
}
/*MapDungeonScript2::MapDungeonScript2(MapDungeonScript1* parent) {
	animStatueGlowEvent = parent->animStatueGlowEvent;
	animSwitchOnEvent = parent->animSwitchOnEvent;
	animDoorOpenEvent = parent->animDoorOpenEvent;
	animIronDoorOpenCloseEvent = parent->animIronDoorOpenCloseEvent;
	animStepBackFromDoorEvent = parent->animStepBackFromDoorEvent;
	Bit1SwitchStateDoorOpenEvent = parent->Bit1SwitchStateDoorOpenEvent;
	statue1 = parent->statue1;
	door = parent->door;
	doorswitch = parent->doorswitch;
	ironDoor = parent->ironDoor;
	woodDoor = parent->woodDoor;
}
void MapDungeonScript2::init() {
	printf("mapDungeon script 2 init\n");

	std::vector<unsigned char>* vSwitchAndStayOn = new std::vector<unsigned char>;
	vSwitchAndStayOn->push_back(1);
	vSwitchAndStayOn->push_back(2);
	vSwitchAndStayOn->push_back(0);
	EventManagement::delEvent(EventManagement::addEvent(new ChangeAnimEvent(0, 0, vSwitchAndStayOn->size(), vSwitchAndStayOn, doorswitch)));
	std::vector<unsigned char>* vStatueFlashTwice = new std::vector<unsigned char>;
	vStatueFlashTwice->push_back(0);
	vStatueFlashTwice->push_back(1);
	vStatueFlashTwice->push_back(5);
	vStatueFlashTwice->push_back(10);
	vStatueFlashTwice->push_back(11);
	vStatueFlashTwice->push_back(0);
	EventManagement::delEvent(EventManagement::addEvent(new ChangeAnimEvent(0, 0, vStatueFlashTwice->size(), vStatueFlashTwice, statue1, false, 20)));
	std::vector<unsigned char>* vDoorOpen = new std::vector<unsigned char>;
	vDoorOpen->push_back(1);
	vDoorOpen->push_back(2);
	vDoorOpen->push_back(0);
	EventManagement::delEvent(EventManagement::addEvent(new ChangeAnimEvent(0, 0, vDoorOpen->size(), vDoorOpen, door, false, 20)));

	//EventManagement::delEvent(EventManagement::addEvent(new StateMachineTriggerEvent((char)0, (char)0, 4, 1), false));
}
void MapDungeonScript2::exit() {
	printf("mapDungeon script 2 exit\n");
}
void MapDungeonScript2::handleEvents() {
	printf("mapDungeon script 2 handleEvents\n");
}*/
const MapData mapDungeonData = {
	"tilesetDungeon.bmp", 24, mapDungeonhoehe, mapDungeonbreite, mapDungeontiledata, mapDungeonwalkdata, new MapDungeonScript1(),
	{ { -1,0,0 },{ -1,0,0 },{ -1,0,0 },{ -1,0,0 } }, mapDungeonborder, 0,
	{ }
};