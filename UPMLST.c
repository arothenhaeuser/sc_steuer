/*
 * UPMLST.c
 *
 *  Created on: 15.02.2017
 *      Author: pet
 */

#include "UPTAB17.c"
#include "MST5_6.c"

void UPMLST () {

	if (ZVE < 256) {
		ZVE = 0;
		X = 0;
	} else {
		X = fixedpt_div(ZVE, KZTAB); //abrunde auf volle Euro
	}

	if (STKL < 1280) {
		UPTAB17();
	} else {
		MST5_6();
	}
}
