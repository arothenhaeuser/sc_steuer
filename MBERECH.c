/*
 * MBERECH.c
 *
 *  Created on: 14.02.2017
 *      Author: pet
 */

#include "fixedpt.h"
#include "MZTABFB.c"
#include "MLSTJAHR.c"
#include "UPLSTLZZ.c"
#include "UPVKVLZZ.c"
#include "MSOLZ.c"

void MBERECH(fixedpt STKL, fixedpt ZKF, fixedpt KRV, fixedpt PKV, fixedpt PKPV,
		fixedpt VMT, fixedpt VKAPA, fixedpt F, fixedpt LZZ, fixedpt ENTSCH, fixedpt R){

	MZTABFB(STKL, ZKF);

	VFRB = fixedpt_mul((ANP + FVB + FVBZ), intToFixedpt(100));

	MLSTJAHR(KRV, STKL, PKV, PKPV, VMT, VKAPA);

	WVFRB = fixedpt_mul((ZVE-GFB), intToFixedpt(100));

	if (WVFRB < 0) {
		WVFRB = 0;
	}

	LSTJAHR = fixedpt_mul(ST, F);

	UPLSTLZZ(LZZ);
	UPVKVLZZ(PKV, LZZ);

	if (ZKF > 0) {
		ZTABFB = ZTABFB + KFB;
		MRE4ABZ(ENTSCH);
		MLSTJAHR(KRV, STKL, PKV, PKPV, VMT, VKAPA);
		JBMG = fixedpt_mul(ST, F);
	} else {
		JBMG = LSTJAHR;
	}

	MSOLZ(R, LZZ);
}
