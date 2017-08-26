/* Aktion b auf Bit c in Bitfeld hl.
   b=0: reset
   b=1: set 
   b=2: read*/
   
void MissableObjectFlagAction(int action /*B*/, int bitno /*C*/){
	int bitinbyte = bitno & 0b00000111;
	int byteno = bitno / 8;  //hl = Bitfeld[byteno]
	
	switch(action){
		case 0: //reset
			Bitfeld[byteno] |= ^(1 << bitinbyte); //xor
			return Bitfeld[byteno];
		break;
		case 1: //set
			Bitfeld[byteno] |= 1 << bitinbyte;
			return Bitfeld[byteno];
		break;
		case 2: //read
			return Bitfeld[byteno] & 1 << bitinbyte;
	}
	
}

bool Bitfeld[256];