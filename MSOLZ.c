/*
 * MSOLZ.c
 *
 *  Created on: 15.02.2017
 *      Author: pet
 */


void MSOLZ (fixedpt R, fixedpt LZZ) {

	fixedpt factor = fixedpt_div(intToFixedpt(55), intToFixedpt(1000));
	fixedpt factor2 = fixedpt_div(intToFixedpt(20), intToFixedpt(100));

	SOLZFREI = fixedpt_mul(SOLZFREI, KZTAB);

	if (JBMG > SOLZFREI) {
		SOLZJ = fixedpt_mul(JBMG, factor);	//abrunden auf Cent
		SOLZMIN = fixedpt_mul((JBMG-SOLZFREI), factor2);

		if(SOLZMIN < SOLZJ) {
			SOLZJ = SOLZMIN;
		}

		JW = fixedpt_mul(SOLZJ, intToFixedpt(100));

		UPANTEIL(LZZ);
		SOLZLZZ = ANTEIL1;
	} else {
		SOLZLZZ = 0;
	}

	if (R > 0) {
		JW = fixedpt_mul(JBMG, intToFixedpt(100));
		UPANTEIL(LZZ);
		BK = ANTEIL1;
	} else {
		BK = 0;
	}

}
