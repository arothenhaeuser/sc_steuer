/*
 * UPLSTLZZ.c
 *
 *  Created on: 15.02.2017
 *      Author: pet
 */


void UPLSTLZZ (fixedpt LZZ) {

	JW = fixedpt_mul(LSTJAHR, intToFixedpt(100));
	UPANTEIL(LZZ);
	LSTLZZ = ANTEIL1;
}
