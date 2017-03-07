/*
 * MLSTJAHR.c
 *
 *  Created on: 15.02.2017
 *      Author: pet
 */

#include "UPEVP.c"
#include "UPMLST.c"

void MLSTJAHR(fixedpt KRV, fixedpt STKL, fixedpt PKV, fixedpt PKPV, fixedpt VMT, fixedpt VKAPA){

	UPEVP(KRV, STKL, PKV, PKPV);

	if (KENNVMT != 1) {
		ZVE = ZRE4 - ZTABFB - VSP;
		UPMLST(STKL);
	} else {
		ZVE = ZRE4 - ZTABFB - VSP - fixedpt_div(VMT, intToFixedpt(100)) - fixedpt_div(VKAPA, intToFixedpt(100));
		if (ZVE < 0) {
			MLSTJAHR_TMP1 = ZVE + fixedpt_div(VMT, intToFixedpt(100)) + fixedpt_div(VKAPA, intToFixedpt(100));
			ZVE = fixedpt_div(MLSTJAHR_TMP1, intToFixedpt(5));
			UPMLST(STKL);
			ST = fixedpt_mul(ST, intToFixedpt(5));
		} else {
			UPMLST(STKL);
			STOVMT = ST;
			ZVE = ZVE + fixedpt_div((VMT+VKAPA), intToFixedpt(500));
			UPMLST(STKL);
			ST = fixedpt_mul((ST-STOVMT), intToFixedpt(5)) + STOVMT;
		}
	}

}
