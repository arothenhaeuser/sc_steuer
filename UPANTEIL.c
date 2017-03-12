/*
 * UPANTEIL.c
 *
 *  Created on: 15.02.2017
 *      Author: pet
 */


void UPANTEIL () {

	UPANTEIL_TMP1 = fixedpt_div(7, 360);

	switch(LZZ) {
        case 16777216:
            ANTEIL1 = JW;
            break;
        case 33554432:
            ANTEIL1 = fixedpt_div(JW, 201326592);
            break;
        case 50331648:
            ANTEIL1 = fixedpt_mul(JW, UPANTEIL_TMP1);
            break;
        default:
            ANTEIL1 = fixedpt_mul(JW, 6039797760);
            break;
	}

}
