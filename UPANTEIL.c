/*
 * UPANTEIL.c
 *
 *  Created on: 15.02.2017
 *      Author: pet
 */


void UPANTEIL (fixedpt LZZ) {

	fixedpt factor = fixedpt_div(7, 360);

	switch(LZZ) {
	case 1:
		ANTEIL1 = JW;
		break;
	case 2:
		ANTEIL1 = fixedpt_div(JW, 201326592);
		break;
	case 3:
		ANTEIL1 = fixedpt_mul(JW, factor);
		break;
	default:
		ANTEIL1 = fixedpt_mul(JW, 6039797760);
		break;
	}

}
