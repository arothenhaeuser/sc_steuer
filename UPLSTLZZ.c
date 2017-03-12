/*
 * UPLSTLZZ.c
 *
 *  Created on: 15.02.2017
 *      Author: pet
 */

#include "UPANTEIL.c"

void UPLSTLZZ (fixedpt LZZ) {

	JW = fixedpt_mul(LSTJAHR, 1677721600);
	UPANTEIL(LZZ);
	LSTLZZ = ANTEIL1;
}
