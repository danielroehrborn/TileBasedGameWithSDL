#pragma once
const SpriteData::AnimAndTimingList HiroLookDown = { 1,{ { { 1,34,32,32 },{ 0,0 },16 } } };
const SpriteData::AnimAndTimingList HiroWalkDown = { 4,{ { { 34,34,32,32 },{ 0,1 },9 },{ { 1,34,32,32 },{ 0,1 },9 },{ { 67,34,32,32 },{ 0,1 },9 },{ { 1,34,32,32 },{ 0,1 },9 } } };
const SpriteData::AnimAndTimingList HiroLookUp = { 1,{ { { 1,1,32,32 },{ 0,0 },16 } } };
const SpriteData::AnimAndTimingList HiroWalkUp = { 4,{ { { 34,1,32,32 },{ 0,-1 },9 },{ { 1,1,32,32 },{ 0,-1 },9 },{ { 67,1,32,32 },{ 0,-1 },9 },{ { 1,1,32,32 },{ 0,-1 },9 } } };
const SpriteData::AnimAndTimingList HiroLookLeft = { 1,{ { { 1,67,32,32 },{ 0,0 },16 } } };
const SpriteData::AnimAndTimingList HiroWalkLeft = { 4,{ { { 34,67,32,32 },{ -1,0 },9 },{ { 1,67,32,32 },{ -1,0 },9 },{ { 67,67,32,32 },{ -1,0 },9 },{ { 1,67,32,32 },{ -1,0 },9 } } };
const SpriteData::AnimAndTimingList HiroLookRight = { 1,{ { { 1,100,32,32 },{ 0,0 },16 } } };
const SpriteData::AnimAndTimingList HiroWalkRight = { 4,{ { { 34,100,32,32 },{ 1,0 },9 },{ { 1,100,32,32 },{ 1,0 },9 },{ { 67,100,32,32 },{ 1,0 },9 },{ { 1,100,32,32 },{ 1,0 },9 } } };
const SpriteData::AnimAndTimingList HiroRunDown = { 4,{ { { 166,34,32,32 },{ 0,3 },8 },{ { 133,34,32,32 },{ 0,2 },6 },{ { 199,34,32,32 },{ 0,3 },8 },{ { 133,34,32,32 },{ 0,2 },6 } } };
const SpriteData::AnimAndTimingList HiroRunUp = { 4,{ { { 166,1,32,32 },{ 0,-3 },8 },{ { 133,1,32,32 },{ 0,-2 },6 },{ { 199,1,32,32 },{ 0,-3 },8 },{ { 133,1,32,32 },{ 0,-2 },6 } } };
const SpriteData::AnimAndTimingList HiroRunLeft = { 4,{ { { 166,67,32,32 },{ -3,0 },8 },{ { 133,67,32,32 },{ -2,0 },6 },{ { 199,67,32,32 },{ -3,0 },8 },{ { 133,67,32,32 },{ -2,0 },6 } } };
const SpriteData::AnimAndTimingList HiroRunRight = { 4,{ { { 166,100,32,32 },{ 3,0 },8 },{ { 133,100,32,32 },{ 2,0 },6 },{ { 199,100,32,32 },{ 3,0 },8 },{ { 133,100,32,32 },{ 2,0 },6 } } };
const SpriteData::AnimAndTimingList HiroAngelDown = { 4,{ { { 1,594,64,64 },{ 0,0 },12 },{ { 66,594,64,64 },{ 0,0 },8 },{ { 131,594,64,64 },{ 0,1 },4 },{ { 196,594,64,64 },{ 0,-1 },12 } } };
const SpriteData Hiro = {
	"HiroSprites.png",13,{ &HiroLookDown, &HiroWalkDown, &HiroLookUp, &HiroWalkUp, &HiroLookLeft,
	&HiroWalkLeft, &HiroLookRight, &HiroWalkRight, &HiroRunDown, &HiroRunUp, &HiroRunLeft, &HiroRunRight, &HiroAngelDown }
};