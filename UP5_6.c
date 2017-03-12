/*
 * UP5_6.c
 *
 *  Created on: 15.02.2017
 *      Author: pet
 */


void UP5_6() {
	UP5_6_TMP = fixedpt_div(1280, 1024);
	UP5_6_TMP2 = fixedpt_div(768, 1024);
	UP5_6_TMP3 = fixedpt_div(3584, 25600);

	UP5_6_MIST = 0;
	UP5_6_DIFF = 0;

	X = fixedpt_mul(ZX, UP5_6_TMP);
	UPTAB17();
	ST1 = ST;
	X = fixedpt_mul(ZX, UP5_6_TMP2);
	UPTAB17();
	ST2 = ST;
	UP5_6_DIFF = fixedpt_mul((ST1 - ST2), 512);
	UP5_6_MIST = fixedpt_mul(ZX, UP5_6_TMP3);

	if (UP5_6_MIST > UP5_6_DIFF) {
		ST = UP5_6_MIST;
	} else {
		ST = UP5_6_DIFF;
	}
}
