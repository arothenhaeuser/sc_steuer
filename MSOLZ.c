/*
 * MSOLZ.c
 *
 *  Created on: 15.02.2017
 *      Author: pet
 */


void MSOLZ () {

	fixedpt factor = fixedpt_div(14080, 256000);
	fixedpt factor2 = fixedpt_div(512, 25600);

	SOLZFREI = fixedpt_mul(SOLZFREI, KZTAB);

	if (JBMG > SOLZFREI) {
		SOLZJ = fixedpt_mul(JBMG, factor);	//abrunden auf Cent
		SOLZMIN = fixedpt_mul((JBMG-SOLZFREI), factor2);

		if(SOLZMIN < SOLZJ) {
			SOLZJ = SOLZMIN;
		}

		JW = fixedpt_mul(SOLZJ, 25600);

		UPANTEIL();
		SOLZLZZ = ANTEIL1;
	} else {
		SOLZLZZ = 0;
	}

	if (R > 0) {
		JW = fixedpt_mul(JBMG, 25600);
		UPANTEIL();
		BK = ANTEIL1;
	} else {
		BK = 0;
	}

}
