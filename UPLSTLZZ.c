/*
 * UPLSTLZZ.c
 *
 *  Created on: 15.02.2017
 *      Author: pet
 */

#include "UPANTEIL.c"

void UPLSTLZZ () {

	JW = fixedpt_mul(LSTJAHR, 1677721600);
	UPANTEIL();
	LSTLZZ = ANTEIL1;
}
