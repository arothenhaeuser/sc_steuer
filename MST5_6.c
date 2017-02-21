/*
 * MST5_6.c
 *
 *  Created on: 15.02.2017
 *      Author: pet
 */

#include "UP5_6.c"

void MST5_6() {

	fixedpt factor = fixedpt_div(intToFixedpt(42), intToFixedpt(100));
	fixedpt factor2 = fixedpt_div(intToFixedpt(45), intToFixedpt(100));
	fixedpt HOCH = 0;
	fixedpt VERGL = 0;

	ZZX = X;

	if (ZZX > W2STKL5) {
		ZX = W2STKL5;
		UP5_6();
		if (ZZX > W3STKL5) {
			MST5_6_TMP1 = ST;
			ST = fixedpt_mul((W3STKL5-W2STKL5), factor);	//abrunden auf volle Euro
			MST5_6_TMP1 = MST5_6_TMP1 + ST;
			ST = fixedpt_mul((ZZX-W3STKL5), factor2);		//abrunden auf volle Euro
			ST = ST + MST5_6_TMP1;
		} else {
			MST5_6_TMP1 = ST;
			ST = fixedpt_mul((ZZX - W2STKL5), factor);
			ST = ST + MST5_6_TMP1;
		}
	} else {
		ZX = ZZX;
		UP5_6();
		if (ZZX > W1STKL5) {
			VERGL = ST;
			ZX = W1STKL5;
			UP5_6();
			MST5_6_TMP1 = fixedpt_mul((ZZX-W1STKL5), factor);
			HOCH = ST + MST5_6_TMP1;		//abrunden auf volle Euro

			if (HOCH < VERGL) {
				ST = HOCH;
			} else {
				ST = VERGL;
			}
		}
	}
}
