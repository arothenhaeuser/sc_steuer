/*
 * UPTAB17.c
 *
 *  Created on: 15.02.2017
 *      Author: pet
 */


void UPTAB17 () {

	UPTAB17_FAC1 = fixedpt_div(1682285002752, 16777216000);
	UPTAB17_FAC2 = X - 231005487104;
	UPTAB17_FAC3 = fixedpt_div(375406985216, 1677721600);
	UPTAB17_FAC4 = fixedpt_div(1576336883712, 1677721600);
	UPTAB17_FAC5 = fixedpt_div(704643072, 1677721600);
	UPTAB17_FAC6 = fixedpt_div(14219428757504, 16777216000);
	UPTAB17_FAC7 = fixedpt_div(754974720, 1677721600);
	UPTAB17_FAC8 = fixedpt_div(27119581134848, 167772160000);

	UPTAB17_TMP1 = GFB + 16777216;
	if (X < UPTAB17_TMP1) {
		ST = 0;
	} else {
		if (X < 231022264320) {
			Y = fixedpt_div((X-GFB), 167772160000);
			RW = fixedpt_mul(Y, UPTAB17_FAC1);
			UPTAB17_TMP1 = intToFixedpt(1400);
			RW = RW + UPTAB17_TMP1;
			ST = fixedpt_mul(RW, Y);	//auf volle Euro aufrunden
		} else {
			if (X < 906942742528) {
				Y = fixedpt_div(UPTAB17_FAC2, 167772160000);
				RW = fixedpt_mul(Y, UPTAB17_FAC3);
				UPTAB17_TMP3 = intToFixedpt(2397);
				RW = RW + UPTAB17_TMP3;
				RW = fixedpt_mul(RW, Y);
				ST = RW + UPTAB17_FAC4;	//auf volle Euro aufrunden
			} else {
				if (X < 4300067569664) {
					UPTAB17_TMP4 = fixedpt_mul(X, UPTAB17_FAC5);
					ST = UPTAB17_TMP4 - UPTAB17_FAC6;
				} else {
					UPTAB17_TMP4 = fixedpt_mul(X, UPTAB17_FAC7);
					ST = UPTAB17_TMP4 - UPTAB17_FAC8;
				}
			}
		}
	}
	ST = fixedpt_mul(ST, KZTAB);
}
