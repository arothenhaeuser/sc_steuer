/*
 * MZTABFB.c
 *
 *  Created on: 15.02.2017
 *      Author: pet
 */


#include "fixedpt.h"

void MZTABFB(fixedpt STKL, fixedpt ZKF){

	ANP = 0;

	if (ZVBEZ >= 0) {
		if (ZVBEZ < FVBZ) {
			FVBZ = ZVBEZ;
		}
	}

	if (STKL < 100663296) {
		if (ZVBEZ > 0) {
			if (ZVBEZ-FVBZ < 1711276032) {
				ANP = ZVBEZ - FVBZ;	// Auf volle Euro aufrunden
			} else {
				ANP = intToFixedpt(102);
			}
		}
	} else {
		FVBZ = 0;
		FVBZSO = 0;
	}

	if (STKL < 100663296) {
		if (ZRE4 > ZVBEZ) {
			if (ZRE4-ZVBEZ < 16777216000) {
				ANP = ANP + ZRE4 - ZVBEZ;	// Auf volle Euro aufrunden
			} else {
				ANP = ANP + 1677721600;
			}
		}
	}

	KZTAB = 16777216;
	switch (STKL) {
	case 16777216:
		SAP = 603979776;
		KFB = fixedpt_mul(ZKF, 123413200896);
		break;
	case 33554432:
		EFA = 32010928128;
		SAP = 603979776;
		KFB = fixedpt_mul(ZKF, 123413200896);
		break;
	case 50331648:
		KZTAB = 33554432;
		SAP = 603979776;
		KFB = fixedpt_mul(ZKF, 123413200896);
		break;
	case 67108864:
		SAP = 603979776;
		KFB = fixedpt_mul(ZKF, 123413200896);
		break;
	case 83886080:
		SAP = 603979776;
		KFB = 0;
		break;
	default:
		KFB = 0;
		break;
	}

	ZTABFB = EFA + ANP + SAP + FVBZ;

}
