#pragma once
const SpriteData::AnimAndTimingList ShipLookDown = { 4,{
	{ { 1,1,46,74 },{ 0,0 },50 },
	{ { 49,1,46,74 },{ 0,0 },100 },
	{ { 97,1,46,74 },{ 0,0 },50 },
	{ { 145,1,46,74 },{ 0,0 },100 }
} };
const SpriteData::AnimAndTimingList ShipWalkDown = { 4,{
	{ { 193,1,46,74 },{ 0,0 },5 },
	{ { 241,1,46,74 },{ 0,0 },5 },
	{ { 289,1,46,74 },{ 0,0 },5 },
	{ { 289,1,46,74 },{ 0,0 },5 }
} };
const SpriteData::AnimAndTimingList ShipLookUp = { 4,{
	{ { 1,78,46,74 },{ 0,0 },50 },
	{ { 49,78,46,74 },{ 0,0 },100 },
	{ { 97,78,46,74 },{ 0,0 },50 },
	{ { 145,78,46,74 },{ 0,0 },100 }
} };
const SpriteData::AnimAndTimingList ShipWalkUp = { 4,{
	{ { 193,78,46,74 },{ 0,0 },5 },
	{ { 241,78,46,74 },{ 0,0 },5 },
	{ { 289,78,46,74 },{ 0,0 },5 },
	{ { 289,78,46,74 },{ 0,0 },5 }
} };
const SpriteData::AnimAndTimingList ShipLookLeft = { 4,{
	{ { 1,155,74,46 },{ 0,0 },50 },
	{ { 77,155,74,46 },{ 0,0 },100 },
	{ { 153,155,74,46 },{ 0,0 },50 },
	{ { 229,155,74,46 },{ 0,0 },100 }
} };
const SpriteData::AnimAndTimingList ShipWalkLeft = { 4,{
	{ { 305,155,74,46 },{ 0,0 },5 },
	{ { 381,155,74,46 },{ 0,0 },5 },
	{ { 457,155,74,46 },{ 0,0 },5 },
	{ { 533,155,74,46 },{ 0,0 },5 }
} };
const SpriteData::AnimAndTimingList ShipLookRight = { 4,{
	{ { 1,204,74,46 },{ 0,0 },50 },
	{ { 77,204,74,46 },{ 0,0 },100 },
	{ { 153,204,74,46 },{ 0,0 },50 },
	{ { 229,204,74,46 },{ 0,0 },100 }
} };
const SpriteData::AnimAndTimingList ShipWalkRight = { 4,{
	{ { 305,204,74,46 },{ 0,0 },5 },
	{ { 381,204,74,46 },{ 0,0 },5 },
	{ { 457,204,74,46 },{ 0,0 },5 },
	{ { 533,204,74,46 },{ 0,0 },5 }
} };
const SpriteData Ship = {
	7,"Ship.png",8,{ &ShipLookDown, &ShipWalkDown, &ShipLookUp, &ShipWalkUp, &ShipLookLeft,
	&ShipWalkLeft, &ShipLookRight, &ShipWalkRight }
};

