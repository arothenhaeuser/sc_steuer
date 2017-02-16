/*
 * MVSP.c
 *
 *  Created on: 15.02.2017
 *      Author: pet
 */


void MVSP (fixedpt PKV, fixedpt PKPV, fixedpt STKL) {

	fixedpt factor1 = fixedpt_div(intToFixedpt(12), intToFixedpt(100));
	fixedpt tmp = KVSATZAG + PVSATZAG;
	fixedpt tmp2 = KVSATZAN + PVSATZAN;

	if (ZRE4VP > BBGKVPV) {
		ZRE4VP = BBGKVPV;
	}

	if (PKV > 0) {
		if (STKL == 6) {
			VSP3 = 0;
		} else {
			VSP3 = fixedpt_mul(PKPV, factor1);
			if (PKV == 2) {
				MVSP_TMP1 = fixedpt_mul(ZRE4VP, tmp);
				VSP3 = VSP3 - MVSP_TMP1;
			}
		}

	} else {
		VSP3 = fixedpt_mul(ZRE4VP, tmp2);
	}

	VSP = VSP3 + VSP1;	//aufrunden auf volle Euro

}
