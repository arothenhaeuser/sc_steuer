/*
 * UPMLST.c
 *
 *  Created on: 15.02.2017
 *      Author: pet
 */


void UPMLST (fixedpt STKL) {

	if (ZVE < 1) {
		ZVE = 0;
		X = 0;
	} else {
		X = fixedpt_div(ZVE, KZTAB); //abrunde auf volle Euro
	}

	if (STKL < 5) {
		UPTAB17();
	} else {
		MST5_6();
	}
}