const SpriteData::AnimAndTimingList LeftWingLookDown = { 4,{
	{ { 1,253,50,74 },{ 0,0 },5 },
	{ { 53,253,50,74 },{ 0,0 },2 },
	{ { 105,253,50,74 },{ 0,0 },5 },
	{ { 157,253,50,74 },{ 0,0 },120 }
} };
const SpriteData::AnimAndTimingList LeftWingWalkDown = { 4,{
	{ { 209,253,50,74 },{ 0,0 },5 },
	{ { 261,253,50,74 },{ 0,0 },5 },
	{ { 313,253,50,74 },{ 0,0 },5 },
	{ { 365,253,50,74 },{ 0,0 },5 }
} };
const SpriteData::AnimAndTimingList LeftWingLookUp = { 4,{
	{ { 1,330,50,74 },{ 0,0 },5 },
	{ { 53,330,50,74 },{ 0,0 },3 },
	{ { 105,330,50,74 },{ 0,0 },5 },
	{ { 157,330,50,74 },{ 0,0 },70 }
} };
const SpriteData::AnimAndTimingList LeftWingWalkUp = { 4,{
	{ { 209,330,50,74 },{ 0,0 },5 },
	{ { 261,330,50,74 },{ 0,0 },5 },
	{ { 313,330,50,74 },{ 0,0 },5 },
	{ { 365,330,50,74 },{ 0,0 },5 }
} };
const SpriteData::AnimAndTimingList LeftWingLookLeft = { 4,{
	{ { 1,407,74,50 },{ 0,0 },5 },
	{ { 77,407,74,50 },{ 0,0 },3 },
	{ { 153,407,74,50 },{ 0,0 },5 },
	{ { 229,407,74,50 },{ 0,0 },70 }
} };
const SpriteData::AnimAndTimingList LeftWingWalkLeft = { 4,{
	{ { 305,407,74,50 },{ 0,0 },5 },
	{ { 381,407,74,50 },{ 0,0 },5 },
	{ { 457,407,74,50 },{ 0,0 },5 },
	{ { 533,407,74,50 },{ 0,0 },5 }
} };
const SpriteData::AnimAndTimingList LeftWingLookRight = { 4,{
	{ { 1,460,74,50 },{ 0,0 },5 },
	{ { 77,460,74,50 },{ 0,0 },3 },
	{ { 153,460,74,50 },{ 0,0 },5 },
	{ { 229,460,74,50 },{ 0,0 },70 }
} };
const SpriteData::AnimAndTimingList LeftWingWalkRight = { 4,{
	{ { 305,460,74,50 },{ 0,0 },5 },
	{ { 381,460,74,50 },{ 0,0 },5 },
	{ { 457,460,74,50 },{ 0,0 },5 },
	{ { 533,460,74,50 },{ 0,0 },5 }
} };
const SpriteData LeftWing = {
	8,"Ship.png",8,{ &LeftWingLookDown, &LeftWingWalkDown, &LeftWingLookUp, &LeftWingWalkUp, &LeftWingLookLeft,
	&LeftWingWalkLeft, &LeftWingLookRight, &LeftWingWalkRight }
};

const SpriteData::AnimAndTimingList RightWingLookDown = { 4,{
	{ { 1,513,50,74 },{ 0,0 },5 },
	{ { 53,513,50,74 },{ 0,0 },2 },
	{ { 105,513,50,74 },{ 0,0 },5 },
	{ { 157,513,50,74 },{ 0,0 },120 }
} };
const SpriteData::AnimAndTimingList RightWingWalkDown = { 4,{
	{ { 209,513,50,74 },{ 0,0 },5 },
	{ { 261,513,50,74 },{ 0,0 },5 },
	{ { 313,513,50,74 },{ 0,0 },5 },
	{ { 365,513,50,74 },{ 0,0 },5 }
} };
const SpriteData::AnimAndTimingList RightWingLookUp = { 4,{
	{ { 1,590,50,74 },{ 0,0 },5 },
	{ { 53,590,50,74 },{ 0,0 },3 },
	{ { 105,590,50,74 },{ 0,0 },5 },
	{ { 157,590,50,74 },{ 0,0 },70 }
} };
const SpriteData::AnimAndTimingList RightWingWalkUp = { 4,{
	{ { 209,590,50,74 },{ 0,0 },5 },
	{ { 261,590,50,74 },{ 0,0 },5 },
	{ { 313,590,50,74 },{ 0,0 },5 },
	{ { 365,590,50,74 },{ 0,0 },5 }
} };
const SpriteData::AnimAndTimingList RightWingLookLeft = { 4,{
	{ { 1,667,74,50 },{ 0,0 },5 },
	{ { 77,667,74,50 },{ 0,0 },3 },
	{ { 153,667,74,50 },{ 0,0 },5 },
	{ { 229,667,74,50 },{ 0,0 },70 }
} };
const SpriteData::AnimAndTimingList RightWingWalkLeft = { 4,{
	{ { 305,667,74,50 },{ 0,0 },5 },
	{ { 381,667,74,50 },{ 0,0 },5 },
	{ { 457,667,74,50 },{ 0,0 },5 },
	{ { 533,667,74,50 },{ 0,0 },5 }
} };
const SpriteData::AnimAndTimingList RightWingLookRight = { 4,{
	{ { 1,720,74,50 },{ 0,0 },5 },
	{ { 77,720,74,50 },{ 0,0 },3 },
	{ { 153,720,74,50 },{ 0,0 },5 },
	{ { 229,720,74,50 },{ 0,0 },70 }
} };
const SpriteData::AnimAndTimingList RightWingWalkRight = { 4,{
	{ { 305,720,74,50 },{ 0,0 },5 },
	{ { 381,720,74,50 },{ 0,0 },5 },
	{ { 457,720,74,50 },{ 0,0 },5 },
	{ { 533,720,74,50 },{ 0,0 },5 }
} };
const SpriteData RightWing = {
	9,"Ship.png",8,{ &RightWingLookDown, &RightWingWalkDown, &RightWingLookUp, &RightWingWalkUp, &RightWingLookLeft,
	&RightWingWalkLeft, &RightWingLookRight, &RightWingWalkRight }
};

