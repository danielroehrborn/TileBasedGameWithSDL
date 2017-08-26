void DetectCollisionBetweenSprites(int H_CURRENTSPRITEOFFSET){ currentSprite = H_CURRENTSPRITEOFFSET;
	
	if (Sprites1[currentSprite].pictureID==0) return;
	
	int ff90 = Sprites1[currentSprite].Y_screen_position + 4;
	switch (Sprites1[currentSprite].Y_screen_position_delta){
		case >0: ff90 = Sprites1[currentSprite].Y_screen_position + 7;
		case -1: ff90 = Sprites1[currentSprite].Y_screen_position - 7;	 
	}
	Sprites1[currentSprite].adjusted_Y_coordinate = ff90;
	
	int ff91;
	switch (Sprites1[currentSprite].X_screen_position_delta){
		case >0: ff91 = Sprites1[currentSprite].X_screen_position + 7;
		case -1: ff91 = Sprites1[currentSprite].X_screen_position - 7;	 
	}
	Sprites1[currentSprite].adjusted_X_coordinate = ff91;
	
	Sprites1[currentSprite].directions_in_which_collisions_occurred = 0;
	
	
	int loopCnt=0;
	for(int loopCnt=0; loopCnt<16; loopCnt++){
		if (loopCnt == currentSprite //next 				  //match the current sprite?
		 || Sprites1[loopCnt].pictureID == 0 //next  		  //sprite slot unused?
		 || Sprites1[loopCnt].sprite_image_index == -1) //next//0xff: sprite is offscreen
		 continue;
		
		int tmp = Sprites1[loopCnt].Y_screen_position + 4;
		switch (Sprites1[loopCnt].Y_screen_position_delta){
			case >0: tmp = Sprites1[loopCnt].Y_screen_position + 7;
			case -1: tmp = Sprites1[loopCnt].Y_screen_position - 7;
		}		
		int distY = abs(Sprites1[currentSprite].adjusted_Y_coordinate, tmp); //absolutwert
		
		//if (Sprites1[currentSprite].adjusted_Y_coordinate > Sprites1[loopCnt].adjusted_Y_coordinate)
			//c=0b10; else c=0b01;
		
		
		if (Sprites1[currentSprite].Y_screen_position_delta == 0){
			distYadjusted = distY - 7; 
			distY = 7;
		}else{
			distYadjusted = distY - 9;
			distY = 9;	
		}
		
		if (distYadjusted < 0){
			checkXDistance();
		}else{
			if (Sprites1[loopCnt].Y_screen_position_delta == 0)
				tmp = distYadjusted - 7;
			if (Sprites1[loopCnt].Y_screen_position_delta != 0)
				tmp = distYadjusted - 9;
			if (tmp > 0) continue; //next
			else	checkXDistance();
		}
	}
}

wSpriteStateData1 Sprites1[16];

class wSpriteStateData1{	//c100
/*data for all sprites on the current map
  holds info for 16 sprites with $10 bytes each
  player sprite is always sprite 0*/
	int pictureID, 						//(c1x0) fixed, loaded at map ini)
	int movement_status 				//(c1x1) 0: uninitialized, 1: ready, 2: delayed, 3: moving
	int sprite_image_index, 			//(c1x2) changed on update, $ff if off screen, includes facing direction, progress in walking animation and a sprite-specific offset
	int Y_screen_position_delta, 		//(c1x3) -1,0 or 1; added to c1x4 on each walking animation update
	int Y_screen_position, 				//(c1x4) in pixels, always 4 pixels above grid which makes sprites appear to be in the center of a tile
	int X_screen_position_delta, 		//(c1x5) -1,0 or 1; added to c1x6 on each walking animation update
	int X_screen_position, 				//(c1x6) in pixels, snaps to grid if not currently walking
	int intra-animation-frame_counter, 	//(c1x7) counting upwards to 4 until c1x8 is incremented
	int animation_frame_counter, 		//(c1x8) increased every 4 updates, hold four states (totalling to 16 walking frames)
	int facing_direction, 				//(c1x9) 0: down, 4: up, 8: left, $c: right
	int adjusted_Y_coordinate, 			//(c1xa)
	int adjusted_X_coordinate, 			//(c1xb)
	int directions_in_which_collisions_occurred, 	//(c1xc)
	int c1xd,
	int sprite_the_collision_occurred_with_a, 		//(c1xe)
	int sprite_the_collision_occurred_with_b, 		//(c1xf)
}

void checkXDistance(){
	int tmp = Sprites1[loopCnt].X_screen_position;
	switch (Sprites1[loopCnt].X_screen_position_delta){
		case >0: tmp = Sprites1[loopCnt].X_screen_position + 7;
		case -1: tmp = Sprites1[loopCnt].X_screen_position - 7;
	}		
	int distX = abs(Sprites1[currentSprite].adjusted_X_coordinate, tmp); //absolutwert
	
	//if (Sprites1[currentSprite].adjusted_X_coordinate > Sprites1[loopCnt].adjusted_X_coordinate)
			//c=0b10; else c=0b01;
		
		
	if (Sprites1[currentSprite].X_screen_position_delta == 0){
		distXadjusted = distX - 7; 
		distX = 7;
	}else{
		distXadjusted = distX - 9;
		distX = 9;	
	}
	
	if (distXadjusted < 0){
		collision();
	}else{
		if (Sprites1[loopCnt].Y_screen_position_delta == 0)
			tmp = distYadjusted - 7;
		if (Sprites1[loopCnt].Y_screen_position_delta != 0)
			tmp = distYadjusted - 9;
		if (tmp > 0) return; //next
		else	collision();
	}
}

void collision(){
	
	//currentSprite bewegt sich in Y-Richtung
	if (distY > distX){	//distY==9, distX==7 -> bits 2-3 
		if (Sprites1[currentSprite].adjusted_Y_coordinate > Sprites1[loopCnt].adjusted_Y_coordinate)
			Sprites1[currentSprite].directions_in_which_collisions_occurred |= 0b1000;  //8 = kollision oben
		else
			Sprites1[currentSprite].directions_in_which_collisions_occurred |= 0b0100;  //4 = kollision unten
	}
	//currentSprite bewegt sich in X-Richtung
	if (distY < distX){ //distY==7, distX==9 -> bits 0-1
		if (Sprites1[currentSprite].adjusted_X_coordinate > Sprites1[loopCnt].adjusted_X_coordinate)
			Sprites1[currentSprite].directions_in_which_collisions_occurred = 0b10;  //2 = kollision links
		else
			Sprites1[currentSprite].directions_in_which_collisions_occurred = 0b01;  //1 = kollision rechts
	}
	
	Sprites1[currentSprite].sprite_the_collision_occurred_with_a |= SpriteCollisionBitTable[loopCnt*2];
	Sprites1[currentSprite].sprite_the_collision_occurred_with_b |= SpriteCollisionBitTable[(loopCnt*2)+1];
}


int SpriteCollisionBitTable[32] = {
	0x00000000,0x00000001
	0x00000000,0x00000010
	0x00000000,0x00000100
	0x00000000,0x00001000
	0x00000000,0x00010000
	0x00000000,0x00100000
	0x00000000,0x01000000
	0x00000000,0x10000000
	0x00000001,0x00000000
	0x00000010,0x00000000
	0x00000100,0x00000000
	0x00001000,0x00000000
	0x00010000,0x00000000
	0x00100000,0x00000000
	0x01000000,0x00000000
	0x10000000,0x00000000
};