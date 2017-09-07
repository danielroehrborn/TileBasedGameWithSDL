#pragma once
const SpriteData::AnimAndTimingList ExplosiveFlyRight = { 1,{ { { 20,196,196,179 },{ 1,0 },20 } } };
const SpriteData::AnimAndTimingList ExplosiveExplode = { 12,{ { { 216,196,196,179 },{ 0,0 },4 },{ { 412,196,196,179 },{ 0,0 },4 },
{ { 608,196,196,179 },{ 0,0 },4 },{ { 804,196,196,179 },{ 0,0 },4 },{ { 1000,196,196,179 },{ 0,0 },4 },{ { 1196,196,196,179 },{ 0,0 },4 },
{ { 1392,196,196,179 },{ 0,0 },4 },{ { 1588,196,196,179 },{ 0,0 },4 },{ { 1784,196,196,179 },{ 0,0 },4 },{ { 1980,196,196,179 },{ 0,0 },4 },
{ { 2176,196,196,179 },{ 0,0 },4 },{ { 2372,196,196,179 },{ 0,0 },8 } } };
const SpriteData Explosive = {
	4,"Explosive.png",2,{ &ExplosiveFlyRight, &ExplosiveExplode }
};