#pragma once
const SpriteData::AnimAndTimingList Statue1Normal = { 1,{ { { 164,7,24,34 },{ 0,0 },16 } } };
const SpriteData::AnimAndTimingList Statue1GoOnOffBlue = { 4,{ { { 196,7,24,34 },{ 0,0 },5 },{ { 228,7,24,34 },{ 0,0 },9 },{ { 196,7,24,34 },{ 0,0 },5 },{ { 164,7,24,34 },{ 0,0 },9 } } };
const SpriteData::AnimAndTimingList Statue1GoOnBlue = { 2,{ { { 196,7,24,34 },{ 0,0 },5 },{ { 228,7,24,34 },{ 0,0 },9 } } };
const SpriteData::AnimAndTimingList Statue1GoOffBlue = { 2,{ { { 196,7,24,34 },{ 0,0 },5 },{ { 164,7,24,34 },{ 0,0 },9 } } };
const SpriteData::AnimAndTimingList Statue1OnBlue = { 1,{ { { 228,7,24,34 },{ 0,0 },16 } } };

const SpriteData::AnimAndTimingList Statue1GoOnOffOrange = { 4,{ { { 260,7,24,34 },{ 0,0 },5 },{ { 292,7,24,34 },{ 0,0 },9 },{ { 260,7,24,34 },{ 0,0 },5 },{ { 164,7,24,34 },{ 0,0 },9 } } };
const SpriteData::AnimAndTimingList Statue1GoOnOrange = { 2,{ { { 260,7,24,34 },{ 0,0 },5 },{ { 292,7,24,34 },{ 0,0 },9 } } };
const SpriteData::AnimAndTimingList Statue1GoOffOrange = { 2,{ { { 260,7,24,34 },{ 0,0 },5 },{ { 164,7,24,34 },{ 0,0 },9 } } };
const SpriteData::AnimAndTimingList Statue1OnOrange = { 1,{ { { 292,7,24,34 },{ 0,0 },9 } } };

const SpriteData::AnimAndTimingList Statue1GoOnOffGreen = { 4,{ { { 324,7,24,34 },{ 0,0 },5 },{ { 356,7,24,34 },{ 0,0 },9 },{ { 324,7,24,34 },{ 0,0 },5 },{ { 164,7,24,34 },{ 0,0 },9 } } };
const SpriteData::AnimAndTimingList Statue1GoOnGreen = { 2,{ { { 324,7,24,34 },{ 0,0 },5 },{ { 356,7,24,34 },{ 0,0 },9 } } };
const SpriteData::AnimAndTimingList Statue1GoOffGreen = { 2,{ { { 324,7,24,34 },{ 0,0 },5 },{ { 164,7,24,34 },{ 0,0 },9 } } };
const SpriteData::AnimAndTimingList Statue1OnGreen = { 1,{ { { 356,7,24,34 },{ 0,0 },9 } } };

const SpriteData DungeonStatue1 = {
	10,"DungeonSprites.png",13,{ &Statue1Normal, &Statue1GoOnOffBlue, &Statue1GoOnBlue, &Statue1GoOffBlue, &Statue1OnBlue,
												&Statue1GoOnOffOrange, &Statue1GoOnOrange, &Statue1GoOffOrange, &Statue1OnOrange,
												&Statue1GoOnOffGreen, &Statue1GoOnGreen, &Statue1GoOffGreen, &Statue1OnGreen }
};

const SpriteData::AnimAndTimingList DoorOpen = { 1,{ { { 192,137,48,22 },{ 0,0 },16 } } };
const SpriteData::AnimAndTimingList DoorClosed = { 1,{ { { 0,137,48,22 },{ 0,0 },16 } } };
const SpriteData::AnimAndTimingList DoorGoOpen = { 4,{ { { 48,137,48,22 },{ 0,0 },5 },{ { 96,137,48,22 },{ 0,0 },5 },{ { 144,137,48,22 },{ 0,0 },5 },{ { 192,137,48,22 },{ 0,0 },9 } } };
const SpriteData::AnimAndTimingList DoorGoClosed = { 4,{ { { 144,137,48,22 },{ 0,0 },5 },{ { 96,137,48,22 },{ 0,0 },5 },{ { 48,137,48,22 },{ 0,0 },5 },{ { 0,137,48,22 },{ 0,0 },9 } } };
const SpriteData::AnimAndTimingList DoorGoOpenClosed = { 8,{ 
	{ { 144,137,48,22 },{ 0,0 },4 },
	{ { 96,137,48,22 },{ 0,0 },5 },
	{ { 48,137,48,22 },{ 0,0 },6 },
	{ { 0,137,48,22 },{ 0,0 },20 },
	{ { 48,137,48,22 },{ 0,0 },4 },
	{ { 96,137,48,22 },{ 0,0 },5 },
	{ { 144,137,48,22 },{ 0,0 },6 },
	{ { 192,137,48,22 },{ 0,0 },20 },
} };

const SpriteData DungeonDoor = {
	10,"DungeonSprites.png",5,{ &DoorOpen, &DoorClosed, &DoorGoOpen, &DoorGoClosed, &DoorGoOpenClosed }
};

