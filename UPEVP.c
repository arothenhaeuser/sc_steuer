/*
 * UPEVP.c
 *
 *  Created on: 15.02.2017
 *      Author: pet
 */

void UPEVP(fixedpt KRV, fixedpt STKL, fixedpt PKV, fixedpt PKPV) {

	fixedpt factor1 = fixedpt_div(intToFixedpt(12), intToFixedpt(100));

	if (KRV > 1) {
		VSP1 = 0;
	} else {
		if (ZRE4VP > BBGRV) {
			ZRE4VP = BBGRV;
		}

		VSP1 = fixedpt_mul(TBSVORV, ZRE4VP);
		VSP1 = fixedpt_mul(VSP1, RVSATZAN);
	}

	VSP2 = fixedpt_mul(factor1, ZRE4VP);

	if (STKL == 3) {
		VHB = intToFixedpt(3000);
	} else {
		VHB = intToFixedpt(1900);
	}

	if (VSP2 > VHB) {
		VSP2 = VHB;
	}

	VSPN = VSP1 + VSP2;	//aufrunden auf volle Euro

	MVSP(PKV, PKPV, STKL);

	if (VSPN > VSP) {
		VSP = VSPN;
	}

}
