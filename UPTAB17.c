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
		if (X < intToFixedpt(13770)) {
			Y = fixedpt_div((X-GFB), 10000);
			RW = fixedpt_mul(Y, factor);
			RW = RW + intToFixedpt(1400);
			ST = fixedpt_mul(RW, Y);	//auf volle Euro aufrunden
		} else {
			if (X < intToFixedpt(54058)) {
				Y = fixedpt_div(factor2, intToFixedpt(10000));
				RW = fixedpt_mul(Y, factor3);
				RW = RW + intToFixedpt(2397);
				RW = fixedpt_mul(RW, Y);
				ST = RW + factor4;	//auf volle Euro aufrunden
			} else {
				if (X < intToFixedpt(256304)) {
					ST = fixedpt_mul(X, factor5) - factor6;
				} else {
					ST = fixedpt_mul(X, factor7) - factor8;
				}
			}
		}
	}
	ST = fixedpt_mul(ST, KZTAB);
}