const SpriteData* shipGroupSprites[] = {
	&LeftWing, &RightWing, &Ship
};
const SpriteGroupData::GroupAnim shipGroupLookDown = {
	10,//duration
	{0,0,0,0},//movement
	{//groupSpriteAnims for this groupAnim
		{0,{1,1,0,0}}, {0,{58,0,0,0}}, {0,{30,3,0,0}}
	}
};
const SpriteGroupData::GroupAnim shipGroupWalkDown =
{ 10, { 0,3,0,0 }, {{ 1,{ 2,1,0,0 } },{ 1,{ 57,0,0,0 } },{ 1,{ 30,3,0,0 } }} };
const SpriteGroupData::GroupAnim shipGroupLookUp =
{ 10,{ 0,0,0,0 },{ { 2,{ 58,0,0,0 } },{ 2,{ 1,1,0,0 } },{ 2,{ 30,3,0,0 } } } };
const SpriteGroupData::GroupAnim shipGroupWalkUp =
{ 10,{ 0,-3,0,0 },{ { 3,{ 57,0,0,0 } },{ 3,{ 2,1,0,0 } },{ 3,{ 30,3,0,0 } } } };
const SpriteGroupData::GroupAnim shipGroupLookLeft =
{ 10,{ 0,0,0,0 },{ { 4,{ 1,1,0,0 } },{ 4,{ 1,65,0,0 } },{ 4,{ 6,33,0,0 } } } };
const SpriteGroupData::GroupAnim shipGroupWalkLeft =
{ 10,{ -3,0,0,0 },{ { 5,{ 1,2,0,0 } },{ 5,{ 1,64,0,0 } },{ 5,{ 6,33,0,0 } } } };
const SpriteGroupData::GroupAnim shipGroupRight =
{ 10,{ 0,0,0,0 },{ { 6,{ 1,65,0,0 } },{ 6,{ 1,1,0,0 } },{ 6,{ 6,33,0,0 } } } };
const SpriteGroupData::GroupAnim shipGroupWalkRight =
{ 10,{ 3,0,0,0 },{ { 7,{ 1,64,0,0 } },{ 7,{ 1,2,0,0 } },{ 7,{ 6,33,0,0 } } } };
const SpriteGroupData shipGroupData = {
	{ (12 + 8) * 16, (12 + 8) * 16 ,120 ,120 }, //mapPos + width, height
	3, //numGroupSprites
	shipGroupSprites, //sprites in group
	8, //num groupAnims
	{//GroupAnims
		&shipGroupLookDown,&shipGroupWalkDown,&shipGroupLookUp,&shipGroupWalkUp,&shipGroupLookLeft,&shipGroupWalkLeft,&shipGroupRight,&shipGroupWalkRight}
};