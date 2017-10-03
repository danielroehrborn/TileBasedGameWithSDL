#pragma once
const SpriteData::AnimAndTimingList ShipLookDown = { 3,{//ok
	{ { 1,39,22,37 },{ 0,0 },16 },
	{ { 25,39,22,37 },{ 0,0 },16 },
	{ { 49,39,22,37 },{ 0,0 },16 }
} };
const SpriteData::AnimAndTimingList ShipWalkDown = { 4,{//ok
	{ { 73,39,22,37 },{ 0,1 },9 },
	{ { 97,39,22,37 },{ 0,1 },9 },
	{ { 121,39,22,37 },{ 0,1 },9 },
	{ { 145,39,22,37 },{ 0,1 },9 } 
} };
const SpriteData::AnimAndTimingList ShipLookUp = { 3,{
	{ { 2,39,22,37 },{ 0,0 },16 },
	{ { 25,39,22,37 },{ 0,0 },16 },
	{ { 49,39,22,37 },{ 0,0 },16 }
} };
const SpriteData::AnimAndTimingList ShipWalkUp = { 4,{ 
	{ { 34,1,32,32 },{ 0,-1 },9 },
	{ { 1,1,32,32 },{ 0,-1 },9 },
	{ { 67,1,32,32 },{ 0,-1 },9 },
	{ { 1,1,32,32 },{ 0,-1 },9 } 
} };
const SpriteData::AnimAndTimingList ShipLookLeft = { 1,{ 
	{ { 1,67,32,32 },{ 0,0 },16 } 
} };
const SpriteData::AnimAndTimingList ShipWalkLeft = { 4,{ 
	{ { 34,67,32,32 },{ -1,0 },9 },
	{ { 1,67,32,32 },{ -1,0 },9 },
	{ { 67,67,32,32 },{ -1,0 },9 },
	{ { 1,67,32,32 },{ -1,0 },9 } 
} };
const SpriteData::AnimAndTimingList ShipLookRight = { 1,{ 
	{ { 1,100,32,32 },{ 0,0 },16 } 
} };
const SpriteData::AnimAndTimingList ShipWalkRight = { 4,{ 
	{ { 34,100,32,32 },{ 1,0 },9 },
	{ { 1,100,32,32 },{ 1,0 },9 },
	{ { 67,100,32,32 },{ 1,0 },9 },
	{ { 1,100,32,32 },{ 1,0 },9 } 
} };
const SpriteData Ship = {
	7,"Ship.png",8,{ &ShipLookDown, &ShipWalkDown, &ShipLookUp, &ShipWalkUp, &ShipLookLeft,
	&ShipWalkLeft, &ShipLookRight, &ShipWalkRight }
};

