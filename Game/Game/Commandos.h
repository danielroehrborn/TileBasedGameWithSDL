#pragma once
const SpriteData::AnimAndTimingList CommandosLookDown = { 4,{ { { 599,452,30,41 },{ 0,0 },20 },{ { 631,452,30,41 },{ 0,0 },20 },{ { 663,452,30,41 },{ 0,0 },20 },{ { 631,452,30,41 },{ 0,0 },20 } } };
const SpriteData::AnimAndTimingList CommandosWalkDown = { 8,{ { { 2,192,24,43 },{ 0,1 },6 },{ { 30,192,24,43 },{ 0,1 },8 },{ { 58,192,24,43 },{ 0,1 },8 },{ { 86,192,24,43 },{ 0,1 },6 },{ { 114,192,24,43 },{ 0,1 },8 },{ { 142,192,24,43 },{ 0,1 },6 },{ { 170,192,24,43 },{ 0,1 },8 },{ { 198,192,24,43 },{ 0,1 },8 } } };
const SpriteData::AnimAndTimingList CommandosLookUp = { 4,{ { { 588,315,31,39 },{ 0,0 },20 },{ { 620,315,31,39 },{ 0,0 },20 },{ { 652,315,31,39 },{ 0,0 },20 },{ { 620,315,31,39 },{ 0,0 },20 } } };
const SpriteData::AnimAndTimingList CommandosWalkUp = { 8,{ { { 1,7,24,43 },{ 0,-1 },6 },{ { 29,7,24,43 },{ 0,-1 },8 },{ { 57,7,24,43 },{ 0,-1 },8 },{ { 85,7,24,43 },{ 0,-1 },6 },{ { 113,7,24,43 },{ 0,-1 },8 },{ { 141,7,24,43 },{ 0,-1 },6 },{ { 169,7,24,43 },{ 0,-1 },10 },{ { 197,7,24,43 },{ 0,-1 },10 } } };
const SpriteData::AnimAndTimingList CommandosLookLeft = { 4,{ { { 658,355,17,49 },{ 0,0 },20 },{ { 640,355,17,49 },{ 0,0 },20 },{ { 658,355,17,49 },{ 0,0 },20 },{ { 676,355,17,49 },{ 0,0 },20 } } };
const SpriteData::AnimAndTimingList CommandosWalkLeft = { 8,{ { { 237,442,25,48 },{ -1,0 },6 },{ { 265,442,25,48 },{ -1,0 },8 },{ { 293,442,25,48 },{ -1,0 },10 },{ { 321,442,25,48 },{ -1,0 },6 },{ { 349,442,25,48 },{ -1,0 },8 },{ { 377,442,25,48 },{ -1,0 },6 },{ { 405,442,25,48 },{ -1,0 },10 },{ { 433,442,25,48 },{ -1,0 },8 } } };
const SpriteData::AnimAndTimingList CommandosLookRight = { 4,{ { { 603,355,17,49 },{ 0,0 },20 },{ { 585,355,17,49 },{ 0,0 },20 },{ { 603,355,17,49 },{ 0,0 },20 },{ { 621,355,17,49 },{ 0,0 },20 } } };
const SpriteData::AnimAndTimingList CommandosWalkRight = { 8,{ { { 1,99,25,48 },{ 1,0 },6 },{ { 29,99,25,48 },{ 1,0 },8 },{ { 57,99,25,48 },{ 1,0 },10 },{ { 85,99,25,48 },{ 1,0 },6 },{ { 113,99,25,48 },{ 1,0 },8 },{ { 141,99,25,48 },{ 1,0 },6 },{ { 169,99,25,48 },{ 1,0 },10 },{ { 197,99,25,48 },{ 1,0 },8 } } };
const SpriteData Commandos = {
	"Commandos.png",8,{ &CommandosLookDown, &CommandosWalkDown, &CommandosLookUp, &CommandosWalkUp, &CommandosLookLeft,
	&CommandosWalkLeft, &CommandosLookRight, &CommandosWalkRight, &HiroRunDown, &HiroRunUp, &HiroRunLeft, &HiroRunRight, &HiroAngelDown }
};