/*
 * MVSP.c
 *
 *  Created on: 15.02.2017
 *      Author: pet
 */


void MVSP (fixedpt PKV, fixedpt PKPV, fixedpt STKL) {

	fixedpt factor1 = fixedpt_div(intToFixedpt(12), intToFixedpt(100));

	if (ZRE4VP > BBGKVPV) {
		ZRE4VP = BBGKVPV;
	}

	if (PKV > 0) {
		if (STKL == 6) {
			VSP3 = 0;
		} else {
			VSP3 = fixedpt_mul(PKPV, factor1);

			if (PKV == 2) {
				VSP3 = VSP3 - fixedpt_mul(ZRE4VP, (KVSATZAG + PVSATZAG));
			}
		}

	} else {
		VSP3 = fixedpt_mul(ZRE4VP, (KVSATZAN + PVSATZAN));
	}

	VSP = VSP3 + VSP1;	//aufrunden auf volle Euro

}
