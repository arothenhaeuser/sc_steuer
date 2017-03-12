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

void MBERECH(){

	MZTABFB();

	VFRB = fixedpt_mul((ANP + FVB + FVBZ), 178187);

	MLSTJAHR();

	WVFRB = fixedpt_mul((ZVE-GFB), 178187);

	if (WVFRB < 0) {
		WVFRB = 0;
	}

	LSTJAHR = fixedpt_mul(ST, F);

	UPLSTLZZ();
	UPVKVLZZ();

	if (ZKF > 0) {
		ZTABFB = ZTABFB + KFB;
		MRE4ABZ();
		MLSTJAHR();
		JBMG = fixedpt_mul(ST, F);
	} else {
		JBMG = LSTJAHR;
	}

	MSOLZ();
}
