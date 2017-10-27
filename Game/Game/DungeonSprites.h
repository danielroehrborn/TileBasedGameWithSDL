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
const SpriteData::AnimAndTimingList DoorGoOpen = { 4,{ { { 48,137,48,22 },{ 0,0 },5 },{ { 96,137,48,22 },{ 0,0 },9 },{ { 144,137,48,22 },{ 0,0 },5 },{ { 192,137,48,22 },{ 0,0 },9 } } };
const SpriteData::AnimAndTimingList DoorGoClosed = { 4,{ { { 144,137,48,22 },{ 0,0 },5 },{ { 96,137,48,22 },{ 0,0 },9 },{ { 48,137,48,22 },{ 0,0 },5 },{ { 0,137,48,22 },{ 0,0 },9 } } };
const SpriteData DungeonDoor = {
	11,"DungeonSprites.png",4,{ &DoorOpen, &DoorClosed, &DoorGoOpen, &DoorGoClosed }
};