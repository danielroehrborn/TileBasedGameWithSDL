#pragma once
const SpriteData::AnimAndTimingList ShipLookDown = { 4,{
	{ { 1,1,46,74 },{ 0,0 },30 },
	{ { 49,1,46,74 },{ 0,0 },3 },
	{ { 97,1,46,74 },{ 0,0 },3 },
	{ { 145,1,46,74 },{ 0,0 },30 }
} };
const SpriteData::AnimAndTimingList ShipWalkDown = { 4,{
	{ { 193,1,46,74 },{ 0,0 },5 },
	{ { 241,1,46,74 },{ 0,0 },5 },
	{ { 289,1,46,74 },{ 0,0 },5 },
	{ { 289,1,46,74 },{ 0,0 },5 }
} };
const SpriteData::AnimAndTimingList ShipLookUp = { 4,{
	{ { 1,78,46,74 },{ 0,0 },6 },
	{ { 49,78,46,74 },{ 0,0 },6 },
	{ { 97,78,46,74 },{ 0,0 },6 },
	{ { 145,78,46,74 },{ 0,0 },160 }
} };
const SpriteData::AnimAndTimingList ShipWalkUp = { 4,{ 
	{ { 193,78,46,74 },{ 0,0 },9 },
	{ { 241,78,46,74 },{ 0,0 },9 },
	{ { 289,78,46,74 },{ 0,0 },9 },
	{ { 289,78,46,74 },{ 0,0 },9 }
} };
const SpriteData::AnimAndTimingList ShipLookLeft = { 4,{ 
	{ { 1,155,74,46 },{ 0,0 },16 },
	{ { 77,155,74,46 },{ 0,0 },16 },
	{ { 153,155,74,46 },{ 0,0 },16 },
	{ { 229,155,74,46 },{ 0,0 },16 }
} };
const SpriteData::AnimAndTimingList ShipWalkLeft = { 4,{ 
	{ { 305,155,74,46 },{ 0,0 },9 },
	{ { 381,155,74,46 },{ 0,0 },9 },
	{ { 457,155,74,46 },{ 0,0 },9 },
	{ { 533,155,74,46 },{ 0,0 },9 }
} };
const SpriteData::AnimAndTimingList ShipLookRight = { 4,{
	{ { 1,204,74,46 },{ 0,0 },16 },
	{ { 77,204,74,46 },{ 0,0 },16 },
	{ { 153,204,74,46 },{ 0,0 },16 },
	{ { 229,204,74,46 },{ 0,0 },16 }
} };
const SpriteData::AnimAndTimingList ShipWalkRight = { 4,{ 
	{ { 305,204,74,46 },{ 0,0 },9 },
	{ { 381,204,74,46 },{ 0,0 },9 },
	{ { 457,204,74,46 },{ 0,0 },9 },
	{ { 533,204,74,46 },{ 0,0 },9 }
} };
const SpriteData Ship = {
	7,"Ship.png",8,{ &ShipLookDown, &ShipWalkDown, &ShipLookUp, &ShipWalkUp, &ShipLookLeft,
	&ShipWalkLeft, &ShipLookRight, &ShipWalkRight }
};

