/*
 * UPTAB17.c
 *
 *  Created on: 15.02.2017
 *      Author: pet
 */


void UPTAB17 () {

	UPTAB17_FAC1 = fixedpt_div(25669632, 256000);
	UPTAB17_FAC2 = X - 3524864;
	UPTAB17_FAC3 = fixedpt_div(5728256, 25600);
	UPTAB17_FAC4 = fixedpt_div(24052992, 25600);
	UPTAB17_FAC5 = fixedpt_div(10752, 25600);
	UPTAB17_FAC6 = fixedpt_div(216971264, 256000);
	UPTAB17_FAC7 = fixedpt_div(11520, 25600);
	UPTAB17_FAC8 = fixedpt_div(413811968, 2560000);

	UPTAB17_TMP1 = GFB + 256;
	if (X < UPTAB17_TMP1) {
		ST = 0;
	} else {
		if (X < 231022264320) {
			Y = fixedpt_div((X-GFB), 2560000);
			RW = fixedpt_mul(Y, UPTAB17_FAC1);
			UPTAB17_TMP1 = intToFixedpt(1400);
			RW = RW + UPTAB17_TMP1;
			ST = fixedpt_mul(RW, Y);	//auf volle Euro aufrunden
		} else {
			if (X < 13838848) {
				Y = fixedpt_div(UPTAB17_FAC2, 2560000);
				RW = fixedpt_mul(Y, UPTAB17_FAC3);
				UPTAB17_TMP3 = intToFixedpt(2397);
				RW = RW + UPTAB17_TMP3;
				RW = fixedpt_mul(RW, Y);
				ST = RW + UPTAB17_FAC4;	//auf volle Euro aufrunden
			} else {
				if (X < 65613824) {
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
