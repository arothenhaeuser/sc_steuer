/*
 * UPANTEIL.c
 *
 *  Created on: 15.02.2017
 *      Author: pet
 */


void UPANTEIL () {

	UPANTEIL_TMP1 = fixedpt_div(7, 360);

	switch(LZZ) {
        case 256:
            ANTEIL1 = JW;
            break;
        case 512:
            ANTEIL1 = fixedpt_div(JW, 3072);
            break;
        case 768:
            ANTEIL1 = fixedpt_mul(JW, UPANTEIL_TMP1);
            break;
        default:
            ANTEIL1 = fixedpt_mul(JW, 92160);
            break;
	}

}