const SpriteData::AnimAndTimingList SwitchOn = { 1,{ { { 0,82,16,13 },{ 0,0 },16 } } };
const SpriteData::AnimAndTimingList SwitchOff = { 1,{ { { 96,82,16,13 },{ 0,0 },16 } } };
const SpriteData::AnimAndTimingList SwitchGoOn = { 6,{ { { 80,82,16,13 },{ 0,0 },4 },{ { 64,82,16,13 },{ 0,0 },4 },{ { 48,82,16,13 },{ 0,0 },5 },{ { 32,82,16,13 },{ 0,0 },6 },{ { 16,82,16,13 },{ 0,0 },7 },{ { 0,82,16,13 },{ 0,0 },9 } } };
const SpriteData::AnimAndTimingList SwitchGoOff = { 6,{ { { 16,82,16,13 },{ 0,0 },4 },{ { 32,82,16,13 },{ 0,0 },4 },{ { 48,82,16,13 },{ 0,0 },5 },{ { 64,82,16,13 },{ 0,0 },6 },{ { 80,82,16,13 },{ 0,0 },7 },{ { 96,82,16,13 },{ 0,0 },9 } } };
const SpriteData::AnimAndTimingList SwitchGoOnOff = { 12,{ 
	{ { 16,82,16,13 },{ 0,0 },4 },
	{ { 32,82,16,13 },{ 0,0 },4 },
	{ { 48,82,16,13 },{ 0,0 },5 },
	{ { 64,82,16,13 },{ 0,0 },6 },
	{ { 80,82,16,13 },{ 0,0 },7 },
	{ { 96,82,16,13 },{ 0,0 },20 },
	{ { 80,82,16,13 },{ 0,0 },4 },
	{ { 64,82,16,13 },{ 0,0 },4 },
	{ { 48,82,16,13 },{ 0,0 },5 },
	{ { 32,82,16,13 },{ 0,0 },6 },
	{ { 16,82,16,13 },{ 0,0 },7 },
	{ { 00,82,16,13 },{ 0,0 },20 }
} };
const SpriteData DungeonSwitch = {
	10,"DungeonSprites.png",5,{ &SwitchOn, &SwitchOff, &SwitchGoOn, &SwitchGoOff, &SwitchGoOnOff }
};

const SpriteData::AnimAndTimingList IronDoorOpen = { 1,{ { { 0,96,16,16 },{ 0,0 },16 } } };
const SpriteData::AnimAndTimingList IronDoorClosed = { 1,{ { { 64,96,16,16 },{ 0,0 },16 } } };
const SpriteData::AnimAndTimingList IronDoorGoOpen = { 4,{ { { 48,96,16,16 },{ 0,0 },5 },{ { 32,96,16,16 },{ 0,0 },6 },{ { 16,96,16,16 },{ 0,0 },7 },{ { 0,96,16,16 },{ 0,0 },8 } } };
const SpriteData::AnimAndTimingList IronDoorGoClosed = { 4,{ { { 16,96,16,16 },{ 0,0 },5 },{ { 32,96,16,16 },{ 0,0 },6 },{ { 48,96,16,16 },{ 0,0 },7 },{ { 64,96,16,16 },{ 0,0 },8 } } };
const SpriteData::AnimAndTimingList IronDoorGoOpenClosed = { 8,{
	{ { 16,96,16,16 },{ 0,0 },5 },
	{ { 32,96,16,16 },{ 0,0 },6 },
	{ { 48,96,16,16 },{ 0,0 },7 },
	{ { 64,96,16,16 },{ 0,0 },20 },
	{ { 48,96,16,16 },{ 0,0 },5 },
	{ { 32,96,16,16 },{ 0,0 },6 },
	{ { 16,96,16,16 },{ 0,0 },7 },
	{ { 00,96,16,16 },{ 0,0 },20 }
} };
const SpriteData DungeonIronDoor = {
	10,"DungeonSprites.png",5,{ &IronDoorOpen, &IronDoorClosed, &IronDoorGoOpen, &IronDoorGoClosed, &IronDoorGoOpenClosed }
};

const SpriteData::AnimAndTimingList WoodDoorOpen = { 1,{ { { 112,112,16,16 },{ 0,0 },16 } } };
const SpriteData::AnimAndTimingList WoodDoorClosed = { 1,{ { { 64,112,16,16 },{ 0,0 },16 } } };
const SpriteData::AnimAndTimingList WoodDoorGoOpen = { 3,{ { { 80,112,16,16 },{ 0,0 },5 },{ { 96,112,16,16 },{ 0,0 },6 },{ { 112,112,16,16 },{ 0,0 },7 } } };
const SpriteData::AnimAndTimingList WoodDoorGoClosed = { 3,{ { { 96,112,16,16 },{ 0,0 },5 },{ { 80,112,16,16 },{ 0,0 },6 },{ { 64,112,16,16 },{ 0,0 },7 } } };
const SpriteData::AnimAndTimingList WoodDoorGoOpenClosed = { 6,{
	{ { 80,112,16,16 },{ 0,0 },5 },
	{ { 96,112,16,16 },{ 0,0 },6 },
	{ { 112,112,16,16 },{ 0,0 },20 },
	{ { 96,112,16,16 },{ 0,0 },5 },
	{ { 80,112,16,16 },{ 0,0 },6 },
	{ { 64,112,16,16 },{ 0,0 },20 }
} };
const SpriteData DungeonWoodDoor = {
	10,"DungeonSprites.png",5,{ &WoodDoorOpen, &WoodDoorClosed, &WoodDoorGoOpen, &WoodDoorGoClosed, &WoodDoorGoOpenClosed }
};