/*
 * UPTAB17.c
 *
 *  Created on: 15.02.2017
 *      Author: pet
 */


void UPTAB17 () {

	fixedpt factor = fixedpt_div(intToFixedpt(100727), intToFixedpt(1000));
	fixedpt factor2 = X - intToFixedpt(13769);
	fixedpt factor3 = fixedpt_div(intToFixedpt(22376), intToFixedpt(100));
	fixedpt factor4 = fixedpt_div(intToFixedpt(93957), intToFixedpt(100));
	fixedpt factor5 = fixedpt_div(intToFixedpt(42), intToFixedpt(100));
	fixedpt factor6 = fixedpt_div(intToFixedpt(847544), intToFixedpt(1000));
	fixedpt factor7 = fixedpt_div(intToFixedpt(45), intToFixedpt(100));
	fixedpt factor8 = fixedpt_div(intToFixedpt(1616453), intToFixedpt(10000));

	if (X < GFB+intToFixedpt(1)) {
		ST = 0;
	} else {
		if (X < 231022264320) {
			Y = fixedpt_div((X-GFB), 10000);
			RW = fixedpt_mul(Y, factor);
			UPTAB17_TMP1 = intToFixedpt(1400);
			RW = RW + UPTAB17_TMP1;
			ST = fixedpt_mul(RW, Y);	//auf volle Euro aufrunden
		} else {
			if (X < 906942742528) {
				UPTAB17_TMP2 = intToFixedpt(10000);
				Y = fixedpt_div(factor2, UPTAB17_TMP2);
				RW = fixedpt_mul(Y, factor3);
				UPTAB17_TMP3 = intToFixedpt(2397);
				RW = RW + UPTAB17_TMP3;
				RW = fixedpt_mul(RW, Y);
				ST = RW + factor4;	//auf volle Euro aufrunden
			} else {
				if (X < 4300067569664) {
					UPTAB17_TMP4 = fixedpt_mul(X, factor5);
					ST = UPTAB17_TMP4 - factor6;
				} else {
					UPTAB17_TMP4 = fixedpt_mul(X, factor7);
					ST = UPTAB17_TMP4 - factor8;
				}
			}
		}
	}
	ST = fixedpt_mul(ST, KZTAB);
}
