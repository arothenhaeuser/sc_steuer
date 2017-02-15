/*
 * UPANTEIL.c
 *
 *  Created on: 15.02.2017
 *      Author: pet
 */


void UPANTEIL (fixedpt LZZ) {

	fixedpt factor = fixedpt_div(intToFixedpt(7), intToFixedpt(360));

	switch(LZZ) {
	case 1:
		ANTEIL1 = JW;
		break;
	case 2:
		ANTEIL1 = fixedpt_div(JW, intToFixedpt(12));
		break;
	case 3:
		ANTEIL1 = fixedpt_mul(JW, factor);
		break;
	default:
		ANTEIL1 = fixedpt_mul(JW, intToFixedpt(360));
		break;
	}

}