const SpriteData::AnimAndTimingList LeftWingLookDown = { 4,{
	{ { 1,253,50,74 },{ 0,0 },10 },
	{ { 53,253,50,74 },{ 0,0 },10 },
	{ { 105,253,50,74 },{ 0,0 },10 },
	{ { 157,253,50,74 },{ 0,0 },30 }
} };
const SpriteData::AnimAndTimingList LeftWingWalkDown = { 4,{
	{ { 209,253,50,74 },{ 0,0 },5 },
	{ { 261,253,50,74 },{ 0,0 },5 },
	{ { 313,253,50,74 },{ 0,0 },5 },
	{ { 365,253,50,74 },{ 0,0 },5 }
} };
const SpriteData::AnimAndTimingList LeftWingLookUp = { 4,{
	{ { 1,330,50,74 },{ 0,0 },16 },
	{ { 53,330,50,74 },{ 0,0 },16 },
	{ { 105,330,50,74 },{ 0,0 },16 },
	{ { 157,330,50,74 },{ 0,0 },16 }
} };
const SpriteData::AnimAndTimingList LeftWingWalkUp = { 4,{
	{ { 209,330,50,74 },{ 0,0 },9 },
	{ { 261,330,50,74 },{ 0,0 },9 },
	{ { 313,330,50,74 },{ 0,0 },9 },
	{ { 365,330,50,74 },{ 0,0 },9 }
} };
const SpriteData::AnimAndTimingList LeftWingLookLeft = { 4,{
	{ { 1,407,74,50 },{ 0,0 },16 },
	{ { 77,407,74,50 },{ 0,0 },16 },
	{ { 153,407,74,50 },{ 0,0 },16 },
	{ { 229,407,74,50 },{ 0,0 },16 }
} };
const SpriteData::AnimAndTimingList LeftWingWalkLeft = { 4,{
	{ { 305,407,74,50 },{ 0,0 },9 },
	{ { 381,407,74,50 },{ 0,0 },9 },
	{ { 457,407,74,50 },{ 0,0 },9 },
	{ { 533,407,74,50 },{ 0,0 },9 }
} };
const SpriteData::AnimAndTimingList LeftWingLookRight = { 4,{
	{ { 1,460,74,50 },{ 0,0 },16 },
	{ { 77,460,74,50 },{ 0,0 },16 },
	{ { 153,460,74,50 },{ 0,0 },16 },
	{ { 229,460,74,50 },{ 0,0 },16 }
} };
const SpriteData::AnimAndTimingList LeftWingWalkRight = { 4,{
	{ { 305,460,74,50 },{ 0,0 },9 },
	{ { 381,460,74,50 },{ 0,0 },9 },
	{ { 457,460,74,50 },{ 0,0 },9 },
	{ { 533,460,74,50 },{ 0,0 },9 }
} };
const SpriteData LeftWing = {
	8,"Ship.png",8,{ &LeftWingLookDown, &LeftWingWalkDown, &LeftWingLookUp, &LeftWingWalkUp, &LeftWingLookLeft,
	&LeftWingWalkLeft, &LeftWingLookRight, &LeftWingWalkRight }
};

const SpriteData::AnimAndTimingList RightWingLookDown = { 4,{
	{ { 1,513,50,74 },{ 0,0 },16 },
	{ { 53,513,50,74 },{ 0,0 },16 },
	{ { 105,513,50,74 },{ 0,0 },16 },
	{ { 157,513,50,74 },{ 0,0 },16 }
} };
const SpriteData::AnimAndTimingList RightWingWalkDown = { 4,{
	{ { 209,513,50,74 },{ 0,0 },9 },
	{ { 261,513,50,74 },{ 0,0 },9 },
	{ { 313,513,50,74 },{ 0,0 },9 },
	{ { 365,513,50,74 },{ 0,0 },9 }
} };
const SpriteData::AnimAndTimingList RightWingLookUp = { 4,{
	{ { 1,590,50,74 },{ 0,0 },16 },
	{ { 53,590,50,74 },{ 0,0 },16 },
	{ { 105,590,50,74 },{ 0,0 },16 },
	{ { 157,590,50,74 },{ 0,0 },16 }
} };
const SpriteData::AnimAndTimingList RightWingWalkUp = { 4,{
	{ { 209,590,50,74 },{ 0,0 },9 },
	{ { 261,590,50,74 },{ 0,0 },9 },
	{ { 313,590,50,74 },{ 0,0 },9 },
	{ { 365,590,50,74 },{ 0,0 },9 }
} };
const SpriteData::AnimAndTimingList RightWingLookLeft = { 4,{
	{ { 1,667,74,50 },{ 0,0 },16 },
	{ { 77,667,74,50 },{ 0,0 },16 },
	{ { 153,667,74,50 },{ 0,0 },16 },
	{ { 229,667,74,50 },{ 0,0 },16 }
} };
const SpriteData::AnimAndTimingList RightWingWalkLeft = { 4,{
	{ { 305,667,74,50 },{ 0,0 },9 },
	{ { 381,667,74,50 },{ 0,0 },9 },
	{ { 457,667,74,50 },{ 0,0 },9 },
	{ { 533,667,74,50 },{ 0,0 },9 }
} };
const SpriteData::AnimAndTimingList RightWingLookRight = { 4,{
	{ { 1,720,74,50 },{ 0,0 },16 },
	{ { 77,720,74,50 },{ 0,0 },16 },
	{ { 153,720,74,50 },{ 0,0 },16 },
	{ { 229,720,74,50 },{ 0,0 },16 }
} };
const SpriteData::AnimAndTimingList RightWingWalkRight = { 4,{
	{ { 305,720,74,50 },{ 0,0 },9 },
	{ { 381,720,74,50 },{ 0,0 },9 },
	{ { 457,720,74,50 },{ 0,0 },9 },
	{ { 533,720,74,50 },{ 0,0 },9 }
} };
const SpriteData RightWing = {
	9,"Ship.png",8,{ &RightWingLookDown, &RightWingWalkDown, &RightWingLookUp, &RightWingWalkUp, &RightWingLookLeft,
	&RightWingWalkLeft, &RightWingLookRight, &RightWingWalkRight }
};