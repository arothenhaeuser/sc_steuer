/*
 * UP5_6.c
 *
 *  Created on: 15.02.2017
 *      Author: pet
 */


void UP5_6 () {
	fixedpt factor = fixedpt_div(intToFixedpt(5), intToFixedpt(4));
	fixedpt factor2 = fixedpt_div(intToFixedpt(3), intToFixedpt(4));
	fixedpt factor3	= fixedpt_div(intToFixedpt(14), intToFixedpt(100));

	fixedpt MIST = 0;
	fixedpt DIFF = 0;

	X = fixedpt_mul(ZX, factor);
	UPTAB17();
	ST1 = ST;
	X = fixedpt_mul(ZX, factor2);
	UPTAB17();
	ST2 = ST;
	DIFF = fixedpt_mul((ST1-ST2), intToFixedpt(2));
	MIST = fixedpt_mul(ZX, factor3);

	if (MIST > DIFF) {
		ST = MIST;
	} else {
		ST = DIFF;
	}
}
