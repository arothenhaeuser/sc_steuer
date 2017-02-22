/*
 * MST5_6.c
 *
 *  Created on: 15.02.2017
 *      Author: pet
 */

#include "UP5_6.c"

void MST5_6() {

	MST5_6_FAC1 = fixedpt_div(42, 100);
	MST5_6_FAC2 = fixedpt_div(45, 100);
	MST5_6_HOCH = 0;
	MST5_6_VERGL = 0;

	ZZX = X;

	if (ZZX > W2STKL5) {
		ZX = W2STKL5;
		UP5_6();
		if (ZZX > W3STKL5) {
			MST5_6_TMP1 = ST;
			ST = fixedpt_mul((W3STKL5-W2STKL5), MST5_6_FAC1);	//abrunden auf volle Euro
			MST5_6_TMP1 = MST5_6_TMP1 + ST;
			ST = fixedpt_mul((ZZX-W3STKL5), MST5_6_FAC2);		//abrunden auf volle Euro
			ST = ST + MST5_6_TMP1;
		} else {
			MST5_6_TMP1 = ST;
			ST = fixedpt_mul((ZZX - W2STKL5), MST5_6_FAC1);
			ST = ST + MST5_6_TMP1;
		}
	} else {
		ZX = ZZX;
		UP5_6();
		if (ZZX > W1STKL5) {
			MST5_6_VERGL = ST;
			ZX = W1STKL5;
			UP5_6();
			MST5_6_TMP1 = fixedpt_mul((ZZX-W1STKL5), MST5_6_FAC1);
			MST5_6_HOCH = ST + MST5_6_TMP1;		//abrunden auf volle Euro

			if (MST5_6_HOCH < MST5_6_VERGL) {
				ST = MST5_6_HOCH;
			} else {
				ST = MST5_6_VERGL;
			}
		}
	}
}
