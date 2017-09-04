#pragma once
const SpriteData::AnimAndTimingList HyperLightDrifterLookDown = { 1,{ { { 64,32,32,32 },{ 0,0 },20 } } };
const SpriteData::AnimAndTimingList HyperLightDrifterWalkDown = { 12,{ { { 96,32,32,32 },{ 0,2 },4 },{ { 128,32,32,32 },{ 0,2 },4 },{ { 160,32,32,32 },{ 0,2 },4 },{ { 192,32,32,32 },{ 0,2 },4 },{ { 224,32,32,32 },{ 0,2 },4 },{ { 256,32,32,32 },{ 0,2 },4 },{ { 288,32,32,32 },{ 0,2 },4 },{ { 320,32,32,32 },{ 0,2 },4 },{ { 352,32,32,32 },{ 0,2 },4 },{ { 0,32,32,32 },{ 0,2 },4 },{ { 32,32,32,32 },{ 0,2 },4 },{ { 64,32,32,32 },{ 0,2 },4 } } };
const SpriteData::AnimAndTimingList HyperLightDrifterLookUp = { 1,{ { { 32,0,32,32 },{ 0,0 },20 } } };
const SpriteData::AnimAndTimingList HyperLightDrifterWalkUp = { 12,{ { { 64,0,32,32 },{ 0,-2 },4 },{ { 96,0,32,32 },{ 0,-2 },4 },{ { 128,0,32,32 },{ 0,-2 },4 },{ { 160,0,32,32 },{ 0,-2 },4 },{ { 192,0,32,32 },{ 0,-2 },4 },{ { 224,0,32,32 },{ 0,-2 },4 },{ { 256,0,32,32 },{ 0,-2 },4 },{ { 288,0,32,32 },{ 0,-2 },4 },{ { 320,0,32,32 },{ 0,-2 },4 },{ { 352,0,32,32 },{ 0,-2 },4 },{ { 0,0,32,32 },{ 0,-2 },4 },{ { 32,0,32,32 },{ 0,-2 },4 } } };
const SpriteData::AnimAndTimingList HyperLightDrifterLookLeft = { 1,{ { { 64,64,32,32 },{ 0,0 },20 } } };
const SpriteData::AnimAndTimingList HyperLightDrifterWalkLeft = { 12,{ { { 96,64,32,32 },{ -2,0 },4 },{ { 128,64,32,32 },{ -2,0 },4 },{ { 160,64,32,32 },{ -2,0 },4 },{ { 192,64,32,32 },{ -2,0 },4 },{ { 224,64,32,32 },{ -2,0 },4 },{ { 256,64,32,32 },{ -2,0 },4 },{ { 288,64,32,32 },{ -2,0 },4 },{ { 320,64,32,32 },{ -2,0 },4 },{ { 352,64,32,32 },{ -2,0 },4 },{ { 0,64,32,32 },{ -2,0 },4 },{ { 32,64,32,32 },{ -2,0 },4 },{ { 64,64,32,32 },{ -2,0 },4 } } };
const SpriteData::AnimAndTimingList HyperLightDrifterLookRight = { 1,{ { { 64,96,32,32 },{ 0,0 },20 } } };
const SpriteData::AnimAndTimingList HyperLightDrifterWalkRight = { 12,{ { { 96,96,32,32 },{ 2,0 },4 },{ { 128,96,32,32 },{ 2,0 },4 },{ { 160,96,32,32 },{ 2,0 },4 },{ { 192,96,32,32 },{ 2,0 },4 },{ { 224,96,32,32 },{ 2,0 },4 },{ { 256,96,32,32 },{ 2,0 },4 },{ { 288,96,32,32 },{ 2,0 },4 },{ { 320,96,32,32 },{ 2,0 },4 },{ { 352,96,32,32 },{ 2,0 },4 },{ { 0,96,32,32 },{ 2,0 },4 },{ { 32,96,32,32 },{ 2,0 },4 },{ { 64,96,32,32 },{ 2,0 },4 } } };

const SpriteData HyperLightDrifter = {
	"HyperLightDrifter.png",8,{ &HyperLightDrifterLookDown, &HyperLightDrifterWalkDown, &HyperLightDrifterLookUp, &HyperLightDrifterWalkUp, &HyperLightDrifterLookLeft,
	&HyperLightDrifterWalkLeft, &HyperLightDrifterLookRight, &HyperLightDrifterWalkRight }
};