const SpriteData::AnimAndTimingList LeftWingLookDown = { 4,{//ok
	{ { 2,165,25,38 },{ 0,0 },16 },
	{ { 28,165,25,38 },{ 0,0 },16 },
	{ { 54,165,25,38 },{ 0,0 },16 },
	{ { 80,165,25,38 },{ 0,0 },16 }
} };
const SpriteData::AnimAndTimingList LeftWingWalkDown = { 4,{//ok
	{ { 107,165,25,38 },{ 0,1 },9 },
	{ { 132,165,25,38 },{ 0,1 },9 },
	{ { 159,165,25,38 },{ 0,1 },9 },
	{ { 184,165,25,38 },{ 0,1 },9 }
} };
const SpriteData::AnimAndTimingList LeftWingLookUp = { 3,{
	{ { 2,39,22,37 },{ 0,0 },16 },
	{ { 25,39,22,37 },{ 0,0 },16 },
	{ { 49,39,22,37 },{ 0,0 },16 }
} };
const SpriteData::AnimAndTimingList LeftWingWalkUp = { 4,{
	{ { 34,1,32,32 },{ 0,-1 },9 },
	{ { 1,1,32,32 },{ 0,-1 },9 },
	{ { 67,1,32,32 },{ 0,-1 },9 },
	{ { 1,1,32,32 },{ 0,-1 },9 }
} };
const SpriteData::AnimAndTimingList LeftWingLookLeft = { 1,{
	{ { 1,67,32,32 },{ 0,0 },16 }
} };
const SpriteData::AnimAndTimingList LeftWingWalkLeft = { 4,{
	{ { 34,67,32,32 },{ -1,0 },9 },
	{ { 1,67,32,32 },{ -1,0 },9 },
	{ { 67,67,32,32 },{ -1,0 },9 },
	{ { 1,67,32,32 },{ -1,0 },9 }
} };
const SpriteData::AnimAndTimingList LeftWingLookRight = { 1,{
	{ { 1,100,32,32 },{ 0,0 },16 }
} };
const SpriteData::AnimAndTimingList LeftWingWalkRight = { 4,{
	{ { 34,100,32,32 },{ 1,0 },9 },
	{ { 1,100,32,32 },{ 1,0 },9 },
	{ { 67,100,32,32 },{ 1,0 },9 },
	{ { 1,100,32,32 },{ 1,0 },9 }
} };
const SpriteData LeftWing = {
	8,"Ship.png",8,{ &LeftWingLookDown, &LeftWingWalkDown, &LeftWingLookUp, &LeftWingWalkUp, &LeftWingLookLeft,
	&LeftWingWalkLeft, &LeftWingLookRight, &LeftWingWalkRight }
};

const SpriteData::AnimAndTimingList RightWingLookDown = { 3,{
	{ { 2,39,22,37 },{ 0,0 },16 },
	{ { 25,39,22,37 },{ 0,0 },16 },
	{ { 49,39,22,37 },{ 0,0 },16 }
} };
const SpriteData::AnimAndTimingList RightWingWalkDown = { 4,{
	{ { 73,39,22,37 },{ 0,1 },9 },
	{ { 97,39,22,37 },{ 0,1 },9 },
	{ { 121,39,22,37 },{ 0,1 },9 },
	{ { 145,39,22,37 },{ 0,1 },9 }
} };
const SpriteData::AnimAndTimingList RightWingLookUp = { 3,{
	{ { 2,39,22,37 },{ 0,0 },16 },
	{ { 25,39,22,37 },{ 0,0 },16 },
	{ { 49,39,22,37 },{ 0,0 },16 }
} };
const SpriteData::AnimAndTimingList RightWingWalkUp = { 4,{
	{ { 34,1,32,32 },{ 0,-1 },9 },
	{ { 1,1,32,32 },{ 0,-1 },9 },
	{ { 67,1,32,32 },{ 0,-1 },9 },
	{ { 1,1,32,32 },{ 0,-1 },9 }
} };
const SpriteData::AnimAndTimingList RightWingLookLeft = { 1,{
	{ { 1,67,32,32 },{ 0,0 },16 }
} };
const SpriteData::AnimAndTimingList RightWingWalkLeft = { 4,{
	{ { 34,67,32,32 },{ -1,0 },9 },
	{ { 1,67,32,32 },{ -1,0 },9 },
	{ { 67,67,32,32 },{ -1,0 },9 },
	{ { 1,67,32,32 },{ -1,0 },9 }
} };
const SpriteData::AnimAndTimingList RightWingLookRight = { 1,{
	{ { 1,100,32,32 },{ 0,0 },16 }
} };
const SpriteData::AnimAndTimingList RightWingWalkRight = { 4,{
	{ { 34,100,32,32 },{ 1,0 },9 },
	{ { 1,100,32,32 },{ 1,0 },9 },
	{ { 67,100,32,32 },{ 1,0 },9 },
	{ { 1,100,32,32 },{ 1,0 },9 }
} };
const SpriteData RightWing = {
	9,"Ship.png",8,{ &RightWingLookDown, &RightWingWalkDown, &RightWingLookUp, &RightWingWalkUp, &RightWingLookLeft,
	&RightWingWalkLeft, &RightWingLookRight, &RightWingWalkRight }
};