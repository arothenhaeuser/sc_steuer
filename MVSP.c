/*
 * MVSP.c
 *
 *  Created on: 15.02.2017
 *      Author: pet
 */


void MVSP () {

	MVSP_TMP2 = fixedpt_div(3072, 25600);
	MVSP_TMP3 = KVSATZAG + PVSATZAG;
	MVSP_TMP4 = KVSATZAN + PVSATZAN;

	if (ZRE4VP > BBGKVPV) {
		ZRE4VP = BBGKVPV;
	}

	if (PKV > 0) {
		if (STKL == 1536) {
			VSP3 = 0;
		} else {
			VSP3 = fixedpt_mul(PKPV, MVSP_TMP2);
			if (PKV == 512) {
				MVSP_TMP1 = fixedpt_mul(ZRE4VP, MVSP_TMP3);
				VSP3 = VSP3 - MVSP_TMP1;
			}
		}

	} else {
		VSP3 = fixedpt_mul(ZRE4VP, MVSP_TMP4);
	}

	VSP = VSP3 + VSP1;	//aufrunden auf volle Euro

}
